#include "input.h"

input_gpio_callback_t input_gpio_callback = NULL;

static void input_gpio_handle(void* arg)
{
    int gpio_num = (uint32_t) arg;
    input_gpio_callback(gpio_num);
}

void input_gpio_create(gpio_num_t gpio_num, gpio_int_type_t type_edge_it)
{
    gpio_config_t GPIO_config;
    GPIO_config.pin_bit_mask = (1<<gpio_num);
    GPIO_config.mode = GPIO_MODE_INPUT;
    GPIO_config.pull_up_en = GPIO_PULLUP_DISABLE;
    GPIO_config.pull_down_en = GPIO_PULLDOWN_ENABLE;
    GPIO_config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&GPIO_config);
}

int input_gpio_get_level(gpio_num_t gpio_num)
{
    return gpio_get_level(gpio_num);
}

void input_gpio_it_callback(void *callback)
{
    input_gpio_callback = callback; 
}