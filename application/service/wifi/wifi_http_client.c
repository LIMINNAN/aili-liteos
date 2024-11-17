#if 0
#include "wifi_http_client.h"
// api :https://api.caiyunapp.com/v2.6/3JTn4S3Isps9vwxq/weather.json?adcode=610113

static const uint8_t get_buf[] =
    "GET /v2.6/3JTn4S3Isps9vwxq/weather.json?adcode=610113 HTTP/1.1\r\nHost: api.caiyunapp.com\r\n\r\n";
static uint64_t total_cnt = 0;
int sock_client = -1;

/**
 * @brief 关闭socket连接
 *
 * @param sig
 */
static void test_close(int sig) {
    if (sock_client) {
        closesocket(sock_client);
    }
    abort_exec(sig);
    if (total_cnt > 0) {
        printf("Total send data=%lld\r\n", total_cnt);
    }
}

// 默认的请求
#define PING_USAGE                                \
    "wifi_http_test [hostname] [port]\r\n"        \
    "\t hostname: hostname or dest server ip\r\n" \
    "\t port: dest server listen port, defualt port:80\r\n"

/**
 * @brief 实际请求代码
 *
 * @param argc char 数组长度
 * @param argv 具体的请求参数 example : wifi_http_test [hostname] [port]
 */
void wifi_http_client_init(int argc, char **argv) {
    printf("Http client task start ...\r\n");

    char *host_name;
    char *addr;
    char *port;
    struct sockaddr_in remote_addr;

    if (argc < 2) {
        printf("%s", PING_USAGE);
        return;
    }

    /* get address (argv[1] if present) */
    host_name = argv[1];
#ifdef LWIP_DNS
    ip4_addr_t dns_ip;
    netconn_gethostbyname(host_name, &dns_ip);
    printf("%d\r\n", dns_ip);
    addr = ip_ntoa(&dns_ip);
    printf("%s\r\n", addr);
#endif
    /* get port number (argv[2] if present) */
    if (argc > 2) {
        port = argv[2];
    } else {
        port = "80";
    }

    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Http Client create socket error\r\n");
        return;
    }
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(atoi(port));
    remote_addr.sin_addr.s_addr = inet_addr(addr);
    memset(&(remote_addr.sin_zero), 0, sizeof(remote_addr.sin_zero));

    printf("Host:%s, Server ip Address : %s:%s\r\n", host_name, addr, port);

    if (connect(sock_client, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) != 0) {
        printf("Http client connect server falied!\r\n");
        closesocket(sock_client);
        return;
    }
    printf("Http client connect server success!\r\n");

    // vTaskSuspend(NULL);
    return;
}

void wifi_http_get(uint32_t *recv_buf, uint32_t bufSize) {

    memset(recv_buf, 0, bufSize);
    total_cnt = 0;
    // 发送请求
    if (send(sock_client, get_buf, strlen(get_buf), 0) < 0) {
        printf("Send get_buf failed\r\n");
        closesocket(sock_client);
        return;
    }
    total_cnt = recv(sock_client, (uint8_t *)recv_buf, sizeof(recv_buf), 0);
    if (total_cnt <= 0)
        return;
    printf("%s\r\n", (uint8_t *)recv_buf);
    // 接收响应
    while (1) {
        printf("doing noting\r\n");
        vTaskDelay(50000);
    }

    closesocket(sock_client);
    vTaskSuspend(NULL);
}
#endif