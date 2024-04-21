#include "LPC17xx.h"

unsigned char int3_flag = 0;

void EINT3_IRQHandler(void)
{
    LPC_SC->EXTINT = 0x8;

    if (int3_flag == 0x0)
    {
        LPC_GPIO2->FIOCLR = 0x1000;
        int3_flag = 0xFF;
    }

    else
    {
        LPC_GPIO2->FIOSET = 0x1000;
        int3_flag = 0x0;
    }
}

int main(void)
{
    LPC_PINCON->PINSEL4 |= 0x4000000;
    LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;

    LPC_GPIO2->FIODIR = 0x1000;
    LPC_GPIO2->FIOSET = 0x1000;

    LPC_SC->EXTINT = 0x8;
    LPC_SC->EXTMODE = 0x8;
    LPC_SC->EXTPOLAR = 0x0;

    NVIC_EnableIRQ(EINT3_IRQn);

    while (1);
}
