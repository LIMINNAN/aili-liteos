#include "bflb_mtimer.h"
#include "board.h"
#include "task_sample.h"
#include "bl616_clock.h"
#include "target_config.h"

int main(void)
{
    board_init();

    RunTaskSample();

    for (;;)
        ;
}
