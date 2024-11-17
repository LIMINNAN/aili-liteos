/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "../custom/custom.h"
#include "events_init.h"
#include "gui_guider.h"
#include "lvgl.h"
#include "widgets_init.h"
#include <stdio.h>

int main_page_digital_clock_min_value = 22;
int main_page_digital_clock_hour_value = 7;
int main_page_digital_clock_sec_value = 34;
char main_page_digital_clock_meridiem[] = "PM";
void setup_scr_main_page(lv_ui *ui) {
    // Write codes main_page
    ui->main_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->main_page, 480, 480);
    lv_obj_set_scrollbar_mode(ui->main_page, LV_SCROLLBAR_MODE_OFF);

    // Write style for main_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page, &_main_page_480x480, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->main_page, lv_color_hex(0x505050), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page, 80, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_container
    ui->main_page_container = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_container, 7, 7);
    lv_obj_set_size(ui->main_page_container, 466, 466);
    lv_obj_set_scrollbar_mode(ui->main_page_container, LV_SCROLLBAR_MODE_OFF);

    // Write style for main_page_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_container, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_container, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_container, lv_color_hex(0x505050), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_container, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_container, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_imgAlbum
    ui->main_page_imgAlbum = lv_carousel_create(ui->main_page_container);
    lv_carousel_set_element_width(ui->main_page_imgAlbum, 208);
    lv_obj_set_size(ui->main_page_imgAlbum, 208, 208);
    ui->main_page_imgAlbum_view1 = lv_carousel_add_element(ui->main_page_imgAlbum, 0);
    ui->main_page_imgAlbum_view2 = lv_carousel_add_element(ui->main_page_imgAlbum, 1);
    ui->main_page_imgAlbum_view3 = lv_carousel_add_element(ui->main_page_imgAlbum, 2);
    lv_obj_set_pos(ui->main_page_imgAlbum, 243, 247);
    lv_obj_set_size(ui->main_page_imgAlbum, 208, 208);
    lv_obj_set_scrollbar_mode(ui->main_page_imgAlbum, LV_SCROLLBAR_MODE_OFF);

    // Write style for main_page_imgAlbum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_imgAlbum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_imgAlbum, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_imgAlbum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for main_page_imgAlbum, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_imgAlbum, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_imgAlbum, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for &style_main_page_imgAlbum_extra_element_items_default
    static lv_style_t style_main_page_imgAlbum_extra_element_items_default;
    ui_init_style(&style_main_page_imgAlbum_extra_element_items_default);

    lv_style_set_bg_opa(&style_main_page_imgAlbum_extra_element_items_default, 0);
    lv_style_set_outline_width(&style_main_page_imgAlbum_extra_element_items_default, 0);
    lv_style_set_border_width(&style_main_page_imgAlbum_extra_element_items_default, 0);
    lv_style_set_radius(&style_main_page_imgAlbum_extra_element_items_default, 5);
    lv_style_set_shadow_width(&style_main_page_imgAlbum_extra_element_items_default, 0);
    lv_obj_add_style(ui->main_page_imgAlbum_view3, &style_main_page_imgAlbum_extra_element_items_default,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->main_page_imgAlbum_view2, &style_main_page_imgAlbum_extra_element_items_default,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(ui->main_page_imgAlbum_view1, &style_main_page_imgAlbum_extra_element_items_default,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_FOCUSED for &style_main_page_imgAlbum_extra_element_items_focused
    static lv_style_t style_main_page_imgAlbum_extra_element_items_focused;
    ui_init_style(&style_main_page_imgAlbum_extra_element_items_focused);

    lv_style_set_bg_opa(&style_main_page_imgAlbum_extra_element_items_focused, 0);
    lv_style_set_outline_width(&style_main_page_imgAlbum_extra_element_items_focused, 0);
    lv_style_set_border_width(&style_main_page_imgAlbum_extra_element_items_focused, 0);
    lv_style_set_radius(&style_main_page_imgAlbum_extra_element_items_focused, 5);
    lv_style_set_shadow_width(&style_main_page_imgAlbum_extra_element_items_focused, 0);
    lv_obj_add_style(ui->main_page_imgAlbum_view3, &style_main_page_imgAlbum_extra_element_items_focused,
                     LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_style(ui->main_page_imgAlbum_view2, &style_main_page_imgAlbum_extra_element_items_focused,
                     LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_add_style(ui->main_page_imgAlbum_view1, &style_main_page_imgAlbum_extra_element_items_focused,
                     LV_PART_MAIN | LV_STATE_FOCUSED);

    // Write codes main_page_img1
    ui->main_page_img1 = lv_img_create(ui->main_page_imgAlbum_view1);
    lv_obj_add_flag(ui->main_page_img1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img1, &_main_page_alpha_204x204);
    lv_img_set_pivot(ui->main_page_img1, 50, 50);
    lv_img_set_angle(ui->main_page_img1, 0);
    lv_obj_set_pos(ui->main_page_img1, 1, 1);
    lv_obj_set_size(ui->main_page_img1, 204, 204);

    // Write style for main_page_img1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img1, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_img2
    ui->main_page_img2 = lv_img_create(ui->main_page_imgAlbum_view2);
    lv_obj_add_flag(ui->main_page_img2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img2, &_main_page_alpha_204x204);
    lv_img_set_pivot(ui->main_page_img2, 50, 50);
    lv_img_set_angle(ui->main_page_img2, 0);
    lv_obj_set_pos(ui->main_page_img2, 2, 2);
    lv_obj_set_size(ui->main_page_img2, 204, 204);

    // Write style for main_page_img2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img2, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_img3
    ui->main_page_img3 = lv_img_create(ui->main_page_imgAlbum_view3);
    lv_obj_add_flag(ui->main_page_img3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_img3, &_main_page_alpha_204x204);
    lv_img_set_pivot(ui->main_page_img3, 50, 50);
    lv_img_set_angle(ui->main_page_img3, 0);
    lv_obj_set_pos(ui->main_page_img3, 2, 2);
    lv_obj_set_size(ui->main_page_img3, 204, 204);

    // Write style for main_page_img3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_img3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_img3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_img3, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_img3, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_APP_6
    ui->main_page_APP_6 = lv_btn_create(ui->main_page_container);
    ui->main_page_APP_6_label = lv_label_create(ui->main_page_APP_6);
    lv_label_set_text(ui->main_page_APP_6_label, "");
    lv_label_set_long_mode(ui->main_page_APP_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->main_page_APP_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->main_page_APP_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->main_page_APP_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->main_page_APP_6, 132, 357);
    lv_obj_set_size(ui->main_page_APP_6, 92, 92);

    // Write style for main_page_APP_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_APP_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_APP_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_APP_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_APP_6, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_APP_6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_APP_6, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_APP_6, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_APP_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_APP_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page_APP_6, &_Applogo026_92x92, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page_APP_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page_APP_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_APP_6, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_APP_6, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_APP_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_APP_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_APP_5
    ui->main_page_APP_5 = lv_btn_create(ui->main_page_container);
    ui->main_page_APP_5_label = lv_label_create(ui->main_page_APP_5);
    lv_label_set_text(ui->main_page_APP_5_label, "");
    lv_label_set_long_mode(ui->main_page_APP_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->main_page_APP_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->main_page_APP_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->main_page_APP_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->main_page_APP_5, 16, 357);
    lv_obj_set_size(ui->main_page_APP_5, 92, 92);

    // Write style for main_page_APP_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_APP_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_APP_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_APP_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_APP_5, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_APP_5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_APP_5, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_APP_5, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_APP_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_APP_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page_APP_5, &_Applogo018_92x92, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page_APP_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page_APP_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_APP_5, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_APP_5, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_APP_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_APP_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_APP_4
    ui->main_page_APP_4 = lv_btn_create(ui->main_page_container);
    ui->main_page_APP_4_label = lv_label_create(ui->main_page_APP_4);
    lv_label_set_text(ui->main_page_APP_4_label, "");
    lv_label_set_long_mode(ui->main_page_APP_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->main_page_APP_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->main_page_APP_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->main_page_APP_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->main_page_APP_4, 358, 134);
    lv_obj_set_size(ui->main_page_APP_4, 92, 92);

    // Write style for main_page_APP_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_APP_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_APP_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_APP_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_APP_4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_APP_4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_APP_4, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_APP_4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_APP_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_APP_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page_APP_4, &_Applogo013_92x92, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page_APP_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page_APP_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_APP_4, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_APP_4, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_APP_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_APP_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_APP_3
    ui->main_page_APP_3 = lv_btn_create(ui->main_page_container);
    ui->main_page_APP_3_label = lv_label_create(ui->main_page_APP_3);
    lv_label_set_text(ui->main_page_APP_3_label, "");
    lv_label_set_long_mode(ui->main_page_APP_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->main_page_APP_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->main_page_APP_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->main_page_APP_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->main_page_APP_3, 241, 134);
    lv_obj_set_size(ui->main_page_APP_3, 92, 92);

    // Write style for main_page_APP_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_APP_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_APP_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_APP_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_APP_3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_APP_3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_APP_3, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_APP_3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_APP_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_APP_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page_APP_3, &_Applogo002_92x92, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page_APP_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page_APP_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_APP_3, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_APP_3, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_APP_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_APP_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_APP_2
    ui->main_page_APP_2 = lv_btn_create(ui->main_page_container);
    ui->main_page_APP_2_label = lv_label_create(ui->main_page_APP_2);
    lv_label_set_text(ui->main_page_APP_2_label, "");
    lv_label_set_long_mode(ui->main_page_APP_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->main_page_APP_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->main_page_APP_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->main_page_APP_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->main_page_APP_2, 358, 18);
    lv_obj_set_size(ui->main_page_APP_2, 92, 92);

    // Write style for main_page_APP_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_APP_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_APP_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_APP_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_APP_2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_APP_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_APP_2, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_APP_2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_APP_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_APP_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page_APP_2, &_Applogo001_92x92, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page_APP_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page_APP_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_APP_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_APP_2, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_APP_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_APP_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_APP_1
    ui->main_page_APP_1 = lv_btn_create(ui->main_page_container);
    ui->main_page_APP_1_label = lv_label_create(ui->main_page_APP_1);
    lv_label_set_text(ui->main_page_APP_1_label, "");
    lv_label_set_long_mode(ui->main_page_APP_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->main_page_APP_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->main_page_APP_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->main_page_APP_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->main_page_APP_1, 242, 18);
    lv_obj_set_size(ui->main_page_APP_1, 92, 92);

    // Write style for main_page_APP_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_page_APP_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->main_page_APP_1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_APP_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_APP_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_APP_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_APP_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_APP_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_APP_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_APP_1, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_APP_1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_APP_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_APP_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->main_page_APP_1, &_Applogo005_92x92, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->main_page_APP_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->main_page_APP_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_APP_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_APP_1, &lv_customer_font_MI_LanTing_Regular_26,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_APP_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_APP_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_digital_clock
    static bool main_page_digital_clock_timer_enabled = false;
    ui->main_page_digital_clock = lv_dclock_create(ui->main_page_container, "7:22 PM");
    if (!main_page_digital_clock_timer_enabled) {
        lv_timer_create(main_page_digital_clock_timer, 1000, NULL);
        main_page_digital_clock_timer_enabled = true;
    }
    lv_obj_set_pos(ui->main_page_digital_clock, 41, 19);
    lv_obj_set_size(ui->main_page_digital_clock, 184, 92);

    // Write style for main_page_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->main_page_digital_clock, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_page_digital_clock, lv_color_hex(0x191717), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_page_digital_clock, &lv_customer_font_Acme_Regular_22,
                               LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_page_digital_clock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_page_digital_clock, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_page_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_digital_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_digital_clock, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_digital_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_digital_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_digital_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_digital_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_statusBar
    ui->main_page_statusBar = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_statusBar, -4, -2);
    lv_obj_set_size(ui->main_page_statusBar, 488, 32);
    lv_obj_set_scrollbar_mode(ui->main_page_statusBar, LV_SCROLLBAR_MODE_OFF);

    // Write style for main_page_statusBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_statusBar, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_statusBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_statusBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_statusBar, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_statusBar, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->main_page_statusBar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->main_page_statusBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->main_page_statusBar, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->main_page_statusBar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_battery
    ui->main_page_battery = lv_img_create(ui->main_page_statusBar);
    lv_obj_add_flag(ui->main_page_battery, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_battery, &_wifi_alpha_32x32);
    lv_img_set_pivot(ui->main_page_battery, 50, 50);
    lv_img_set_angle(ui->main_page_battery, 0);
    lv_obj_set_pos(ui->main_page_battery, 429, -1);
    lv_obj_set_size(ui->main_page_battery, 32, 32);

    // Write style for main_page_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_battery, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_blicon
    ui->main_page_blicon = lv_img_create(ui->main_page_statusBar);
    lv_obj_add_flag(ui->main_page_blicon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_page_blicon, &_bluetooth_connected_alpha_32x32);
    lv_img_set_pivot(ui->main_page_blicon, 50, 50);
    lv_img_set_angle(ui->main_page_blicon, 0);
    lv_obj_set_pos(ui->main_page_blicon, 387, 0);
    lv_obj_set_size(ui->main_page_blicon, 32, 32);

    // Write style for main_page_blicon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_blicon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_blicon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_blicon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_blicon, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_fastStting
    ui->main_page_fastStting = lv_obj_create(ui->main_page);
    lv_obj_set_pos(ui->main_page_fastStting, 0, -480);
    lv_obj_set_size(ui->main_page_fastStting, 480, 480);
    lv_obj_set_scrollbar_mode(ui->main_page_fastStting, LV_SCROLLBAR_MODE_OFF);

    // Write style for main_page_fastStting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_page_fastStting, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_page_fastStting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_page_fastStting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_page_fastStting, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_fastStting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_page_fastStting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_page_fastStting, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_page_fastStting, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_page_fastStting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_page_fastStting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_page_fastStting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_page_fastStting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_page_fastStting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes main_page_snapMainimg
    ui->main_page_snapMainimg = lv_img_create(ui->main_page_fastStting);
    lv_obj_add_flag(ui->main_page_snapMainimg, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->main_page_snapMainimg, 50, 50);
    lv_img_set_angle(ui->main_page_snapMainimg, 0);
    lv_obj_set_pos(ui->main_page_snapMainimg, 0, 0);
    lv_obj_set_size(ui->main_page_snapMainimg, 480, 480);

    // Write style for main_page_snapMainimg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_page_snapMainimg, 41, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->main_page_snapMainimg, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_page_snapMainimg, 129, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_page_snapMainimg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_page_snapMainimg, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of main_page.

    // Update current screen layout.
    lv_obj_update_layout(ui->main_page);

    // Init events for screen.
    events_init_main_page(ui);
}
