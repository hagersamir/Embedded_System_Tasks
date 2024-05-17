#ifndef EXTI_H
#define EXTI_H
#include "EXTI_Private.h"
#include "Utils.h"
#include "Bit_Operations.h"
#include "Nvic.h"
#include "Gpio.h"

#define INC_PORT GPIO_A
#define DEC_PORT GPIO_B
#define INC_PIN 9
#define DEC_PIN 4
#define FALLING_EDGE EXTI->FTSR
#define RISING_EDGE EXTI->RTSR


void Exti_Init(uint8 PortName, uint8 PinNum, uint8 mode);
void Exti_Enable(uint8 line);
void Exti_Disable(uint8 line);

#endif /* EXTI_H */
