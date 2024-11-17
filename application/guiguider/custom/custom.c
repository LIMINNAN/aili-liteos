/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include "custom.h"
#include "lv_port_disp.h"
#include "lvgl.h"
#include <stdio.h>
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static uint8_t isAodShow = AODHIDE;
static lv_timer_t *g_aodTimer = NULL;
static AodTimerPeriod aodTimerPeriod = AUTOLEVEL;

AodTimerPeriod get_aodTimerPeriod(void) { return aodTimerPeriod; }
void set_aodTimerPeriod(AodTimerPeriod value) { aodTimerPeriod = value; }

lv_timer_t *get_aodTimer(void) { return g_aodTimer; }

uint8_t get_isAodShow(void) { return isAodShow; }
void set_isAodShow(uint8_t value) {
    if (value == AODHIDE || value == AODSHOW) {
        isAodShow = value;
    } else {
        LV_LOG_WARN("Invalid value for isAodShow, must be AODHIDE (0) or AODSHOW (1)");
    }
}

static void ModifiedObjFlag(lv_ui *ui) {
    if (ui == NULL)
        return;

    if (ui->main_page != NULL) {
        lv_obj_clear_flag(ui->main_page, LV_OBJ_FLAG_ALL);
        lv_obj_clear_flag(ui->main_page_battery, LV_OBJ_FLAG_ALL);
        lv_obj_clear_flag(ui->main_page_statusBar, LV_OBJ_FLAG_ALL);
        lv_obj_clear_flag(ui->main_page_blicon, LV_OBJ_FLAG_ALL);
        lv_obj_clear_flag(ui->main_page_snapMainimg, LV_OBJ_FLAG_ALL);
        lv_obj_clear_flag(ui->main_page_fastStting, LV_OBJ_FLAG_ALL);
    }
    if (ui->componet_settings != NULL && ui->componet_settings_setting_list != NULL) {
        lv_obj_clear_flag(ui->componet_settings_setting_list, LV_OBJ_FLAG_ALL);
    }
}

bool *GetFormerScreenDel(lv_obj_t *formerScreen) {
    if (formerScreen == NULL) {
        LV_LOG_WARN("formerScreen ptr is NULL");
        return NULL;
    }
    if (formerScreen == guider_ui.main_page) {
        LV_LOG_USER("formerScreen is guider_ui.main_page");
        return &guider_ui.main_page_del;
    }
    LV_LOG_USER("formerScreen is not main_page");
    return NULL;
}

static void timer_aod_page_handler(lv_timer_t *e) {
    if (e == NULL) {
        LV_LOG_USER("aodTimer is null");
        return;
    }
    if (!get_isAodShow()) { // AOD隐藏
        LV_LOG_USER("Aod hiding");
        lv_timer_reset(get_aodTimer());
        lv_timer_resume(get_aodTimer());
    } else { // AOD显示
        LV_LOG_USER("Aod showing");
        lv_timer_pause(get_aodTimer());
        lv_timer_reset(get_aodTimer());
    }
    bool *FormerScreenDel = GetFormerScreenDel((lv_obj_t *)lv_event_get_user_data(e));
    if (FormerScreenDel == NULL) {
        LV_LOG_USER("FormerScreenDel is NULL!");
        return;
    }
    ui_load_scr_animation(&guider_ui, &guider_ui.aod_page, guider_ui.aod_page_del, FormerScreenDel, setup_scr_aod_page,
                          LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false, false);
    set_isAodShow(AODSHOW);
    LV_LOG_USER("Aod showing");
    lv_timer_pause(get_aodTimer());
    lv_timer_reset(get_aodTimer());
}

void CreatAodTimer(lv_obj_t *page) {
    if (page == NULL) {
        LV_LOG_USER("aodFormerpage is NULL");
        return;
    }
    if (get_aodTimer() == NULL) {
        AodTimerPeriod period = get_aodTimerPeriod();
        if (period < LEVELMAX) {
            g_aodTimer = lv_timer_create(timer_aod_page_handler, period, page);
            LV_LOG_USER("CreatAodTimer success");
        } else {
            LV_LOG_USER("Never Show Aod due to LEVELMAX");
        }
    }
    if (get_isAodShow() == AODHIDE) {
        lv_timer_reset(get_aodTimer());
        lv_timer_resume(get_aodTimer());
    } else {
        lv_timer_pause(get_aodTimer());
        lv_timer_reset(get_aodTimer());
    }
}

void custom_init(lv_ui *ui) {
    if (ui == NULL) {
        LV_LOG_WARN("UI structure is NULL in custom_init");
        return;
    }
    CreatAodTimer(ui->main_page);
    ModifiedObjFlag(ui);
}
