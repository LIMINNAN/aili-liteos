/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "../generated/gui_guider.h"
typedef enum AodTimerPeriod {
    AUTOLEVEL = 10000,
    LEVELI = 15000,
    LEVELII = 30000,
    LEVELIII = 50000,
    LEVELMAX = UINT32_MAX
} AodTimerPeriod;

typedef enum AodDisplayStatus { AODHIDE, AODSHOW } AodDisplayStatus;

void CreatAodTimer(lv_obj_t *page);
void custom_init(lv_ui *ui);

uint8_t get_isAodShow(void);
void set_isAodShow(uint8_t value);

lv_timer_t *get_aodTimer(void);
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
