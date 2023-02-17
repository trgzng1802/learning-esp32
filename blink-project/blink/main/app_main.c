/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "input_iot.h"

#define BLINK_GPIO CONFIG_BLINK_GPIO

void input_gpio_event_callback(int pin)
{
    if (pin == GPIO_NUM_0)
    {
        static int x = 0;
        gpio_set_level(BLINK_GPIO, x);
        x = 1 - x;  
    }
}

void app_main(void)
{
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    input_gpio_create(GPIO_NUM_0, NEG_EDGE);
    input_gpio_it_callback(input_gpio_event_callback);
}
