#include "led.h"



void led_init(void)
{
     gpio_config_t io_conf = {};
     io_conf.intr_type = GPIO_INTR_DISABLE;
     io_conf.mode = GPIO_MODE_OUTPUT;
     io_conf.pin_bit_mask = 1ULL << LED_GPIO_PIN;
     io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
     io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
     gpio_config(&io_conf);
}

void led_open(void)
{
    gpio_set_level(LED_GPIO_PIN, 1);
    // printf("led on\n");
}

void led_close(void)
{
    gpio_set_level(LED_GPIO_PIN, 0);
    // printf("led off\n");
}
