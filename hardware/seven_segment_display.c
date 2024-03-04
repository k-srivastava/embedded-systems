#include "LPC17xx.h"

#define ALL_DISPLAY 0x180000
#define DATAPORT 0xFF0

unsigned int display[16] = {
    0x3F0, 0x060, 0x5B0, 0x4F0,
    0x660, 0x6D0, 0x7D0, 0x070,
    0x7F0, 0x6F0, 0x770, 0x7C0,
    0x390, 0x5E0, 0x790, 0x710
};


int main(void)
{
    LPC_PINCON->PINSEL0 = 0x0;
    LPC_PINCON->PINSEL1 = 0x0;

    LPC_GPIO0->FIODIR = 0x180FF0;

    while (1)
    {
        unsigned int i = 0;
        for (i = 0; i <= 0xF; i++)
        {
            LPC_GPIO0->FIODIR = 0x180FF0;
            LPC_GPIO0->FIOSET = ALL_DISPLAY;
            LPC_GPIO0->FIOCLR = DATAPORT;
            LPC_GPIO0->FIOSET = display[i];

            unsigned int j = 0;
            for (j = 0; j < 3; j++)
            {
                unsigned int delay = 0;
                for (delay = 0; delay < 600000; delay++);
            }
        }
    }
}
