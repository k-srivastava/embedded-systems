#include "LPC17xx.h"

unsigned char flag, flag_1;

void pwm_init(void)
{
    LPC_SC->PCONP = 1 << 6;
    LPC_PINCON->PINSEL7 = 0xC0000;

    LPC_PWM1->PR = 0x0;
    LPC_PWM1->PCR = 0x400;
    LPC_PWM1->MCR = 0x3;
    LPC_PWM1->MR0 = 30000;
    LPC_PWM1->MR2 = 0x100;
    LPC_PWM1->LER = 0xFF;
    LPC_PWM1->TCR = 0x2;
    LPC_PWM1->TCR = 0x9;

    NVIC_EnableIRQ(PWM1_IRQn);
}

void PWM1_IRQHandler(void)
{
    LPC_PWM1->IR = 0xFF;

    if (flag == 0x0)
    {
        LPC_PWM1->MR2 += 100;
        LPC_PWM1->LER = 0xFF;

        if (LPC_PWM1->MR2 >= 27000)
        {
            flag = 0xFF;
            flag_1 = 0xFF;
            LPC_PWM1->LER = 0xFF;
        }
    }

    else if (flag_1 == 0xFF)
    {
        LPC_PWM1->MR2 -= 100;
        LPC_PWM1->LER = 0xFF;

        if (LPC_PWM1->MR2 <= 0x300)
        {
            flag = 0x0;
            flag_1 = 0x0;
            LPC_PWM1->LER = 0xFF;
        }
    }
}

int main(void)
{
    pwm_init();
    while (1);
}
