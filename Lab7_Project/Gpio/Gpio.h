/**
 * Gpio.h
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"



/*PortName*/
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

/*PinMode*/
#define GPIO_INPUT  0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF     0x02
#define GPIO_ANALOG 0x03

/*DefaultState For output pin-mode*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01

/*DefaultState For input pin-mode*/

#define GPIO_NO_PULL_UP_DOWN 0x00
#define GPIO_PULL_UP         0x01
#define GPIO_PULL_DOWN	     0x10
#define GPIO_RESERVED		 0x11



/*Data*/
#define LOW  0x00
#define HIGH 0x01
#define OK 0
#define NOK 1


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);


// TODO: make this function as described in Lab4.pdf
uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum);



#endif /* GPIO_H */
