#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const BTN = 28;
const LED_V = 5;
const LED_R = 8;
const LED_A = 11;
const LED_Am = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN);
  gpio_init(LED_V);
  gpio_init(LED_R);
  gpio_init(LED_A);
  gpio_init(LED_Am);

  gpio_set_dir(BTN, GPIO_IN);
  gpio_set_dir(LED_V, GPIO_OUT);
  gpio_set_dir(LED_R, GPIO_OUT);
  gpio_set_dir(LED_A, GPIO_OUT);
  gpio_set_dir(LED_Am, GPIO_OUT);

  gpio_pull_up(BTN);  

  while (true) {
    if (!gpio_get(BTN)) {
      gpio_put(LED_V, 1);
      sleep_ms(300);

      gpio_put(LED_V, 0);
      gpio_put(LED_R, 1);
      sleep_ms(300);

      gpio_put(LED_R, 0);
      gpio_put(LED_A, 1);
      sleep_ms(300);

      gpio_put(LED_A, 0);
      gpio_put(LED_Am, 1);
      sleep_ms(300);

      gpio_put(LED_Am, 0);

      while (!gpio_get(BTN)) {
      };
    }
  }
}