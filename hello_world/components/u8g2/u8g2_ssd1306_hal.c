#include <stdio.h>
#include "driver/i2c.h"
#include "u8g2_ssd1306_hal.h"


static i2c_cmd_handle_t handle_i2c;


uint8_t u8g2_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr)
{
    return 1;//no use in hw i2c
}

uint8_t u8g2_i2c_byte_cb(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    switch (msg)
    {
        case U8X8_MSG_BYTE_SET_DC:
        case U8X8_MSG_BYTE_INIT:
        break;
        case U8X8_MSG_BYTE_SEND:
        {
            // arg_ptr 是要发送的数据（uint8_t[]）
            // arg_int 是数据的长度
            uint8_t *data_ptr = (uint8_t *)arg_ptr;
            while (arg_int > 0)
            {
                ESP_ERROR_CHECK(i2c_master_write_byte(handle_i2c, *data_ptr, 1));
                data_ptr++;
                arg_int--;
            }
            break;
        }

        case U8X8_MSG_BYTE_START_TRANSFER:
        {
            uint8_t i2c_address = u8x8_GetI2CAddress(u8x8);
            handle_i2c = i2c_cmd_link_create();
            ESP_ERROR_CHECK(i2c_master_start(handle_i2c));
            ESP_ERROR_CHECK(i2c_master_write_byte(handle_i2c, i2c_address | I2C_MASTER_WRITE, 1));
            break;
        }

        case U8X8_MSG_BYTE_END_TRANSFER:
        {
            ESP_ERROR_CHECK(i2c_master_stop(handle_i2c));
            ESP_ERROR_CHECK(i2c_master_cmd_begin(0, handle_i2c, 10 / portTICK_RATE_MS));
            i2c_cmd_link_delete(handle_i2c);
            break;
        }

        default:
        break;
    }
    return 0;
}

void u8G2Init(u8g2_t *u8g2)
{
    u8g2_Setup_ssd1306_i2c_128x64_noname_f(u8g2,U8G2_R0,u8g2_i2c_byte_cb,u8g2_gpio_and_delay);
    // u8g2_SetI2CAddress(&u8g2, 0x78);
    u8g2_InitDisplay(u8g2);
    u8g2_SetPowerSave(u8g2, 0);
    u8g2_ClearBuffer(u8g2);
}









