#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "input.h"
#include "output.h"

#define BLINK_GPIO GPIO_NUM_13
#define BUTTON_PIN GPIO_NUM_23


void input_gpio_event_callback(int pin)
{
    if (pin == BUTTON_PIN)
    {
        static uint32_t x = 0;
        output_gpio_set_level(BLINK_GPIO, x);
        // if (x) printf("Turn off the LED!\n");
        // else printf("Turn on the LED!\n");
        x = 1 - x;
    }
}

void app_main(void)
{
    //config output
    output_gpio_create(BLINK_GPIO,GPIO_PULLUP_DISABLE, GPIO_PULLDOWN_DISABLE);
    //config input
    input_gpio_create(GPIO_NUM_23, GPIO_INTR_POSEDGE, GPIO_PULLUP_DISABLE, GPIO_PULLDOWN_ENABLE);
    input_gpio_set_callback(input_gpio_event_callback);
    // while(1) gpio_set_level(BLINK_GPIO, 1 - gpio_get_level(BUTTON_PIN));
    
}