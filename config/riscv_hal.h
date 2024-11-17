#ifndef RISCV_HAL_H
#define RISCV_HAL_H

#include "risc-v/csr.h"
#include "bl616_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LREG               lw
#define SREG               sw
#define REGBYTES           4

#define EXC_SIZE_ON_STACK  (36 * REGBYTES)
#define INT_SIZE_ON_STACK  (32 * REGBYTES)

/* task TCB offset */
#define TASK_CB_KERNEL_SP  0x0
#define TASK_CB_STATUS     0x4

#define UINT32_CUT_MASK    0xFFFFFFFF
#define UINT8_CUT_MASK     0xFF
#define OS_MV_32_BIT       32

/************************ mstatus ************************/
#define RISCV_MSTATUS_UIE  0x00000001
#define RISCV_MSTATUS_MIE  0x00000008
#define RISCV_MSTATUS_UPIE 0x00000010
#define RISCV_MSTATUS_MPIE 0x00000080
#define RISCV_MSTATUS_MPP  0x00001800

/************************ mie ***************************/
#define RISCV_MIE_USIE     0x000000001
#define RISCV_MIE_MSIE     0x000000008
#define RISCV_MIE_UTIE     0x000000010
#define RISCV_MIE_MTIE     0x000000080
#define RISCV_MIE_UEIE     0x000000100
#define RISCV_MIE_MEIE     0x000000800

/************************** mcause ***********************/
#ifndef MCAUSE_INT_ID_MASK
#define MCAUSE_INT_ID_MASK 0x7FFFFFF
#endif
#define RISCV_MCAUSE_ECALL_U 8

#define RISCV_USER_SOFT_IRQ  0
#define RISCV_MACH_SOFT_IRQ  3
#define RISCV_USER_TIMER_IRQ 4
#define RISCV_MACH_TIMER_IRQ 7
#define RISCV_USER_EXT_IRQ   8
#define RISCV_MACH_EXT_IRQ   11

#ifdef __cplusplus
}
#endif
#endif /* RISCV_HAL_H */