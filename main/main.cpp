#include <iostream>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

class LEDController {
private:
    gpio_num_t ledPin;

public:
    // Constructor to initialize the LED pin
    explicit LEDController(gpio_num_t pin) : ledPin(pin) {
        gpio_reset_pin(ledPin);
        gpio_set_direction(ledPin, GPIO_MODE_OUTPUT);
    }

    // Method to turn the LED on
    void turnOn() const {
        gpio_set_level(ledPin, true);
    }

    // Method to turn the LED off
    void turnOff() const {
        gpio_set_level(ledPin, false);
    }
};

extern "C" void app_main(void) {
    LEDController ledController(GPIO_NUM_2);

    while (true) {
        ledController.turnOn();
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1000 ms
        ledController.turnOff();
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1000 ms
    }
}
