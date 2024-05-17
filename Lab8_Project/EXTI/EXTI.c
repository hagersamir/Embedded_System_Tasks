#include "EXTI.h"
#include "Gpio.h"

void Exti_Init(uint8 PortName, uint8 PinNum, uint8 mode)
{
    uint16 portNo;
    switch (PortName)
    {
    case GPIO_A:
        portNo = 0000;
        break;
    case GPIO_B:
        portNo = 0001;
        break;
    case GPIO_C:
        portNo = 0010;
        break;
    case GPIO_D:
        portNo = 0011;
        break;
    default:
        break;
    }
    if (PinNum < 4)
    {
        SYSCFG->EXTICR1 &= ~(0xf << (PinNum * 4));
        SYSCFG->EXTICR1 |= (portNo << (PinNum * 4));
    }
    else if (PinNum < 8)
    {
        SYSCFG->EXTICR2 &= ~(0xf << ((PinNum - 4) * 4));
        SYSCFG->EXTICR2 |= (portNo << ((PinNum - 4) * 4));
    }
    else if (PinNum < 12)
    {
        SYSCFG->EXTICR3 &= ~(0xf << ((PinNum - 8) * 4));
        SYSCFG->EXTICR3 |= (portNo << ((PinNum - 8) * 4));
    }
    else if (PinNum < 16)
    {
        SYSCFG->EXTICR4 &= ~(0xf << ((PinNum - 12) * 4));
        SYSCFG->EXTICR4 |= (portNo << ((PinNum - 12) * 4));
    }
    SET_BIT(mode, PinNum); // enable edge detection for selected line
}

void Exti_Enable(uint8 line)
{
    SET_BIT(EXTI->IMR, line);
    Nvic_EnableInterrupt(line + 6);
}

void Exti_Disable(uint8 line)
{
    CLEAR_BIT(EXTI->IMR, line);
    Nvic_DisableInterrupt(line + 6);
}
