#include <stdio.h>

#include "LPC17xx.h"
#include "lcd.h"

#define REF_VOLTAGE 3.3
#define FULL_SCALE 0xFFF

int main(void)
{
    unsigned char message_1[] = "ANALOG IP:";
    unsigned char message_2[] = "ADC OUTPUT:";
    unsigned char blank[] = "   ";

    lcd_init();
    LPC_PINCON->PINSEL3 |= 0xC0000000;
    LPC_SC->PCONP |= 1 << 12;

    temp1 = 0x80;
    lcd_com();
    delay_lcd(800);
    lcd_puts(message_1);

    temp1 = 0xC0;
    lcd_com();
    delay_lcd(800);
    lcd_puts(message_2);

    while (1)
    {
        LPC_ADC->ADCR = 1 << 5 | 1 << 21 | 1 << 24;

        unsigned int i = 0;
        for (i = 0; i < 2000; i++) {}

        unsigned int adc_temp;
        while ((adc_temp = LPC_ADC->ADGDR) == 0x80000000) {}

        adc_temp = LPC_ADC->ADGDR;
        adc_temp >>= 4;
        adc_temp &= 0xFFF;

        const float in_voltage = (float)adc_temp * (float)REF_VOLTAGE / (float)FULL_SCALE;
        unsigned char voltage[7], dval[7];

        sprintf(voltage, "%3.2fV", in_voltage);
        sprintf(dval, "%x", adc_temp);

        for (i = 0; i < 2000; i++) {}

        temp1 = 0x8A;
        lcd_com();
        delay_lcd(800);
        lcd_puts(voltage);

        temp1 = 0xCB;
        lcd_com();
        lcd_puts(blank);

        temp1 = 0xCB;
        lcd_com();
        delay_lcd(800);
        lcd_puts(dval);

        for (i = 0; i < 200000; i++) {}
    }
}
