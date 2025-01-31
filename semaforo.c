#include "pico/stdlib.h"
#include <stdio.h>

// Definições dos pinos dos LEDs RGB
#define GREEN_LED_PIN 11
#define YELLOW_LED_PIN 12
#define RED_LED_PIN 13

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} traffic_light_state_t;

traffic_light_state_t current_state = RED;

// Função de callback do temporizador
bool timer_callback(struct repeating_timer *t) {
    switch (current_state) {
        case RED:
            gpio_put(RED_LED_PIN, 1);
            gpio_put(GREEN_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 0);
            current_state = GREEN;
            break;
        case GREEN:
            gpio_put(RED_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 1);
            gpio_put(YELLOW_LED_PIN, 0);
            current_state = YELLOW;
            break;
        case YELLOW:
            gpio_put(RED_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 1);
            current_state = RED;
            break;
    }
    return true; // Continue chamando o callback
}

int main() {
    // Inicializa a porta serial
    stdio_init_all();

    // Inicializa os pinos dos LEDs
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);

    // Inicializa o estado inicial do semáforo
    gpio_put(RED_LED_PIN, 1);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(YELLOW_LED_PIN, 0);

    // Configura o temporizador
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        printf("Semaforo funcionando...\n");
        sleep_ms(1000); // Espera 1 segundo
    }

    return 0;
}