#ifndef __SERVOMOVEMENT_H_
#define __SERVOMOVEMENT_H_
/**
 * @file servomovement.h
 * @author Nanthini ()
 * @brief Project to servomovemnt connected to oscope MCU GPIO Pin
 * @version 0.1
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define SERVO_ON 	(0x01)			/**< SERVO state HIGH */
#define SERVO_OFF	(0x00)			/**< SERVO state LOW */

#define SERVO_ON_TIME     (1000)  /**< SERVO ON time in milli seconds  */
#define SERVO_OFF_TIME    (500)   /**< SERVO OFF time in milli seconds */

/**
 * Include files
 */ 
#include <avr/io.h>

/**
 * Function Definitions
 */

/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_servo_state(uint8_t state);


#endif /** __SERVOMOVEMENT_H_ */
