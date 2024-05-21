/**
 * Gpio.c
 *
 *
 *  Author    : Hager Samir / Youssef Ahmed
 */

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

#define GPIO_REG(REG_ID, PORT_ID) ((uint32 *)((PORT_ID) + (REG_ID)))
uint32 gpioAddresses[4] = {GPIOA_BASE_ADDR, GPIOB_BASE_ADDR,GPIOC_BASE_ADDR,GPIOD_BASE_ADDR};


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
					uint8 DefaultState)
{
	 uint8 portId = PortName - GPIO_A;
	 GpioType *gpioReg = (GpioType*)gpioAddresses[portId];
	 gpioReg ->GPIO_MODER &= ~(0x03 << (PinNum * 2));
	 gpioReg ->GPIO_MODER |= (PinMode << (PinNum * 2));
	 if (PinMode == GPIO_OUTPUT)
	 {
	 gpioReg ->GPIO_OTYPER &= ~(0x01 << PinNum);
	 gpioReg ->GPIO_OTYPER |= (DefaultState << PinNum);
	 }
	 else if (PinMode == GPIO_INPUT)
	 {
	 gpioReg ->GPIO_PUPDR &= ~(0x03 << PinNum);
	 gpioReg ->GPIO_PUPDR |= (DefaultState << PinNum);
	 }

}

uint32 ObtainModeReg(uint8 PortName)
{
	 uint8 portId = PortName - GPIO_A;
	 GpioType *gpioReg = gpioAddresses[portId];
	 return gpioReg ->GPIO_MODER ;

}


void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data)
{
	uint32 modeReg = ObtainModeReg(PortName); // obtain the mode register for the given port.
	uint8 check =  (modeReg >> (PinNum * 2)) & 0x03;
	 uint8 portId = PortName -GPIO_A;
	 GpioType *gpioReg = gpioAddresses[portId];
	if (check == GPIO_OUTPUT) // check if it's output 01
	{
	    gpioReg ->GPIO_ODR &= ~(0x1 << PinNum);
	    gpioReg ->GPIO_ODR |= (Data << PinNum);
		return OK;
	}
	else
	{
		return NOK;
	}
}

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum)
{
	uint8 portId = PortName -GPIO_A;
	 GpioType *gpioReg = gpioAddresses[portId];
    uint8 data = (gpioReg ->GPIO_IDR >> PinNum) & 0x01;
	return data;
}
