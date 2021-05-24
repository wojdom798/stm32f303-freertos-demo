#include "main.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"


static void led1_task(void *args) {
  int delay_ms = *(int*) args;
  while (1) {
    LED1_TOGGLE;
    vTaskDelay(pdMS_TO_TICKS(delay_ms));
  }
}

static void led2_task(void *args) {
  int delay_ms = *(int*) args;
  delay_ms = 2000;
  while (1) {
    LED2_TOGGLE;
    vTaskDelay(pdMS_TO_TICKS(delay_ms));
  }
}


// Global Variables
uint32_t core_clock_hz;
uint32_t SystemCoreClock;

volatile uint32_t sysTickCounter;


int main(void) {

	sysTickCounter = 0;
  setupHardware();

  xTaskCreate(led1_task, "LED_blink_1", 128, NULL, configMAX_PRIORITIES-1, NULL);
  xTaskCreate(led1_task, "LED_blink_2", 128, NULL, configMAX_PRIORITIES-1, NULL);

//  for (uint32_t i = 0; i < 20; i++) {
//	  LED1_TOGGLE;
//	  for (uint32_t j = 0; j < 200000UL; j++) continue;
//	  LED1_TOGGLE;
//	  for (uint32_t j = 0; j < 200000UL; j++) continue;
//  }

  vTaskStartScheduler();

  while (1) {}

  return 0;
}


void setupHardware(void) {
  // Flash Memory Latency Setting (needs to be set for clock frequency greater than 24 MHz; stm32f3 reference manual pg. 78)
  FLASH->ACR &= ~(0x1F); // reset all bits in the FLASH_ACR register to 0
  // FLASH_ACR_LATENCY_2 form stm32f303xe.h doesn't quite match with the datasheet's values
  FLASH->ACR |= (FLASH_ACR_LATENCY_2 | FLASH_ACR_PRFTBE);
  
  // Setup PLL
  RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL); // reset PLL source and multiplication bits
  // set PLL to HSI / PREDIV (PREDIV -> HCLK not divided); multiply 8 MHz HSI times 9 = 72 MHz
  RCC->CFGR |= (RCC_CFGR_PLLSRC_HSI_PREDIV | RCC_CFGR_PLLMUL9);
  // turn the PLL on
  RCC->CR |= (RCC_CR_PLLON);
  // wait for PLL to turn on
  while (!(RCC->CR & RCC_CR_PLLRDY)) continue;
  // select PLL as system clock source
  RCC->CFGR &= ~(RCC_CFGR_SW);
  RCC->CFGR |= (RCC_CFGR_SW_PLL);
  // wait for the setting to settle
  while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) continue;

  SystemCoreClock = core_clock_hz = 72000000UL;


  // Nucleo Board LED GPIO setup
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // IOP(A)EN
  NUCLEO_LED_GPIO->MODER &= ~(0x3 << (NUCLEO_LED_PIN * 2));
  NUCLEO_LED_GPIO->MODER |= (0x1 << (NUCLEO_LED_PIN * 2)); // general purpose output mode
  NUCLEO_LED_GPIO->OTYPER &= ~(1 << NUCLEO_LED_PIN); // output push-pull
  NUCLEO_LED_GPIO->OSPEEDR &= ~(0x3 << (NUCLEO_LED_PIN * 2)); // low speed
  NUCLEO_LED_GPIO->PUPDR &= ~(0x3 << (NUCLEO_LED_PIN * 2)); // no pull-up, no pull-down

  // LED 1 setup
  RCC->AHBENR |= LED1_GPIO_RCC_EN;
  LED1_GPIO->MODER &= ~(0x3 << (LED1_PIN * 2));
  LED1_GPIO->MODER |= (0x1 << (LED1_PIN * 2)); // general purpose output mode
  LED1_GPIO->OTYPER &= ~(1 << LED1_PIN); // output push-pull
  LED1_GPIO->OSPEEDR &= ~(0x3 << (LED1_PIN * 2)); // low speed
  LED1_GPIO->PUPDR &= ~(0x3 << (LED1_PIN * 2)); // no pull-up, no pull-down

  // LED 2 setup
  RCC->AHBENR |= LED2_GPIO_RCC_EN;
  LED2_GPIO->MODER &= ~(0x3 << (LED2_PIN * 2));
  LED2_GPIO->MODER |= (0x1 << (LED2_PIN * 2)); // general purpose output mode
  LED2_GPIO->OTYPER &= ~(1 << LED2_PIN); // output push-pull
  LED2_GPIO->OSPEEDR &= ~(0x3 << (LED2_PIN * 2)); // low speed
  LED2_GPIO->PUPDR &= ~(0x3 << (LED2_PIN * 2)); // no pull-up, no pull-down

  SysTick_Config(72000000/72000);
}

void SysTick_Handler(void) {
	sysTickCounter++;
	if (sysTickCounter == 100000)
	{
		NUCLEO_LED_TOGGLE;
		sysTickCounter = 0;
	}
}
