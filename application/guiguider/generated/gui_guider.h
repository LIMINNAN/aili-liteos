/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct {

    lv_obj_t *main_page;
    bool main_page_del;
    lv_obj_t *main_page_container;
    lv_obj_t *main_page_imgAlbum;
    lv_obj_t *main_page_imgAlbum_view1;
    lv_obj_t *main_page_imgAlbum_view2;
    lv_obj_t *main_page_imgAlbum_view3;
    lv_obj_t *main_page_img1;
    lv_obj_t *main_page_img2;
    lv_obj_t *main_page_img3;
    lv_obj_t *main_page_APP_6;
    lv_obj_t *main_page_APP_6_label;
    lv_obj_t *main_page_APP_5;
    lv_obj_t *main_page_APP_5_label;
    lv_obj_t *main_page_APP_4;
    lv_obj_t *main_page_APP_4_label;
    lv_obj_t *main_page_APP_3;
    lv_obj_t *main_page_APP_3_label;
    lv_obj_t *main_page_APP_2;
    lv_obj_t *main_page_APP_2_label;
    lv_obj_t *main_page_APP_1;
    lv_obj_t *main_page_APP_1_label;
    lv_obj_t *main_page_digital_clock;
    lv_obj_t *main_page_statusBar;
    lv_obj_t *main_page_battery;
    lv_obj_t *main_page_blicon;
    lv_obj_t *main_page_fastStting;
    lv_obj_t *main_page_snapMainimg;
    lv_obj_t *aod_page;
    bool aod_page_del;
    lv_obj_t *aod_page_container;
    lv_obj_t *aod_page_analog_clock;
    lv_obj_t *componet_settings;
    bool componet_settings_del;
    lv_obj_t *componet_settings_container;
    lv_obj_t *componet_settings_setting_list;
    lv_obj_t *componet_settings_setting_list_sidebar_page;
    lv_obj_t *componet_settings_setting_list_subpage_1;
    lv_obj_t *componet_settings_setting_list_cont_1;
    lv_obj_t *componet_settings_setting_list_label_1;
    lv_obj_t *componet_settings_setting_list_subpage_2;
    lv_obj_t *componet_settings_setting_list_cont_2;
    lv_obj_t *componet_settings_setting_list_label_2;
    lv_obj_t *componet_settings_setting_list_subpage_3;
    lv_obj_t *componet_settings_setting_list_cont_3;
    lv_obj_t *componet_settings_setting_list_label_3;
    lv_obj_t *componet_settings_setting_list_subpage_4;
    lv_obj_t *componet_settings_setting_list_cont_4;
    lv_obj_t *componet_settings_setting_list_label_4;
} lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui *ui);

void ui_init_style(lv_style_t *style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t **new_scr, bool new_scr_del, bool *old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void *var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value,
                  lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                  uint32_t playback_delay, lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb,
                  lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

extern lv_ui guider_ui;

void setup_scr_main_page(lv_ui *ui);
void setup_scr_aod_page(lv_ui *ui);
void setup_scr_componet_settings(lv_ui *ui);

LV_IMG_DECLARE(_main_page_480x480);
LV_IMG_DECLARE(_main_page_alpha_204x204);
LV_IMG_DECLARE(_main_page_alpha_204x204);
LV_IMG_DECLARE(_main_page_alpha_204x204);

LV_IMG_DECLARE(_Applogo026_92x92);

LV_IMG_DECLARE(_Applogo018_92x92);

LV_IMG_DECLARE(_Applogo013_92x92);

LV_IMG_DECLARE(_Applogo002_92x92);

LV_IMG_DECLARE(_Applogo001_92x92);

LV_IMG_DECLARE(_Applogo005_92x92);
LV_IMG_DECLARE(_wifi_alpha_32x32);
LV_IMG_DECLARE(_bluetooth_connected_alpha_32x32);
LV_IMG_DECLARE(_hour_needle_white_alpha_70x8);
LV_IMG_DECLARE(_min_needle_white_alpha_105x8);
LV_IMG_DECLARE(_second_needle_2_alpha_130x5);

LV_FONT_DECLARE(lv_customer_font_MI_LanTing_Regular_26)
LV_FONT_DECLARE(lv_customer_font_Acme_Regular_22)
#ifdef __cplusplus
}
#endif
#endif
