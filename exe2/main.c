#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN1 = 26;
const int BTN_PIN2 = 7;


int main() {
  stdio_init_all();

  gpio_init(BTN_PIN1);
  gpio_init(BTN_PIN2);

  gpio_set_dir(BTN_PIN1, GPIO_IN);
  gpio_set_dir(BTN_PIN2, GPIO_IN);

  gpio_pull_up(BTN_PIN1);
  gpio_pull_up(BTN_PIN2);


  while (true) {
    if (!gpio_get(BTN_PIN1)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN1)) {
      };
    }
    else if (!gpio_get(BTN_PIN2)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PIN2)) {
      };
    }
  }
}
