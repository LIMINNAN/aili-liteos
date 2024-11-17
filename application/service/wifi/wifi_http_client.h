#include <lwip/api.h>
#include <lwip/arch.h>
#include <lwip/errno.h>
#include <lwip/inet.h>
#include <lwip/opt.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include "bflb_mtimer.h"
#include "utils_getopt.h"

/**
 * @brief 初始化http clieny
 *
 * @param argc char 数组长度
 * @param argv 具体的请求参数 example : wifi_http_test [hostname] [port]
 */
void wifi_http_client_init(int argc, char **argv);
/**
 * @brief 发送http get请求
 *
 * @param recv_buf
 * @param bufSize
 */
void wifi_http_get(uint32_t *recv_buf, uint32_t bufSize);