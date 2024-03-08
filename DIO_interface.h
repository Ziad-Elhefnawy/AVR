/*
 * DIO_interface.h
 *
 * Created: 3/6/2024 7:14:46 PM
 *  Author: Ziad Ashraf
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//macros for PortX
#define DIO_PORTA			0
#define DIO_PORTB			1
#define DIO_PORTC			2
#define DIO_PORTD			3

//macros for PortValue
#define DIO_PORT_HIGH		0xFF
#define DIO_PORT_LOW		0x00

//macros for PortDirection
#define DIO_PORT_INPUT		0x00
#define DIO_PORT_OUTPUT		0xFF

//macros for PinX
#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2			2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7

//macros for PinValue
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

//macros for PinDirection
#define DIO_PIN_INPUT		0
#define DIO_PIN_OUTPUT		1

//functions prototypes of pin
void DIO_voidSetPinDirection				(u8 copy_u8PortX, u8 copy_u8PinX, u8 copy_u8PinDirection);
void DIO_voidSetPinValue					(u8 copy_u8PortX, u8 copy_u8PinX, u8 copy_u8PinValue);
void DIO_voidGetPinValue					(u8 copy_u8PortX, u8 copy_u8PinX, u8* copy_pu8PinValue);
void DIO_voidTogglePinValue					(u8 copy_u8PortX, u8 copy_u8PinX);
void DIO_voidActivePinInPullUpResistance	(u8 copy_u8PortX, u8 copy_u8PinX);


//functions prototypes of port
void DIO_voidSetPortDirection				(u8 copy_u8PortX, u8 copy_u8PortDirection);
void DIO_voidSetPortValue					(u8 copy_u8PortX, u8 copy_u8PortValue);
void DIO_voidGetPortValue					(u8 copy_u8PortX, u8* copy_pu8PortValue);
void DIO_voidTogglePortValue				(u8 copy_u8PortX);
void DIO_voidActivePortInPullUpResistance	(u8 copy_u8PortX);

//DIO initialization function prototype 
void DIO_voidInit();

#endif /* DIO_INTERFACE_H_ */