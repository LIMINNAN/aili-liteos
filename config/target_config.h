#ifndef TARGET_CONFIG_H
#define TARGET_CONFIG_H

// 系统时钟（单位：Hz）
#define OS_SYS_CLOCK                            1000000 // 1 MHz

// 操作系统节拍的时钟周期
#define LOSCFG_BASE_CORE_TICK_PER_SECOND        1000UL // 每秒 1000 次节拍
#define MTIMER_INT_FREQ                         (OS_SYS_CLOCK / LOSCFG_BASE_CORE_TICK_PER_SECOND)
#define LOSCFG_BASE_CORE_TICK_RESPONSE_MAX      0xFFFFFFFFUL // 最大响应时间 0xffffffff 个节拍

// 定时器裁剪的外部配置项
#define LOSCFG_BASE_CORE_TICK_HW_TIME           0
#define LOSCFG_BASE_CORE_TICK_WTIMER            1
// 是否采用接管中断的方式
#define LOSCFG_PLATFORM_HWI                     1 // 1 表示采用接管中断的方式

// 支持的最大任务个数（除去空闲任务）
#define LOSCFG_BASE_CORE_TSK_LIMIT              32 // 最大任务数 32

// 空闲任务的堆栈大小
#define LOSCFG_BASE_CORE_TSK_IDLE_STACK_SIZE    0x360UL // 空闲任务堆栈大小 0x180

// 默认任务栈大小
#define LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE 0x1000UL // 默认任务栈大小 0x1000

// 最小任务堆栈大小，按 4 字节对齐
#define LOSCFG_BASE_CORE_TSK_MIN_STACK_SIZE     ALIGN(0x180, 4) // 最小任务堆栈大小

// 具有相同优先级任务的最长执行时间（单位：节拍）
#define LOSCFG_BASE_CORE_TIMESLICE_TIMEOUT      2 // 时间片最大 2 个节拍

// 最大支持信号量的个数
#define LOSCFG_BASE_IPC_SEM_LIMIT               100 // 最大信号量数 100

// 最大支持互斥量的个数
#define LOSCFG_BASE_IPC_MUX_LIMIT               64 // 最大互斥量数 64

// 最大支持消息队列的个数
#define LOSCFG_BASE_IPC_QUEUE_LIMIT             64 // 最大消息队列数 64

// 支持的最大软件定时器数量
#define LOSCFG_BASE_CORE_SWTMR_LIMIT            80 // 最大软件定时器数量 80
#define LOSCFG_BACKTRACE_DEPTH                  15
#define OS_SYS_MEM_SIZE                         1024UL
#endif // TARGET_CONFIG_H
