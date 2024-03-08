/*
 * LCD_config.h
 *
 * Created: 3/7/2024 7:08:08 PM
 *  Author: Ziad Ashraf
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_RS_PORT				DIO_PORTA
#define LCD_RS_PIN				DIO_PIN3

#define LCD_EN_PORT     		DIO_PORTA
#define LCD_EN_PIN				DIO_PIN2

#define LCD_D4_PORT				DIO_PORTB
#define LCD_D4_PIN				DIO_PIN0

#define LCD_D5_PORT				DIO_PORTB
#define LCD_D5_PIN				DIO_PIN1

#define LCD_D6_PORT				DIO_PORTB
#define LCD_D6_PIN				DIO_PIN2

#define LCD_D7_PORT				DIO_PORTB
#define LCD_D7_PIN				DIO_PIN4


/*
#define	LCD_4BIT_MODE			0x28
#define	LCD_8BIT_MODE			0x38
#define	LCD_CURSOR_UNDERLINE	0x0E
#define	LCD_CGRAM_START_ADDRESS	0x40
*/

/*
 * 0 --> 1 Line
 * 1 --> 4 Lines
 */
#define LCD_NO_OF_LINES 1

/*
 * 0 --> 5 * 7
 * 1 --> 5 * 10
 */
#define LCD_CHAR_FONT 0

/*
 * 0 --> OFF
 * 1 --> ON
 */
#define DISPLAY_STATUS 1

/*
 * 0 --> OFF
 * 1 --> ON
 */
#define CURSOR_DISPLAY 1

/*
 * 0 --> OFF
 * 1 --> ON
 */
#define CURSOR_BLINK 1

/*
 * 0 --> Right to Left
 * 1 --> Left to Right
 */
#define DISPLAY_DIRECTION 1

/*
 * 0 --> OFF
 * 1 --> ON
 */
#define DISPLAY_SHIFT 0

#endif /* LCD_CONFIG_H_ */