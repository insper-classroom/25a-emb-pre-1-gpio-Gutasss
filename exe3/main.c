#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_VERDE = 26;
const int BTN_VERMELHO = 28;
const int LED_VERMELHO = 4;
const int LED_VERDE = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_VERDE);
  gpio_init(BTN_VERMELHO);
  gpio_init(LED_VERMELHO);
  gpio_init(LED_VERDE);

  gpio_set_dir(BTN_VERDE, GPIO_IN);
  gpio_set_dir(BTN_VERMELHO, GPIO_IN);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT);
  gpio_set_dir(LED_VERDE, GPIO_OUT);

  gpio_pull_up(BTN_VERDE);
  gpio_pull_up(BTN_VERMELHO);

  int vermelho = 0;
  int verde = 0;

  while (true) {
    if (!gpio_get(BTN_VERDE)) {
      if (verde == 0) {
        gpio_put(LED_VERDE, 1);
        verde += 1;
      } else if (verde == 1) {
        gpio_put(LED_VERDE, 0);
        verde -= 1;
      }
      while (!gpio_get(BTN_VERDE)) { 
        sleep_ms(10);
      }
    }

    if (!gpio_get(BTN_VERMELHO)) {
      if (vermelho == 0) {
        gpio_put(LED_VERMELHO, 1);
        vermelho += 1;
      } else if (vermelho == 1) {
        gpio_put(LED_VERMELHO, 0);
        vermelho -= 1;
      }
      while (!gpio_get(BTN_VERMELHO)) { 
        sleep_ms(10);
      }
    }
  }
}
