#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

void app_main(void)
{
    while (1) {
        ESP_LOGI("HELLO", "Hello from ESP32 + Docker!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
