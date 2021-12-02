/**
 * @file project_main.c
 * @author Nanthini.()
 * @brief Project to Blink an LED at 1000ms ON and 500 ms OFF Interval
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

#include "user_utils.h"
#include "servomovement.h"

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB |= (1 << DDB0);
}

void change_led_state(uint8_t state)
{
	SERVO_PORT = (state << SERVO_PIN);
}


/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the servo will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the servo  will turn ON
 */
#define  F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= 0xFF;

    ICR1 = 19999;
    TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0 | 1<<COM1B1 | 1<<COM1B0;
    TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10; //Prescaler=1,inverted, fast PWM,Mode 14
    
    while(1)
    {
        for( int i=1000; i<=2000; i+=100 )
        {
            OCR1A = ICR1 - i;
            OCR1B = ICR1 - i;
            _delay_ms(100);
        }
    }
}
