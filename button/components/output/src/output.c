#include "output.h"


void output_gpio_create(gpio_num_t gpio_num, gpio_pullup_t pull_up_mode, gpio_pulldown_t pull_down_mode)
{
    gpio_config_t GPIO_config;
    GPIO_config.pin_bit_mask = (1<<gpio_num);
    GPIO_config.mode = GPIO_MODE_OUTPUT;
    GPIO_config.pull_up_en = pull_up_mode;
    GPIO_config.pull_down_en = pull_down_mode;
    GPIO_config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&GPIO_config);
}

int output_gpio_set_level(gpio_num_t gpio_num,  uint32_t level)
{
    return gpio_set_level(gpio_num, level);
}
