/**
 ******************************************************************************
 * @file           : main.c
 * @author         : paco
 * @brief          : Main program body
 ******************************************************************************
 *
 ******************************************************************************
 */

#include "stm32f1xx.h"

int main(void)
{
	uint32_t i;

	RCC->CR |= RCC_CR_HSION;
	RCC->CFGR |= RCC_CFGR_MCOSEL_SYSCLK | RCC_CFGR_SW_HSI;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->ODR &= ~GPIO_ODR_ODR13;

	GPIOC->CRH |= GPIO_CRH_MODE13_1;

	/* Loop forever */
	for(;;)
	{
		for(i = 0x000F0000UL; i > 0; i--);
		GPIOC->ODR ^= GPIO_ODR_ODR13;
	}
	return 0;
}
