#if 0
#include "WIFI_Connection.h"

int wifi_start_firmware_task(void) {
    LOG_I("Starting wifi ...\r\n");

    /* enable wifi clock */

    GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_IP_WIFI_PHY | GLB_AHB_CLOCK_IP_WIFI_MAC_PHY | GLB_AHB_CLOCK_IP_WIFI_PLATFORM);
    GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_WIFI);

    /* set ble controller EM Size */

    GLB_Set_EM_Sel(GLB_WRAM160KB_EM0KB);

    if (0 != rfparam_init(0, NULL, 0)) {
        LOG_I("PHY RF init failed!\r\n");
        return 0;
    }

    LOG_I("PHY RF init success!\r\n");

    /* Enable wifi irq */

    extern void interrupt0_handler(void);
    bflb_irq_attach(WIFI_IRQn, (irq_callback)interrupt0_handler, NULL);
    bflb_irq_enable(WIFI_IRQn);

    xTaskCreate(wifi_main, (char *)"fw", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW, &wifi_fw_task);

    return 0;
}

void wifi_event_handler(uint32_t code) {

    sta_ConnectStatus = code;
    switch (code) {
    case CODE_WIFI_ON_INIT_DONE: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_INIT_DONE\r\n", __func__);
        wifi_mgmr_init(&conf);
    } break;
    case CODE_WIFI_ON_MGMR_DONE: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_MGMR_DONE\r\n", __func__);
    } break;
    case CODE_WIFI_ON_SCAN_DONE: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_SCAN_DONE\r\n", __func__);
        wifi_mgmr_sta_scanlist();
    } break;
    case CODE_WIFI_ON_CONNECTED: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_CONNECTED\r\n", __func__);
        void mm_sec_keydump();
        mm_sec_keydump();
    } break;
    case CODE_WIFI_ON_GOT_IP: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_GOT_IP\r\n", __func__);
    } break;
    case CODE_WIFI_ON_DISCONNECT: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_DISCONNECT\r\n", __func__);
    } break;
    case CODE_WIFI_ON_AP_STARTED: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_AP_STARTED\r\n", __func__);
    } break;
    case CODE_WIFI_ON_AP_STOPPED: {
        LOG_I("[APP] [EVT] %s, CODE_WIFI_ON_AP_STOPPED\r\n", __func__);
    } break;
    case CODE_WIFI_ON_AP_STA_ADD: {
        LOG_I("[APP] [EVT] [AP] [ADD] %lld\r\n", xTaskGetTickCount());
    } break;
    case CODE_WIFI_ON_AP_STA_DEL: {
        LOG_I("[APP] [EVT] [AP] [DEL] %lld\r\n", xTaskGetTickCount());
    } break;
    default: {
        LOG_I("[APP] [EVT] Unknown code %u \r\n", code);
    }
    }
}

uint8_t wifi_connect(char *ssid, char *passwd) {
    LOG_I("call wifi_connect\r\n");
    LOG_I("ssid: %s, password: %s", ssid, passwd);
    uint32_t ipv4_addr = 0;
    if (NULL == ssid || 0 == strlen(ssid)) {
        return 1;
    }

    if (wifi_mgmr_sta_state_get() == 1) {
        wifi_sta_disconnect();
    }
    if (wifi_sta_connect(ssid, passwd, NULL, NULL, 0, 0, 0, 1)) {
        return 4;
    }

    // 等待连接成功
    sta_ConnectStatus = 0;
    for (int i = 0; i < 10 * 30; i++) {
        vTaskDelay(100);
        switch (sta_ConnectStatus) {
        case CODE_WIFI_ON_CONNECTED: // 连接成功(表示wifi sta状态的时候表示同时获取IP(DHCP)成功，或者使用静态IP)
            LOG_I("CODE_WIFI_ON_CONNECTED\r\n");
            break;
        case CODE_WIFI_ON_DISCONNECT: // 连接失败（超过了重连次数还没有连接成功的状态）
            // wifi_sta_disconnect();
            return 4;
        case CODE_WIFI_ON_GOT_IP: // 获取IP
            wifi_sta_ip4_addr_get(&ipv4_addr, NULL, NULL, NULL);
            LOG_I("CODE_WIFI_ON_GOT_IP\r\n");
            xSemaphoreGive(wifiConnectionSemaphore);
            return 0;
        default:
            // 等待连接成功
            break;
        }
    }
    return 14; // 连接超时
}

void wifi_connection(void *arg) {
    // WiFiTaskParameters *params = (WiFiTaskParameters *)arg;
    while (1) {
        if (sta_ConnectStatus == CODE_WIFI_ON_MGMR_DONE) { // WIFI管理初始化完毕
            printf("ssid: %s, password: %s", "RedmiK70E", "Lmn200513");
            wifi_connect("RedmiK70E", "Lmn200513");
        }
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}
#endif
