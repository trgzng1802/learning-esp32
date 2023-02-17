#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "input.h"

#define BLINK_GPIO GPIO_NUM_13
#define BUTTON_PIN GPIO_NUM_23

uint8_t currentState, preStatus;
bool isPressing;

void input_gpio_event_callback(int pin)
{
    if (pin == BUTTON_PIN)
    {
        static int x = 0;
        gpio_set_level(BLINK_GPIO, x);
        // if (x) printf("Turn off the LED!\n");
        // else printf("Turn on the LED!\n");
        x = 1 - x;
    }
}


void app_main(void)
{
    //config output
    gpio_config_t GPIO_config;
    GPIO_config.pin_bit_mask = (1<<GPIO_NUM_13);
    GPIO_config.mode = GPIO_MODE_OUTPUT;
    GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;
    GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    GPIO_config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&GPIO_config);

    //config input
    input_gpio_create(GPIO_NUM_23, GPIO_INTR_POSEDGE, GPIO_PULLUP_DISABLE, GPIO_PULLDOWN_ENABLE);
    input_gpio_set_callback(input_gpio_event_callback);
    // while(1) gpio_set_level(BLINK_GPIO, 1 - gpio_get_level(BUTTON_PIN));
    
}