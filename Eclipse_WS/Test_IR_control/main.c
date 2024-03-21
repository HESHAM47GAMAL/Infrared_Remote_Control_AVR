/*
*   
*   Here there are small test for IR Remote control as only dispaly signal of remote and display Protocol
*   
*
*/




#include "SERVICE/STRING_SERVICE_FUN.h"

#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"

#include "HAL/IR_Remote_Control/IR_interface.h"
#include "HAL/LCD/LCD_interface.h"

uint64 IR_code = 0 ;
uint8 protocol [10];
uint8 the_code[30];
uint8 IR_Remote_Press_Status ;

int main()
{

    GPIO_init();
    IR_Remote_Init();
    LCD_init();

    while(1)
    {
        IR_code = IR_Remote_Receive(protocol,&IR_Remote_Press_Status);
        Convert_uint64_to_String(IR_code,the_code);

        LCD_MoveCursor(0,0);
        LCD_DisplayString(the_code);
        LCD_MoveCursor(1,0);
        LCD_DisplayString(protocol);
    }


}