/*
 * main.c
 *
 *  Created on: Mar 20, 2024
 *      Author: moham
 */

#include "HAL/LCD/LCD_interface.h"

#include "HAL/IR_Remote_Control/IR_interface.h"

#include "SERVICE/STRING_SERVICE_FUN.h"

#include "MCAL/TIMER1/TIMER1_private.h"
#include "MCAL/GPIO/GPIO_interface.h"


uint64 IR_signal_buffer = 0 ;

uint8 the_protocol_type[30] ;
uint8 the_code[30] ;

volatile uint8 IR_press_state = 0 ;


#define F_CPU 8000000UL
#include "util/delay.h"

int main(void)
{
    LCD_init();
    IR_Remote_Init();
    GPIO_init();

    while(1)
    {
        IR_signal_buffer = IR_Remote_Receive(the_protocol_type , &IR_press_state);
        Convert_uint64_to_String(IR_signal_buffer,the_code);
		
        LCD_MoveCursor(0,0);
        LCD_DisplayString(the_code);


        LCD_MoveCursor(1,0);
        LCD_DisplayString(the_protocol_type);

       if( (IR_signal_buffer == IR_CMD_1) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN0_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_1) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN0_ID,LOGIC_LOW);
       }

       if( (IR_signal_buffer == IR_CMD_2) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN1_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_2) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN1_ID,LOGIC_LOW);
       }

       if( (IR_signal_buffer == IR_CMD_3) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN2_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_3) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN2_ID,LOGIC_LOW);
       }

       if( (IR_signal_buffer == IR_CMD_4) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN3_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_4) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN3_ID,LOGIC_LOW);
       }


       if( (IR_signal_buffer == IR_CMD_4) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN3_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_4) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN3_ID,LOGIC_LOW);
       }

       if( (IR_signal_buffer == IR_CMD_5) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN4_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_5) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN4_ID,LOGIC_LOW);
       }

       if( (IR_signal_buffer == IR_CMD_6) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN5_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_6) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN5_ID,LOGIC_LOW);
       }


       if( (IR_signal_buffer == IR_CMD_7) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN6_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_7) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN6_ID,LOGIC_LOW);
       }

       if( (IR_signal_buffer == IR_CMD_8) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN7_ID,LOGIC_HIGH);
       }
       else if( (IR_signal_buffer == IR_CMD_8) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePin(PORTA_ID,PIN7_ID,LOGIC_LOW);
       }


       if( (IR_signal_buffer == IR_CMD_9) && (IR_press_state == NewPress_IR) )
       {
           GPIO_WritePort(PORTA_ID,ONES_WORD);
       }
       else if( (IR_signal_buffer == IR_CMD_9) && (IR_press_state == StillPress_IR) )
       {
           GPIO_WritePort(PORTA_ID,ZEROS_WORD);
       }

    }

}



