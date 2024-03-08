/*
 * DIO_program.c
 *
 * Created: 3/6/2024 7:13:27 PM
 *  Author: Ziad Ashraf
 */ 

//including libraries directives
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

//including DIO directives
#include "../Include/MCAL/DIO/DIO_interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_registers.h"
#include "../Include/MCAL/DIO/DIO_config.h"



void DIO_voidSetPinDirection (u8 copy_u8PortX, u8 copy_u8PinX, u8 copy_u8PinDirection){
	
	switch(copy_u8PortX){
	case DIO_PORTA:
		switch(copy_u8PinDirection){
		case DIO_PIN_INPUT:
		CLEAR_BIT(DIO_DDRA_REG, copy_u8PinX);
		break;
		case DIO_PIN_OUTPUT:
		SET_BIT(DIO_DDRA_REG, copy_u8PinX);
		break;
	}
	break;
	case DIO_PORTB:
	switch(copy_u8PinDirection){
		case DIO_PIN_INPUT:
		CLEAR_BIT(DIO_DDRB_REG, copy_u8PinX);
		break;
		case DIO_PIN_OUTPUT:
		SET_BIT(DIO_DDRB_REG, copy_u8PinX);
		break;
	}
	break;
	case DIO_PORTC:
	switch(copy_u8PinDirection){
		case DIO_PIN_INPUT:
		CLEAR_BIT(DIO_DDRC_REG, copy_u8PinX);
		break;
		case DIO_PIN_OUTPUT:
		SET_BIT(DIO_DDRC_REG, copy_u8PinX);
		break;
	}
	break;
	case DIO_PORTD:
	switch(copy_u8PinDirection){
		case DIO_PIN_INPUT:
		CLEAR_BIT(DIO_DDRD_REG, copy_u8PinX);
		break;
		case DIO_PIN_OUTPUT:
		SET_BIT(DIO_DDRD_REG, copy_u8PinX);
		break;
	}
	break;
	}

}


void DIO_voidSetPinValue (u8 copy_u8PortX, u8 copy_u8PinX, u8 copy_u8PinValue){
	
	switch(copy_u8PortX){
		case DIO_PORTA:
		switch(copy_u8PinValue){
			case DIO_PIN_HIGH:
			SET_BIT(DIO_PORTA_REG, copy_u8PinX);
			break;
			case DIO_PIN_LOW:
			CLEAR_BIT(DIO_PORTA_REG, copy_u8PinX);
			break;
		}
		case DIO_PORTB:
		switch(copy_u8PinValue){
			case DIO_PIN_HIGH:
			SET_BIT(DIO_PORTB_REG, copy_u8PinX);
			break;
			case DIO_PIN_LOW:
			CLEAR_BIT(DIO_PORTB_REG, copy_u8PinX);
			break;
		}
		case DIO_PORTC:
		switch(copy_u8PinValue){
			case DIO_PIN_HIGH:
			SET_BIT(DIO_PORTC_REG, copy_u8PinX);
			break;
			case DIO_PIN_LOW:
			CLEAR_BIT(DIO_PORTC_REG, copy_u8PinX);
			break;
		}
		case DIO_PORTD:
		switch(copy_u8PinValue){
			case DIO_PIN_HIGH:
			SET_BIT(DIO_PORTD_REG, copy_u8PinX);
			break;
			case DIO_PIN_LOW:
			CLEAR_BIT(DIO_PORTD_REG, copy_u8PinX);
			break;
		}
	}
	
}


void DIO_voidGetPinValue (u8 copy_u8PortX, u8 copy_u8PinX, u8* copy_pu8PinValue){
	
	if(copy_pu8PinValue!=NULL){
		switch(copy_u8PortX){
			case DIO_PORTA:
			*copy_pu8PinValue = GET_BIT(DIO_PINA_REG, copy_u8PinX);
			break;
			case DIO_PORTB:
			*copy_pu8PinValue = GET_BIT(DIO_PINB_REG, copy_u8PinX);
			break;
			case DIO_PORTC:
			*copy_pu8PinValue = GET_BIT(DIO_PINC_REG, copy_u8PinX);
			break;
			case DIO_PORTD:
			*copy_pu8PinValue = GET_BIT(DIO_PIND_REG, copy_u8PinX);
			break;
		}
	}else{
		//return Error State
	}

}


void DIO_voidTogglePinValue	(u8 copy_u8PortX, u8 copy_u8PinX){
	
	switch(copy_u8PortX){
		case DIO_PORTA:
		TOGGLE_BIT(DIO_PORTA_REG, copy_u8PinX);
		break;
		case DIO_PORTB:
		TOGGLE_BIT(DIO_PORTB_REG, copy_u8PinX);
		break;
		case DIO_PORTC:
		TOGGLE_BIT(DIO_PORTC_REG, copy_u8PinX);
		break;
		case DIO_PORTD:
		TOGGLE_BIT(DIO_PORTD_REG, copy_u8PinX);
		break;
	}
	
}


void DIO_voidActivePinInPullUpResistance (u8 copy_u8PortX, u8 copy_u8PinX){
	
	 // Configure the pin as input
	 DIO_voidSetPinDirection(copy_u8PortX, copy_u8PinX, DIO_PIN_INPUT);
	 
	 // Enable the internal pull-up resistor
	 DIO_voidSetPinValue(copy_u8PortX, copy_u8PinX, DIO_PIN_HIGH);
	
}


