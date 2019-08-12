#include "main.h"
#include "nvic.h"

void EXTI15_10_IRQHandler(void) {
    if (EXTI->PR & (1 << PC13)) {
        EXTI->PR |= (1 << PC13);
        led_on = !led_on;
    }
}
