/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "events_init.h"
#include "custom.h"
#include <stdio.h>

#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif
// 申明全局变量来存储快照图像
static lv_img_dsc_t *snapshot_img_dsc = NULL;
static void main_page_event_handler(lv_event_t *e) {
    // lv_timer_reset(get_g_aodTimer());
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE: {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        LV_LOG_USER("LV_EVENT_GESTURE");
        switch (dir) {
        case LV_DIR_BOTTOM: {
            if (snapshot_img_dsc == NULL) {
                LV_LOG_USER("Snapshot image descriptor is NULL");
                // 为主页面创建快照，生成图像描述符
                snapshot_img_dsc = lv_snapshot_take(guider_ui.main_page, LV_IMG_CF_TRUE_COLOR);

                lv_indev_wait_release(lv_indev_get_act());
                ui_animation(guider_ui.main_page_fastStting, 150, 10, lv_obj_get_y(guider_ui.main_page_fastStting), 0,
                             &lv_anim_path_ease_in_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, 0, 0, 0);
                // 动画完成之后将主页面模糊化
                if (snapshot_img_dsc) {
                    lv_img_set_src(guider_ui.main_page_snapMainimg, snapshot_img_dsc); // 将快照设置为 img 对象的源
                    lv_obj_set_style_bg_img_recolor(guider_ui.main_page, lv_color_hex(0x505050),
                                                    LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            } else {
                /* doing nothing */
                LV_LOG_USER("Snapshot image descriptor is not NULL");
                // lv_snapshot_free(snapshot_img_dsc);
                // snapshot_img_dsc = NULL;
            }
            break;
        }
        case LV_DIR_TOP: {

            lv_indev_wait_release(lv_indev_get_act());
            ui_animation(guider_ui.main_page_fastStting, 150, 10, lv_obj_get_y(guider_ui.main_page_fastStting), -480,
                         &lv_anim_path_ease_in_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, 0, 0, 0);
            // 动画完成之后将主页面清晰化
            if (snapshot_img_dsc) {
                lv_snapshot_free(snapshot_img_dsc);
                snapshot_img_dsc = NULL;
                // lv_img_set_src(guider_ui.main_page_snapMainimg, snapshot_img_dsc);
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_main_page(lv_ui *ui) {
    lv_obj_add_event_cb(guider_ui.main_page, main_page_event_handler, LV_EVENT_ALL, ui);
}

static void aod_page_analog_clock_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED: {
        ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.aod_page_del,
                              setup_scr_main_page, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false, false);
        set_isAodShow(AODHIDE);
        CreatAodTimer(guider_ui.main_page);
        break;
    }
    default:
        break;
    }
}

void events_init_aod_page(lv_ui *ui) {
    lv_obj_add_event_cb(ui->aod_page_analog_clock, aod_page_analog_clock_event_handler, LV_EVENT_CLICKED, ui);
}

void events_init(lv_ui *ui) {}
