#ifndef INPUT_IO_H
#define INPUT_IO_H

#include <stdio.h>
#include "esp_err.h"
#include "hal/gpio_types.h"
#include "esp_log.h"
#include "driver/gpio.h"

typedef void (*input_gpio_callback_t) (int);

void input_gpio_create(gpio_num_t gpio_num, gpio_int_type_t type_edge_it, gpio_pullup_t pull_up_mode, gpio_pulldown_t pull_down_mode);
int input_gpio_get_level(gpio_num_t gpio_num);
void input_gpio_set_callback(void *callback);

#endif
