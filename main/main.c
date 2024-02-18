#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/task.h>>

#define LED_PIN GPIO_NUM_27
#define BUTTON_PUSH_PIN GPIO_NUM_33

void app_main(void)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_PUSH_PIN, GPIO_MODE_INPUT);

    while(1)
    {
        if (gpio_get_level(BUTTON_PUSH_PIN) == 1)
        {
            gpio_set_level(LED_PIN, 1);
        }
        else
        {
            gpio_set_level(LED_PIN, 0);
        }

        vTaskDelay(1);
    }
}
