#include "input.h"

input_gpio_callback_t input_gpio_callback = NULL;

static void input_gpio_handle(void* arg)
{
    int gpio_num = (uint32_t) arg;
    input_gpio_callback(gpio_num);
}

void input_gpio_create(gpio_num_t gpio_num, gpio_int_type_t type_edge_it, gpio_pullup_t pull_up_mode, gpio_pulldown_t pull_down_mode)
{
    gpio_config_t GPIO_config;
    GPIO_config.pin_bit_mask = (1<<gpio_num);
    GPIO_config.mode = GPIO_MODE_INPUT;
    GPIO_config.pull_up_en = pull_up_mode;
    GPIO_config.pull_down_en = pull_down_mode;
    GPIO_config.intr_type = type_edge_it;
    gpio_install_isr_service(0);
    gpio_isr_handler_add(gpio_num, input_gpio_handle, (void*) gpio_num);
    gpio_config(&GPIO_config);
}

int input_gpio_get_level(gpio_num_t gpio_num)
{
    return gpio_get_level(gpio_num);
}

void input_gpio_set_callback(void *callback)
{
    input_gpio_callback = callback; 
}