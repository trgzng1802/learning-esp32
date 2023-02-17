#include "input_iot.h"

input_gpio_callback_t input_gpio_callback = NULL;

static void IRAM_ATTR input_gpio_handle(void* arg)
{
    int gpio_num = (uint32_t) arg;
    input_gpio_callback(gpio_num);
}

void input_gpio_create(gpio_num_t gpio_num, it_type_edge_t type_edge_it)
{
    gpio_pad_select_gpio(gpio_num);
    gpio_set_direction(gpio_num, GPIO_MODE_INPUT);
    gpio_set_pull_mode(gpio_num, GPIO_PULLUP_ONLY);
    gpio_set_intr_type(gpio_num, type_edge_it);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(gpio_num, input_gpio_handle, (void*) gpio_num);
}

void input_gpio_get_level(gpio_num_t gpio_num)
{
    return gpio_get_level(gpio_num);
}

void input_gpio_it_callback(void *callback)
{
    input_gpio_callback = callback; 
}