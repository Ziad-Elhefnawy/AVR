/*
 * DIO_registers.h
 *
 * Created: 3/6/2024 7:18:27 PM
 *  Author: Ziad Ashraf
 */ 


#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

//registers addresses of port A
#define DIO_PORTA_REG	(*((volatile u8*) 0x3B))
#define DIO_DDRA_REG	(*((volatile u8*) 0x3A))
#define DIO_PINA_REG	(*((volatile u8*) 0x39))

//registers addresses of port B
#define DIO_PORTB_REG	(*((volatile u8*) 0x38))
#define DIO_DDRB_REG	(*((volatile u8*) 0x37))
#define DIO_PINB_REG	(*((volatile u8*) 0x36))

//registers addresses of port B
#define DIO_PORTC_REG	(*((volatile u8*) 0x35))
#define DIO_DDRC_REG	(*((volatile u8*) 0x34))
#define DIO_PINC_REG	(*((volatile u8*) 0x33))

//registers addresses of port D
#define DIO_PORTD_REG	(*((volatile u8*) 0x32))
#define DIO_DDRD_REG	(*((volatile u8*) 0x31))
#define DIO_PIND_REG	(*((volatile u8*) 0x30))




#endif /* DIO_REGISTERS_H_ */