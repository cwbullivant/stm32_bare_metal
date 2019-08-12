#ifndef _VVC_MAIN_H
#define _VVC_MAIN_H

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f446xx.h"
#include "nvic.h"
#include "timer.h"

#define PA5 (5)
#define PC13 (13)

volatile uint8_t led_on;
volatile uint32_t core_clock_hz;

#endif
