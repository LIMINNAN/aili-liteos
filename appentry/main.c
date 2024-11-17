#include "board.h"
#include "los_task.h"
#include "gui_guider.h"
#include "events_init.h"
#include "los_tick.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

lv_ui guider_ui;

void lv_log_print_g_cb(const char *buf)
{
    printf("[lvgl]%s", buf);
}

static void gui_service(void)
{
    lv_log_register_print_cb(lv_log_print_g_cb);
    lv_demo_benchmark();
    // setup_ui(&guider_ui);
    // events_init(&guider_ui);
    while (1) {
        lv_task_handler();
        LOS_MDelay(1);
    }
}

static LosTaskCB g_gui_service_task_cb;

int main(void)
{
    board_init();

    LOS_KernelInit();

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    TSK_INIT_PARAM_S g_gui_service_task_param = {
        .pfnTaskEntry = (TSK_ENTRY_FUNC)gui_service,
        .usTaskPrio = 1,
        .uwStackSize = 0x2000,
        .pcName = "gui_service",
    };

    UINT32 ret = LOS_TaskCreate(&g_gui_service_task_cb, &g_gui_service_task_param);
    if (ret != LOS_OK) {
        printf("Failed to create gui_service task: %d\n", ret);
        return -1;
    }

    LOS_Start();

    for (;;)
        ;
}
