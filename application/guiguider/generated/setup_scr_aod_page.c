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

int aod_page_analog_clock_hour_value = 10;
int aod_page_analog_clock_min_value = 10;
int aod_page_analog_clock_sec_value = 15;
void setup_scr_aod_page(lv_ui *ui) {
    // Write codes aod_page
    ui->aod_page = lv_obj_create(NULL);
    lv_obj_set_size(ui->aod_page, 480, 480);
    lv_obj_set_scrollbar_mode(ui->aod_page, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->aod_page, LV_OBJ_FLAG_CLICKABLE);

    // Write style for aod_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->aod_page, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->aod_page, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->aod_page, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes aod_page_container
    ui->aod_page_container = lv_obj_create(ui->aod_page);
    lv_obj_set_pos(ui->aod_page_container, 52, 52);
    lv_obj_set_size(ui->aod_page_container, 376, 376);
    lv_obj_set_scrollbar_mode(ui->aod_page_container, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->aod_page_container, LV_OBJ_FLAG_CLICKABLE);

    // Write style for aod_page_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->aod_page_container, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->aod_page_container, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->aod_page_container, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->aod_page_container, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->aod_page_container, 366, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->aod_page_container, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->aod_page_container, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->aod_page_container, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->aod_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->aod_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->aod_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->aod_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->aod_page_container, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes aod_page_analog_clock
    static bool aod_page_analog_clock_timer_enabled = false;
    ui->aod_page_analog_clock = lv_analogclock_create(ui->aod_page_container);
    lv_analogclock_hide_digits(ui->aod_page_analog_clock, false);
    lv_analogclock_hide_point(ui->aod_page_analog_clock, true);
    lv_analogclock_set_major_ticks(ui->aod_page_analog_clock, 2, 10, lv_color_hex(0xc0c0c0), 18);
    lv_analogclock_set_ticks(ui->aod_page_analog_clock, 2, 5, lv_color_hex(0x808080));
    lv_analogclock_set_hour_needle_img(ui->aod_page_analog_clock, &_hour_needle_white_alpha_70x8, 3, 4);
    lv_analogclock_set_min_needle_img(ui->aod_page_analog_clock, &_min_needle_white_alpha_105x8, 2, 4);
    lv_analogclock_set_sec_needle_line(ui->aod_page_analog_clock, 2, lv_color_hex(0xFF4500), -40);
    lv_analogclock_set_time(ui->aod_page_analog_clock, aod_page_analog_clock_hour_value,
                            aod_page_analog_clock_min_value, aod_page_analog_clock_sec_value);
    // create timer
    if (!aod_page_analog_clock_timer_enabled) {
        lv_timer_create(aod_page_analog_clock_timer, 1000, NULL);
        aod_page_analog_clock_timer_enabled = true;
    }
    lv_obj_set_pos(ui->aod_page_analog_clock, 3, 3);
    lv_obj_set_size(ui->aod_page_analog_clock, 366, 366);

    // Write style for aod_page_analog_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->aod_page_analog_clock, 67, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->aod_page_analog_clock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->aod_page_analog_clock, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->aod_page_analog_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->aod_page_analog_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for aod_page_analog_clock, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->aod_page_analog_clock, lv_color_hex(0x4f4f4f), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->aod_page_analog_clock, &lv_customer_font_Acme_Regular_22,
                               LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->aod_page_analog_clock, 255, LV_PART_TICKS | LV_STATE_DEFAULT);

    // Write style for aod_page_analog_clock, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->aod_page_analog_clock, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->aod_page_analog_clock, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->aod_page_analog_clock, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // The custom code of aod_page.

    // Update current screen layout.
    lv_obj_update_layout(ui->aod_page);

    // Init events for screen.
    events_init_aod_page(ui);
}
