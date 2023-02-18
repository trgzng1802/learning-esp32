#include "button.h"
#include "output.c"
#include "input.c"

uint8_t current_state = 0;
uint8_t pre_state = 0;
uint8_t debouncing_state = 0;
uint8_t is_debouncing = 0;
int64_t debouncing_time = 0;

button_callback_t button_callback = NULL;

void button_handle(gpio_num_t gpio_num, void* button_event_callback)
{
    uint8_t temp_state = gpio_get_level(gpio_num);
    if (temp_state != debouncing_state)
    {
        debouncing_state = temp_state;
        debouncing_time = esp_timer_get_time();
        is_debouncing = 1;
    }

    if ((is_debouncing == 1) && (esp_timer_get_time()- debouncing_time) > 15)
    {
        current_state = debouncing_state;
        is_debouncing = 0;
    }

    if (current_state != pre_state)
    {
        button_callback = button_event_callback;
    }

}