#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"
#include "EXTI.h"

#define SYSCFG_EXTICR1 (*(uint32*) (0x40013800 + 0x08))


// void EXTI9_5_IRQHandler(void);
// void EXTI4_IRQHandler(void);
// volatile uint32 interrupt_flag = 0;
volatile uint32 counter = 0;
void Display_7segment(uint32 counter);
void INC(void);
void DEC(void);

void Init(void)
{
//	 7segment
	for (uint32 i = Start_Pin_Seg; i < Start_Pin_Seg + 7; i++)
	{
		Gpio_ConfigPin(Port_Seg, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	}
	Gpio_ConfigPin(INC_PORT, INC_PIN, GPIO_INPUT, GPIO_PULL_UP);
	Gpio_ConfigPin(DEC_PORT, DEC_PIN, GPIO_INPUT, GPIO_PULL_UP);
//	Gpio_ConfigPin(GPIO_B, 1, GPIO_INPUT, GPIO_PULL_UP);
//	Gpio_ConfigPin(GPIO_A, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);
}
void Display_7segment(uint32 counter)
{
	// Turn off all segments first
	for (uint32 i = 0; i < 7; i++)
	{
		Gpio_WritePin(Port_Seg, i, LOW);
	}

	// Set the appropriate segments for the current digit
	switch (counter)
	{
	case 0:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 4, HIGH); // e
		Gpio_WritePin(Port_Seg, 5, HIGH); // f
		break;
	case 1:
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		break;
	case 2:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 4, HIGH); // e
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	case 3:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	case 4:
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 5, HIGH); // f
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	case 5:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 5, HIGH); // f
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	case 6:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 4, HIGH); // e
		Gpio_WritePin(Port_Seg, 5, HIGH); // f
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	case 7:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		break;
	case 8:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 4, HIGH); // e
		Gpio_WritePin(Port_Seg, 5, HIGH); // f
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	case 9:
		Gpio_WritePin(Port_Seg, 0, HIGH); // a
		Gpio_WritePin(Port_Seg, 1, HIGH); // b
		Gpio_WritePin(Port_Seg, 2, HIGH); // c
		Gpio_WritePin(Port_Seg, 3, HIGH); // d
		Gpio_WritePin(Port_Seg, 5, HIGH); // f
		Gpio_WritePin(Port_Seg, 6, HIGH); // g
		break;
	default:
		break;
	}
}
int main()
{
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_GPIOD);
	Rcc_Enable(RCC_SYSCFG);
	Init();
//	Exti_Init(GPIO_B, 1, FALLING_EDGE);
//	Exti_Enable(1);
//	SYSCFG_EXTICR1 &=~(0xf << (1 * 4));
//	SYSCFG_EXTICR1 |= (1 << (1 * 4));
//	EXTI->IMR |= (1 << 1);
//	Nvic_EnableInterrupt(7);
	Nvic_EnableInterrupt(10); // for decrement push button
	Nvic_EnableInterrupt(23); // for increment push button
// Initialize EXTI for push buttons
	Exti_Init(INC_PORT, INC_PIN, FALLING_EDGE);
	Exti_Init(DEC_PORT, DEC_PIN, FALLING_EDGE);

//	 Exti_Enable(INC_PIN);
//	 Exti_Enable(DEC_PIN);

	uint32 LocalCounter = 0;

	while (1)
	{

		 Exti_Disable(INC_PIN);
		 Exti_Disable(DEC_PIN);
		 LocalCounter = counter;
		 Exti_Enable(INC_PIN);
		 Exti_Enable(DEC_PIN);
		 // Delay after enabling interrupts to de-bounce buttons
		 for (volatile unsigned long i = 0; i < 100000; i++)
		 	;
		Display_7segment(counter);
		for (volatile unsigned long i = 0; i < 1000000; i++)
			;
	}

	return 0;
}
void INC(void)
{
	// Increment counter ISR using PA9
	if (counter < 9)
	{
		counter++;
	}
	else
	{
		counter = 0; // go back to 0 if counter exceeds 9
	}
}
void DEC(void)
{
	// Decrement counter ISR using PB4
	if (counter > 0)
	{
		counter--;
	}
	else
	{
		counter = 9; // go back to max value (9) if counter goes below 0
	}
}

void EXTI9_5_IRQHandler(void)
{

	INC();
	SET_BIT(EXTI->PR, INC_PIN);
}

void EXTI4_IRQHandler(void)
{

	DEC();
	SET_BIT(EXTI->PR, DEC_PIN);
}


void EXTI1_IRQHandler(void)
{
	Gpio_WritePin(GPIO_A, 0, LOW);
	for (int i = 0; i < 1000000; i++) {
	}
	Gpio_WritePin(GPIO_A, 0, HIGH);
	for (int i = 0; i < 1000000; i++) {
	}
	//clear pending flag
	SET_BIT(EXTI->PR, 1);

}
