#include "LIB/STD_TYPES.h"
#include "MCAL/I2C/I2C_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

int main(void)
{
    u8 name[7];  // 6 حروف + نهاية \0
    u8 data;
    u8 i = 0;

    LCD_voidInit();
    I2C_voidSlaveInit(0x20);

    LCD_voidWriteString("Waiting...");
    _delay_ms(1000);
    LCD_voidClearDisplay();

    while (1)
    {
        i = 0;
        if (I2C_SLAVE_u8OwnSLA_Write_Recieved_ACK() == I2C_NO_Error)
        {
            while (i < 6)  // استقبل فقط 6 حروف
            {
                if (I2C_SLAVE_u8DataByteRecieved_ACK(&data) == I2C_NO_Error)
                {
                    name[i++] = data;
                }
            }

            name[i] = '\0';  // نهاية السلسلة
            LCD_voidClearDisplay();
            LCD_voidWriteString(name);  // اطبع الاسم مرة واحدة
        }
    }
}
