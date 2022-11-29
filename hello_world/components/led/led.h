#ifndef __LED_H
#define __LED_H

#include <stdio.h>
#include "driver/gpio.h"
#include "sdkconfig.h"

#define LED_GPIO_PIN 2

void led_init(void);
void led_open(void);
void led_close(void);

#endif
