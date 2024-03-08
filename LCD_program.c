/*
 * LCD_program.c
 *
 * Created: 3/7/2024 7:06:28 PM
 *  Author: Ziad Ashraf
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

//including libraries directives
#include "../Includes/LIB/STD_TYPES.h"
#include "../Includes/LIB/BIT_MATH.h"
#include <util/delay.h>

//including DIO directives
#include "../Includes/MCAL/DIO/DIO_interface.h"

//include DIO directives
#include "../Includes/HAL/LCD/LCD_interface.h"
#include "../Includes/HAL/LCD/LCD_config.h"
#include "../Includes/HAL/LCD/LCD_private.h"




static void enablePulse(void)
{
	DIO_voidSetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
	_delay_ms(2);
}


void LCD_voidWriteData(u8 copy_u8data){
		// RS: Data Mode
		DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);

		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8data,4));
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D5_PIN,GET_BIT(copy_u8data,5));
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D6_PIN,GET_BIT(copy_u8data,6));
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D7_PIN,GET_BIT(copy_u8data,7));
		
		enablePulse();
		
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8data,0));
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D5_PIN,GET_BIT(copy_u8data,1));
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D6_PIN,GET_BIT(copy_u8data,2));
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D7_PIN,GET_BIT(copy_u8data,3));
		
		enablePulse();
}


void LCD_voidWriteCommand(u8 copy_u8Command){
	
	// RS: Command Mode	
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);

	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Command,4));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Command,5));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Command,6));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Command,7));
	
	enablePulse();
	
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Command,0));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Command,1));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Command,2));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Command,3));
	
	enablePulse();
	
}


void LCD_voidInit(void){
	
	// Wait for more than 30 ms after VDD rises to 4.5V
	_delay_ms(30);

	// Function Set Command
	LCD_voidWriteCommand(LCD_FUNCTION_SET);
	// Wait for more than 39 us
	_delay_ms(1);

	// Display ON/OFF Control Command
	LCD_voidWriteCommand(LCD_DISPLAY_ON_OFF_CONTROL);
	// Wait for more than 39 us
	_delay_ms(1);

	// Display Clear Command
	LCD_voidWriteCommand(LCD_DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(2);

	// Entry Mode Set Command
	LCD_voidWriteCommand(LCD_ENTRY_MODE_SET);
	// Wait for more than 39 us
	_delay_ms(1);
	
	
}

void LCD_voidWriteString(u8 * copy_str){
	
	while (*copy_str != '\0')
	{
		LCD_voidWriteData(*copy_str);
		copy_str++;
	}
	
}


void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col){
	
	switch (copy_u8Row){
		case 0:
		LCD_voidWriteCommand(LCD_BEGINNING_FIRST_LINE+copy_u8Col);
		break;
		case 1:
		LCD_voidWriteCommand(LCD_BEGINNING_SECOND_LINE+copy_u8Col);
		break;
		case 2:
		LCD_voidWriteCommand(LCD_BEGINNING_THIRD_LINE+copy_u8Col);
		break;
		case 3:
		LCD_voidWriteCommand(LCD_BEGINNING_FOURTH_LINE+copy_u8Col);
		break;
	}
	
}


void LCD_voidClear(void){
	
	LCD_voidWriteCommand(LCD_DISPLAY_CLEAR);
	_delay_ms(5);
	
}


void LCD_voidWriteNumber( u32 copy_u8num ){
	
	u32 local_u32Number = 1;
	if (copy_u8num == 0)
	{
		LCD_voidWriteData('0');
	}
	while (copy_u8num != 0)
	{
		local_u32Number = (local_u32Number * 10) + (copy_u8num % 10);
		copy_u8num = copy_u8num / 10;
	}
	while (local_u32Number != 1)
	{
		LCD_voidWriteData(( local_u32Number % 10) + 48);
		local_u32Number = local_u32Number / 10;
	}
	
}

void lcd_voidDisplayChar(u8 chr)
{
	LCD_voidWriteData(chr);
}


/*void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum ){

	u8 loc_ByteIndex=0;
	u8 loc_CharIndx=0;

	for (loc_CharIndx=0;loc_CharIndx<NO_CSTOM_CHAR;loc_CharIndx++)
	{
		lcd_vidSendCmd(_LCD_CGRAM_START_ADDRESS +(loc_CharIndx*8));
		for (loc_ByteIndex =0; loc_ByteIndex<NO_CSTOM_CHAR_BYTES;loc_ByteIndex++)
		{
			lcd_vidDisplyChar(customChar[loc_CharIndx][copy_u8ByteNum]);
		}
	}
	
}


void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ){



} */



