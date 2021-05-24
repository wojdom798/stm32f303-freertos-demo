#ifndef _MAIN_H
#define _MAIN_H

#include <stdint.h>
#include "stm32f303xe.h"

// Nucleo Board User LED and Button
#define NUCLEO_LED_GPIO (GPIOA)
#define NUCLEO_LED_PIN (5)
#define NUCLEO_LED_TOGGLE (NUCLEO_LED_GPIO->ODR ^= (1 << NUCLEO_LED_PIN))

#define NUCLEO_BUTTON_GPIO (GPIOC)
#define NUCLEO_BUTTON_PIN (13)



#define LED1_GPIO_RCC_EN RCC_AHBENR_GPIOBEN
#define LED1_GPIO GPIOB
#define LED1_PIN 3
#define LED1_TOGGLE (LED1_GPIO->ODR ^= (1 << LED1_PIN))

#define LED2_GPIO_RCC_EN RCC_AHBENR_GPIOBEN
#define LED2_GPIO GPIOB
#define LED2_PIN 5
#define LED2_TOGGLE (LED2_GPIO->ODR ^= (1 << LED2_PIN))


// Function Prototypes
void setupHardware(void);

#endif
