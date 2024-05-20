#include "EXTI.h"
#include "Gpio.h"

void Exti_Init(uint8 PortName, uint8 PinNum, uint8 mode)
{
    SET_BIT(mode, PinNum); // enable edge detection for selected line

    uint8 portNo;
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
//    portNo = PortName - GPIO_A;

    uint8 register_index = PinNum / NUM_OF_BITS_PER_PIN;
    uint8 bit_offset = PinNum % NUM_OF_BITS_PER_PIN;
    *SYSCFG_EXTICR[register_index] &= ~(0xF << bit_offset * 4);
    *SYSCFG_EXTICR[register_index] |= (portNo << bit_offset * 4);


//    if (PinNum < 4)
//    {
//        SYSCFG->EXTICR1 &= ~(0xf << (PinNum * 4));
//        SYSCFG->EXTICR1 |= (portNo << (PinNum * 4));
//    }
//    else if (PinNum < 8) // 7
//    {
//        SYSCFG->EXTICR2 &= ~(0xf << ((PinNum - 4) * 4)); // 3 * 4 == 12
//        SYSCFG->EXTICR2 |= (portNo << ((PinNum - 4) * 4));
//    }
//    else if (PinNum < 12) // 11
//    {
//        SYSCFG->EXTICR3 &= ~(0xf << ((PinNum - 8) * 4)); // (11 - 8) * 4 ==
//        SYSCFG->EXTICR3 |= (portNo << ((PinNum - 8) * 4));
//    }
//    else if (PinNum < 16)
//    {
//        SYSCFG->EXTICR4 &= ~(0xf << ((PinNum - 12) * 4));
//        SYSCFG->EXTICR4 |= (portNo << ((PinNum - 12) * 4));
//    }
}

void Exti_Enable(uint8 line)
{
    SET_BIT(EXTI->IMR, line);
}

void Exti_Disable(uint8 line)
{
    CLEAR_BIT(EXTI->IMR, line);
}
