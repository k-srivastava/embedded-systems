#include "LPC17xx.h"

void clockwise(void)
{
    unsigned int rotate_var = 0x1;

    unsigned int i = 0;
    for (i = 0; i <= 3; i++)
    {
        LPC_GPIO2->FIOCLR = 0xF;
        LPC_GPIO2->FIOSET = rotate_var;

        rotate_var <<= 1;

        unsigned int k = 0;
        for (k = 0; k < 15000; k++);
    }
}

void anti_clockwise(void)
{
    unsigned int rotate_var = 0x8;

    unsigned int i = 0;
    for (i = 0; i <= 3; i++)
    {
        LPC_GPIO2->FIOCLR = 0xF;
        LPC_GPIO2->FIOSET = rotate_var;

        rotate_var >>= 1;

        unsigned int k = 0;
        for (k = 0; k < 15000; k++);
    }
}

int main(void)
{
    LPC_PINCON->PINSEL4 = 0x0;
    LPC_GPIO2->FIODIR = 0xF;

    while (1)
    {
        unsigned int i = 0, j = 0;

        for (i = 0; i < 50; i++) { clockwise(); }
        for (j = 0; j < 50000; j++) {}
        for (i = 0; i < 50; i++) { anti_clockwise(); }
    }
}
