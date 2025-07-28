#include "LIB/STD_TYPES.h"
#include "MCAL/I2C/I2C_Interface.h"
#include <util/delay.h>

int main(void)
{
    u8 name[] = "KAREEM";  // لازم يحتوي على أكثر من حرف
    u8 i = 0;

    I2C_voidMasterInit(0);

    while (1)
    {
        I2C_Master_u8StartCondition();

        if (I2C_Master_u8SendSLA_Write_ACK(0x20) == I2C_NO_Error)
        {
            i = 0;
            while (name[i] != '\0')  // لازم يبعث كل الحروف
            {
                I2C_Master_u8WriteDataByte_ACK(name[i++]);
            }
            I2C_Master_u8WriteDataByte_ACK('\0');  // نهاية الرسالة
        }

        I2C_Master_voidStopCondition();
        _delay_ms(3000);  // علشان تشوف البيانات وتعيد الإرسال
    }
}
