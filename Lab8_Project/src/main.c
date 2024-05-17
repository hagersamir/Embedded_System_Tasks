#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"
#include "EXTI.h"

volatile uint32 counter = 0;
volatile uint32 interrupt_flag = 0;

void Display_7segment(uint16);
void INC(void);
void DEC(void);

void Init(void)
{
	// 7segment
	for (uint32 i = 0; i < 7; i++)
	{
		Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	}
	Gpio_ConfigPin(GPIO_B, 4, GPIO_INPUT, GPIO_PULL_UP);
	Gpio_ConfigPin(GPIO_A, 9, GPIO_INPUT, GPIO_PULL_UP);
}
void Display_7segment(uint16 counter)
{
	// Turn off all segments first
	for (uint32 i = 0; i < 7; i++)
	{
		Gpio_WritePin(GPIO_A, i, LOW);
	}

	// Set the appropriate segments for the current digit
	switch (counter)
	{
		case 0:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 4, HIGH); // e
			Gpio_WritePin(GPIO_A, 5, HIGH); // f
			break;
		case 1:
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			break;
		case 2:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 4, HIGH); // e
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
			break;
		case 3:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
			break;
		case 4:
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 5, HIGH); // f
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
			break;
		case 5:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 5, HIGH); // f
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
			break;
		case 6:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 4, HIGH); // e
			Gpio_WritePin(GPIO_A, 5, HIGH); // f
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
			break;
		case 7:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			break;
		case 8:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 4, HIGH); // e
			Gpio_WritePin(GPIO_A, 5, HIGH); // f
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
			break;
		case 9:
			Gpio_WritePin(GPIO_A, 0, HIGH); // a
			Gpio_WritePin(GPIO_A, 1, HIGH); // b
			Gpio_WritePin(GPIO_A, 2, HIGH); // c
			Gpio_WritePin(GPIO_A, 3, HIGH); // d
			Gpio_WritePin(GPIO_A, 5, HIGH); // f
			Gpio_WritePin(GPIO_A, 6, HIGH); // g
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
	Rcc_Enable(RCC_SYSCFG);
	// Initialize EXTI for push buttons
	Exti_Init(INC_PORT, INC_PIN, FALLING_EDGE);
	Exti_Init(DEC_PORT, DEC_PIN, FALLING_EDGE);
	Exti_Enable(DEC_PIN);
	Exti_Enable(INC_PIN);
	// Nvic_EnableInterrupt(10);
	// Nvic_EnableInterrupt(15);
	Init();
	while (1)
	{
		// Display_7segment(counter);
		// 	for (volatile unsigned long i = 0; i < 1000000; i++)
		// 	{
		// 	}
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
	interrupt_flag = 1; // Set flag to update display
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
	interrupt_flag = 1; // Set flag to update display
}

void EXTI0_IRQHandler(void)
{
	
	if ((EXTI->PR)& (1<< INC_PIN))
	{
		INC();
		if (interrupt_flag)
		{
			Display_7segment(counter);
			for (volatile unsigned long i = 0; i < 1000000; i++)
			{
			}
			interrupt_flag = 0; // Reset the flag
		}
		// clear pending flag for pin A9
		SET_BIT(EXTI->PR, INC_PIN);
	}
	
}

void EXTI1_IRQHandler(void)
{
	if ((EXTI->PR)& (1<< DEC_PIN)){
		DEC();
		if (interrupt_flag)
		{
			Display_7segment(counter);
			for (volatile unsigned long i = 0; i < 1000000; i++)
			{
			}
			interrupt_flag = 0; // Reset the flag
		}
		// clear pending flag for pin B4
		SET_BIT(EXTI->PR, DEC_PIN);
	}
}
