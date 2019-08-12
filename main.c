/* Main program. */

#include "main.h"

int main(void) {

    led_on = 0; // initialize global defined in global.h; LED off 

    FLASH->ACR |= 0x7; // enable 7 wait states FLASH latency
    FLASH->ACR |= FLASH_ACR_PRFTEN; // enable prefetch buffer



    while (1) {
    }
}
