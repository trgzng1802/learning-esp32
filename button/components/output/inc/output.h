#ifndef OUTPUT_IO_H
#define OUTPUT_IO_H

#include <stdio.h>
#include "esp_err.h"
#include "hal/gpio_types.h"
#include "esp_log.h"
#include "driver/gpio.h"


void output_gpio_create(gpio_num_t gpio_num, gpio_pullup_t pull_up_mode, gpio_pulldown_t pull_down_mode);
int output_gpio_set_level(gpio_num_t gpio_num,  uint32_t level);

#endif
