#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>
#include "esp_err.h"
#include "hal/gpio_types.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_timer.h"

typedef void (*button_callback_t) button_set_callback(int);
void button_handle(gpio_num_t gpio_num, void* button_event_callback);

#endif
