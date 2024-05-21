#ifndef EXTI_H
#define EXTI_H
#include "EXTI_Private.h"
#include "Utils.h"
#include "Bit_Operations.h"
#include "Nvic.h"
#include "Gpio.h"

#define INC_PORT GPIO_A
#define DEC_PORT GPIO_B
#define Port_Seg GPIO_D
#define Start_Pin_Seg 0
#define INC_PIN 9
#define DEC_PIN 4
static uint32 FALLING_EDGE = 0x1;
static uint32 RISING_EDGE = 0x0;

#define NUM_OF_EXTICR_REGISTERS 4
#define NUM_OF_BITS_PER_PIN 4

static uint32* SYSCFG_EXTICR[NUM_OF_EXTICR_REGISTERS] = {
    &(SYSCFG->EXTICR1),
    &(SYSCFG->EXTICR2),
    &(SYSCFG->EXTICR3),
    &(SYSCFG->EXTICR4)
};


void Exti_Init(uint8 PortName, uint8 PinNum, uint32 edge);
// void Exti_Init(uint8 PortName, uint8 PinNum, uint8 edge,void(*callbackFunctionPtr)(void));
void Exti_Enable(uint8 line);
void Exti_Disable(uint8 line);

#endif /* EXTI_H */