void DIO_voidSetPortDirection (u8 copy_u8PortX, u8 copy_u8PortDirection){
	
	switch(copy_u8PortX){
		case DIO_PORTA:
		switch(copy_u8PortDirection){
			case DIO_PORT_INPUT:
			DIO_DDRA_REG = DIO_PORT_LOW;
			break;
			case DIO_PORT_OUTPUT:
			DIO_DDRA_REG = DIO_PORT_HIGH;
			break;
		}
		case DIO_PORTB:
		switch(copy_u8PortDirection){
			case DIO_PORT_INPUT:
			DIO_DDRB_REG = DIO_PORT_LOW;
			break;
			case DIO_PORT_OUTPUT:
			DIO_DDRB_REG = DIO_PORT_HIGH;
			break;
		}
		case DIO_PORTC:
		switch(copy_u8PortDirection){
			case DIO_PORT_INPUT:
			DIO_DDRC_REG = DIO_PORT_LOW;
			break;
			case DIO_PORT_OUTPUT:
			DIO_DDRC_REG = DIO_PORT_HIGH;
			break;
		}
		case DIO_PORTD:
		switch(copy_u8PortDirection){
			case DIO_PORT_INPUT:
			DIO_DDRD_REG = DIO_PORT_LOW;
			break;
			case DIO_PORT_OUTPUT:
			DIO_DDRD_REG = DIO_PORT_HIGH;
			break;
		}
	}
	
}


void DIO_voidSetPortValue (u8 copy_u8PortX, u8 copy_u8PortValue){
	
	switch(copy_u8PortX){
		case DIO_PORTA:
		DIO_PORTA_REG = copy_u8PortValue;
		break;
		case DIO_PORTB:
		DIO_PORTB_REG = copy_u8PortValue;
		break;
		case DIO_PORTC:
		DIO_PORTC_REG = copy_u8PortValue;
		break;
		case DIO_PORTD:
		DIO_PORTD_REG = copy_u8PortValue;
		break;
	}
	
}


void DIO_u8GetPortValue (u8 copy_u8PortX, u8* copy_pu8PortValue){
	
	if(copy_pu8PortValue!=NULL){
		switch(copy_u8PortX){
			case DIO_PORTA:
			*copy_pu8PortValue = DIO_PINA_REG;
			break;
			case DIO_PORTB:
			*copy_pu8PortValue = DIO_PINB_REG;
			break;
			case DIO_PORTC:
			*copy_pu8PortValue = DIO_PINC_REG;
			break;
			case DIO_PORTD:
			*copy_pu8PortValue = DIO_PIND_REG;
			break;
		}
	}else{
		//return Error State
	}
	
}


void DIO_voidTogglePortValue (u8 copy_u8PortX){
	
	u8 pu8PortValue;
	switch(copy_u8PortX){
		case DIO_PORTA:
		DIO_u8GetPortValue(DIO_PORTA, &pu8PortValue);
		DIO_voidSetPortValue(DIO_PORTA,~pu8PortValue);
		break;
		case DIO_PORTB:
		DIO_u8GetPortValue(DIO_PORTB, &pu8PortValue);
		DIO_voidSetPortValue(DIO_PORTB,~pu8PortValue);
		break;
		case DIO_PORTC:
		DIO_u8GetPortValue(DIO_PORTC, &pu8PortValue);
		DIO_voidSetPortValue(DIO_PORTC,~pu8PortValue);
		break;
		case DIO_PORTD:
		DIO_u8GetPortValue(DIO_PORTC, &pu8PortValue);
		DIO_voidSetPortValue(DIO_PORTC,~pu8PortValue);
		break;
	}
	
}


void DIO_voidActivePortInPullUpResistance (u8 copy_u8PortX){
	
	switch(copy_u8PortX){
		case DIO_PORTA:
		DIO_voidSetPortDirection(DIO_PORTA,DIO_PORT_INPUT);
		DIO_voidSetPortValue(DIO_PORTA,DIO_PORT_HIGH);
		break;
		case DIO_PORTB:
		DIO_voidSetPortDirection(DIO_PORTB,DIO_PORT_INPUT);
		DIO_voidSetPortValue(DIO_PORTB,DIO_PORT_HIGH);
		break;
		case DIO_PORTC:
		DIO_voidSetPortDirection(DIO_PORTC,DIO_PORT_INPUT);
		DIO_voidSetPortValue(DIO_PORTC,DIO_PORT_HIGH);
		break;
		case DIO_PORTD:
		DIO_voidSetPortDirection(DIO_PORTD,DIO_PORT_INPUT);
		DIO_voidSetPortValue(DIO_PORTD,DIO_PORT_HIGH);
		break;
	}
	
}

void DIO_voidInit(){
	
	DIO_DDRA_REG = DIO_PORTA_DIRECTION;
	DIO_DDRB_REG = DIO_PORTB_DIRECTION;
	DIO_DDRC_REG = DIO_PORTC_DIRECTION;
	DIO_DDRD_REG = DIO_PORTD_DIRECTION;
	
}




