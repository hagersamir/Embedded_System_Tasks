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
	 uint8 portId = PortName -GPIO_A;
     uint32 *gpioModerReg = GPIO_REG(GPIOx_MODER, gpioAddresses[portId]);
     uint32 *gpioOutputTypeReg = GPIO_REG(GPIOx_OTYPER, gpioAddresses[portId]);
     uint32 *gpioInputTypeReg = GPIO_REG(GPIOx_PUPDR, gpioAddresses[portId]);
     *gpioModerReg  &= ~(0x03 << (PinNum * 2));
     *gpioModerReg  |= (PinMode << (PinNum * 2));
     *gpioOutputTypeReg &= ~(0x01 << PinNum); // mask of 1 bit for 2 states [(push-pull), (open-drain)]
     *gpioOutputTypeReg |= (DefaultState << PinNum);
     *gpioInputTypeReg &= ~(0x03 << PinNum); // mask of 2 bit for 4 states [(no pull-up and pull-down), (Pull-up), (Pull-down), (Reserved)]
     *gpioInputTypeReg |= (DefaultState << PinNum);

}

uint32 ObtainModeReg(uint8 PortName)
{
	 uint8 portId = PortName -GPIO_A;
	 uint32 *gpioModerReg = GPIO_REG(GPIOx_MODER, gpioAddresses[portId]);
	return *gpioModerReg;
}


uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data)
{
	uint32 modeReg = ObtainModeReg(PortName); // obtain the mode register for the given port.
	uint8 check =  (modeReg >> (PinNum * 2)) & 0x03;
	 uint8 portId = PortName -GPIO_A;
	if (check == GPIO_OUTPUT) // check if it's output 01
	{
	    uint32 *gpioOutputTypeReg = GPIO_REG(GPIOx_ODR, gpioAddresses[portId]);
	    *gpioOutputTypeReg &= ~(0x1 << PinNum);
	    *gpioOutputTypeReg |= (Data << PinNum);
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
    uint32 *gpioInputTypeReg = GPIO_REG(GPIOx_IDR, gpioAddresses[portId]);
    uint8 data = (*gpioInputTypeReg >> PinNum) & 0x01;
	return data;
}
