#ifndef INPUT_IO_H
#define INPUT_IO_H

#include <stdio.h>
#include "esp_err.h"
#include "hal/gpio_types.h"
#include "esp_log.h"
#include "driver/gpio.h"

typedef enum {
    POS_EDGE = 0,
    NEG_EDGE,
    ANY_EDGE
} it_type_edge_t;

typedef void (*input_gpio_callback_t) (int);

void input_gpio_create(gpio_num_t gpio_num, it_type_edge_t type_edge_it);
void input_gpio_get_level(gpio_num_t gpio_num);
void input_gpio_it_callback(void *callback);

#endif
