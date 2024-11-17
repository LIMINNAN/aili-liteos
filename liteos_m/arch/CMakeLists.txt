sdk_generate_library()

# 添加源文件到目标
sdk_library_add_sources(
    risc-v/riscv32/gcc/los_context.c
    risc-v/riscv32/gcc/los_dispatch.S
    risc-v/riscv32/gcc/los_exc.S
    risc-v/riscv32/gcc/los_interrupt.c
    risc-v/riscv32/gcc/los_timer.c
    risc-v/common/los_common_interrupt.c
)

sdk_add_include_directories(
    include
    risc-v/riscv32/gcc
    risc-v/common
)