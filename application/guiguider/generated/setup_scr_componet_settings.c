/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "custom.h"
#include "events_init.h"
#include "gui_guider.h"
#include "lvgl.h"
#include "widgets_init.h"
#include <stdio.h>
static void show_border(lv_obj_t *obj) {
    lv_obj_set_style_border_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
}
void setup_scr_componet_settings(lv_ui *ui) {
    // Write codes componet_settings
    ui->componet_settings = lv_obj_create(NULL);
    lv_obj_set_size(ui->componet_settings, 480, 480);
    lv_obj_set_scrollbar_mode(ui->componet_settings, LV_SCROLLBAR_MODE_OFF);

    // Write style for componet_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->componet_settings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->componet_settings, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->componet_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes componet_settings_container
    ui->componet_settings_container = lv_obj_create(ui->componet_settings);
    lv_obj_set_pos(ui->componet_settings_container, 0, 0);
    lv_obj_set_size(ui->componet_settings_container, 480, 480);
    lv_obj_set_scrollbar_mode(ui->componet_settings_container, LV_SCROLLBAR_MODE_OFF);

    // Write style for componet_settings_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->componet_settings_container, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->componet_settings_container, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->componet_settings_container, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->componet_settings_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes componet_settings_setting_list
    ui->componet_settings_setting_list = lv_menu_create(ui->componet_settings_container);

    // Create sidebar page for menu componet_settings_setting_list
    ui->componet_settings_setting_list_sidebar_page =
        lv_menu_page_create(ui->componet_settings_setting_list, "系统设置");
    lv_menu_set_sidebar_page(ui->componet_settings_setting_list, ui->componet_settings_setting_list_sidebar_page);
    lv_obj_set_scrollbar_mode(ui->componet_settings_setting_list_sidebar_page, LV_SCROLLBAR_MODE_OFF);

    // Create subpage for componet_settings_setting_list
    ui->componet_settings_setting_list_subpage_1 = lv_menu_page_create(ui->componet_settings_setting_list, NULL);
    ui->componet_settings_setting_list_cont_1 = lv_menu_cont_create(ui->componet_settings_setting_list_sidebar_page);
    ui->componet_settings_setting_list_label_1 = lv_label_create(ui->componet_settings_setting_list_cont_1);
    lv_label_set_text(ui->componet_settings_setting_list_label_1, "蓝牙");
    lv_obj_set_style_text_font(ui->componet_settings_setting_list_label_1, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui->componet_settings_setting_list_label_1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->componet_settings_setting_list_subpage_1, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->componet_settings_setting_list, ui->componet_settings_setting_list_cont_1,
                                ui->componet_settings_setting_list_subpage_1);

    // Create subpage for componet_settings_setting_list
    ui->componet_settings_setting_list_subpage_2 = lv_menu_page_create(ui->componet_settings_setting_list, NULL);
    ui->componet_settings_setting_list_cont_2 = lv_menu_cont_create(ui->componet_settings_setting_list_sidebar_page);
    ui->componet_settings_setting_list_label_2 = lv_label_create(ui->componet_settings_setting_list_cont_2);
    lv_label_set_text(ui->componet_settings_setting_list_label_2, "WiFi");
    lv_obj_set_style_text_font(ui->componet_settings_setting_list_label_2, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui->componet_settings_setting_list_label_2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->componet_settings_setting_list_subpage_2, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->componet_settings_setting_list, ui->componet_settings_setting_list_cont_2,
                                ui->componet_settings_setting_list_subpage_2);

    // Create subpage for componet_settings_setting_list
    ui->componet_settings_setting_list_subpage_3 = lv_menu_page_create(ui->componet_settings_setting_list, NULL);
    ui->componet_settings_setting_list_cont_3 = lv_menu_cont_create(ui->componet_settings_setting_list_sidebar_page);
    ui->componet_settings_setting_list_label_3 = lv_label_create(ui->componet_settings_setting_list_cont_3);
    lv_label_set_text(ui->componet_settings_setting_list_label_3, "显示和亮度");
    lv_obj_set_style_text_font(ui->componet_settings_setting_list_label_3, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui->componet_settings_setting_list_label_3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->componet_settings_setting_list_subpage_3, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->componet_settings_setting_list, ui->componet_settings_setting_list_cont_3,
                                ui->componet_settings_setting_list_subpage_3);

    // Create subpage for componet_settings_setting_list
    ui->componet_settings_setting_list_subpage_4 = lv_menu_page_create(ui->componet_settings_setting_list, NULL);
    ui->componet_settings_setting_list_cont_4 = lv_menu_cont_create(ui->componet_settings_setting_list_sidebar_page);
    ui->componet_settings_setting_list_label_4 = lv_label_create(ui->componet_settings_setting_list_cont_4);
    lv_label_set_text(ui->componet_settings_setting_list_label_4, "声音与振动");
    lv_obj_set_style_text_font(ui->componet_settings_setting_list_label_4, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui->componet_settings_setting_list_label_4, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->componet_settings_setting_list_subpage_4, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->componet_settings_setting_list, ui->componet_settings_setting_list_cont_4,
                                ui->componet_settings_setting_list_subpage_4);
    lv_event_send(ui->componet_settings_setting_list_cont_1, LV_EVENT_CLICKED, NULL);
    lv_obj_set_pos(ui->componet_settings_setting_list, 0, 0);
    lv_obj_set_size(ui->componet_settings_setting_list, 480, 480);
    lv_obj_set_scrollbar_mode(ui->componet_settings_setting_list, LV_SCROLLBAR_MODE_OFF);

    // 列表整体颜色
    lv_obj_set_style_bg_opa(ui->componet_settings_setting_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->componet_settings_setting_list, lv_color_hex(0xffffff),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_dither_mode(ui->componet_settings_setting_list, LV_DITHER_ORDERED,
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->componet_settings_setting_list, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->componet_settings_setting_list, lv_color_hex(0xffffff),
                                   LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->componet_settings_setting_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->componet_settings_setting_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->componet_settings_setting_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->componet_settings_setting_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 列表标题颜色
    static lv_style_t style_componet_settings_setting_list_extra_main_title_main_default;
    ui_init_style(&style_componet_settings_setting_list_extra_main_title_main_default);

    lv_style_set_text_color(&style_componet_settings_setting_list_extra_main_title_main_default,
                            lv_color_hex(0x000000));
    lv_style_set_text_font(&style_componet_settings_setting_list_extra_main_title_main_default,
                           &lv_customer_font_MI_LanTing_Regular_26);
    lv_style_set_text_opa(&style_componet_settings_setting_list_extra_main_title_main_default, 255);
    lv_style_set_text_align(&style_componet_settings_setting_list_extra_main_title_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_top(&style_componet_settings_setting_list_extra_main_title_main_default, 5);
    lv_style_set_pad_bottom(&style_componet_settings_setting_list_extra_main_title_main_default, 5);

    lv_menu_t *componet_settings_setting_list_menu = (lv_menu_t *)ui->componet_settings_setting_list;
    lv_obj_t *componet_settings_setting_list_title = componet_settings_setting_list_menu->sidebar_header_title;
    lv_obj_set_size(componet_settings_setting_list_title, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(lv_menu_get_sidebar_header(ui->componet_settings_setting_list),
                     &style_componet_settings_setting_list_extra_main_title_main_default,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of componet_settings.
    
    // Update current screen layout.
    lv_obj_update_layout(ui->componet_settings);
}
