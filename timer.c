#include "clock.h"

void initTIM(void) {
    FLASH->ACR |= 0x7; // enable 7 wait states FLASH latency
    FLASH->ACR |= FLASH_ACR_PRFTEN; // enable prefetch buffer
 
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLSRC_HSI); // set PLL source to HSI
    RCC->PLLCFGR |= 0x10U; // sets PLLM to 0x10 = 16
    RCC->PLLCFGR |= (0xC0UL << 6U); // sets PLLN to 192
    RCC->PLLCFGR &= ~(0x1UL << 16U); // sets PLLP[1:0] to 00; div by 2

    RCC->CR |= RCC_PLLON; // activate PLL
    while (!(RCC->CR & RC_CR_PLLRDY)) {}; // wait until it's ready
    RCC->CFGR &= ~(RCC_CFGR_SW); // validate reset value
    RCC->CFGR |= RCC_CFGR_SW_PLL; // set system clock to PLL
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {}; // Wait until ready

    core_clock_hz = 96000000; // clock freq = 96 MHz after above

}
