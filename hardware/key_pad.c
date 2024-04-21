#include "LPC17xx.h"
#include "lcd.h"

unsigned char message_1[] = "ALS BENGALURU";
unsigned char message_2[] = "KEY PRESSED=";

unsigned char scan_code[] = {
    0x1E, 0x1D, 0x1B, 0x17,
    0x2E, 0x2D, 0x2B, 0x27,
    0x4E, 0x4D, 0x4B, 0x47,
    0x8E, 0x8D, 0x8B, 0x87
};

unsigned char ascii_code[] = {
    '0', '1', '2', '3',
    '4', '5', '6', '7',
    '8', '9', 'A', 'B',
    'C', 'D', 'E', 'F'
};

unsigned char flag, key;
unsigned long int temp_1;

void scan(void)
{
    unsigned long temp = LPC_GPIO0->FIOPIN;
    temp &= 0x78000;

    if (temp != 0x78000)
    {
        unsigned int i;
        for (i = 0; i < 500; i++)
        {
            temp = LPC_GPIO0->FIOPIN;
            temp &= 0x78000;

            if (temp != 0x78000)
            {
                flag = 1;
                temp >>= 15;
                temp_1 >>= 16;
                key = temp | temp_1;
            }
        }
    }
}

int main(void)
{
    LPC_PINCON->PINSEL0 = 0x0;
    LPC_PINCON->PINSEL1 = 0x0;
    LPC_PINCON->PINSEL3 = 0x0;

    LPC_GPIO0->FIODIR &= ~0x78000;
    LPC_GPIO1->FIODIR |= 0xF00000;
    LPC_GPIO1->FIOSET = 0xF00000;

    lcd_init();

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
        while (1)
        {
            unsigned char row = 1;
            unsigned long int var_1;

            for (row = 1; row < 5; row++)
            {
                if (row == 1)
                    var_1 = 0x100000;
                else if (row == 2)
                    var_1 = 0x200000;
                else if (row == 3)
                    var_1 = 0x400000;
                else
                    var_1 = 0x800000;

                temp_1 = var_1;

                LPC_GPIO1->FIOSET = 0xF00000;
                LPC_GPIO1->FIOCLR = var_1;

                flag = 0;
                scan();

                if (flag == 1)
                    break;
            }

            if (flag == 1)
                break;
        }

        unsigned long int i = 0;
        for (i = 0; i < 16; i++)
        {
            if (key == scan_code[i])
            {
                key = ascii_code[i];
                break;
            }
        }

        temp1 = 0xCC;
        lcd_com();
        delay_lcd(800);
        lcd_puts(&key);
    }
}
