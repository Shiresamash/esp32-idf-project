#ifndef __u8g2_ssd1306_hal_h_
#define __u8g2_ssd1306_hal_h_
#include "u8g2.h"
#include "u8x8.h"



uint8_t u8g2_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr);
uint8_t u8g2_i2c_byte_cb(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
void u8G2Init(u8g2_t *u8g2);








#endif
