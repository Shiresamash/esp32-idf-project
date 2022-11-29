/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "led.h"
#include "chipinfo.h"
#include "ssd1306.h"
#include "u8g2.h"
#include "u8x8.h"
#include "u8g2_ui_test.h"
#include "u8g2_ssd1306_hal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "allwinner_logo.h"



TaskHandle_t taskHandle_test;
u8g2_t u8g2;

static void test_thread(void * arg)
{
    // unsigned int i = 0;
    // wifi_ap_mode_config();
    // wifi_sta_config();
    getChipInfo();
    ssd1306_init();
    u8G2Init(&u8g2);
    u8g2_DrawXBMP(&u8g2, 0, 0, 128, 64, bmpallwiner);
    u8g2_SendBuffer(&u8g2);
    led_init();
    vTaskDelay(100);
    // time_thread_init();
    // DrawLogo(&u8g2);
    // vTaskDelay(100);
    // u8g2_DrawXBMP(&u8g2, 0, 0, 128, 64, bmpallwiner);
    // u8g2_SendBuffer(&u8g2);
    // vTaskDelay(500);
    while (1)
    {
        led_open();
        vTaskDelay(100);
        led_close();
        vTaskDelay(100);
        // printf("running..\n");
    }
    
}


void app_main(void)
{

    xTaskCreate(test_thread, "show", 2048, NULL, 1, &taskHandle_test);
    // U8g2Test(&u8g2);
    vTaskDelete(NULL);
}
