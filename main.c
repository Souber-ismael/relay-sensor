#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define RELAY_GPIO        GPIO_NUM_18   
#define RELAY_ACTIVE_LOW  0             

static const char *TAG = "RELAY";

static inline void relay_set(bool on) {
    int level = (on ? 1 : 0) ^ (RELAY_ACTIVE_LOW ? 1 : 0); // ici RELAY_ACTIVE_LOW=0 -> ON=HIGH
    gpio_set_level(RELAY_GPIO, level);
}

void app_main(void) {
    gpio_config_t io = {
        .pin_bit_mask = (1ULL << RELAY_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io);
    
    // Sécuriser: relais OFF au démarrage
    relay_set(false);

    // Démo : ON 	10 s, OFF 10 s
    while (1) {
        relay_set(true);
        ESP_LOGI(TAG, "Relay ON (contact COM-NO ferme)");
        vTaskDelay(pdMS_TO_TICKS(10000));

        relay_set(false);
        ESP_LOGI(TAG, "Relay OFF (contact COM-NO ouvert)");
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
