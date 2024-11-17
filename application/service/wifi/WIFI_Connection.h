#include <lwip/tcpip.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>
#include "bl_fw_api.h"
#include "wifi_mgmr_ext.h"
#include "wifi_mgmr.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "bl616_glb.h"
#include "board.h"
#include "log.h"
SemaphoreHandle_t wifiConnectionSemaphore;
extern xQueueHandle queue;

// 栈内存深度
#define WIFI_STACK_SIZE (1536)
// 任务优先级
#define TASK_PRIORITY_FW (16)

// wifi 连接结构体
typedef struct
{
    char ssid[50];
    char password[50];
} WiFiTaskParameters;
/****************************************************************************
 * Private Data
 ****************************************************************************/

static TaskHandle_t wifi_fw_task;

// wifi 链接参数，国家代码
static wifi_conf_t conf =
    {
        .country_code = "CN",
};

static uint32_t sta_ConnectStatus = 0;

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Functions
 ****************************************************************************/

/**
 * @brief wifi框架调度
 *
 * @return int
 */
int wifi_start_firmware_task(void);

/**
 * @brief WIFI事件处理
 *
 * @param code
 */
void wifi_event_handler(uint32_t code);

/**
 * @brief 连接wifi
 *
 * @param ssid wifi 名称
 * @param passwd wifi 密码
 * @return uint8_t
 */
uint8_t wifi_connect(char *ssid, char *passwd);

/**
 * @brief wifi 实际连接
 *
 * @param arg
 */
void wifi_connection(void *arg);
