#include <stdio.h>
#include "pico/stdlib.h"

const uint led_pin_red = 13;
const uint led_pin_green = 11;
const uint led_pin_blue = 12; 

const uint btn_pin_a = 5;      
const uint btn_pin_b = 6;

void setup_gpio(uint pin, bool is_output);
void set_leds(bool red, bool green, bool blue);
void initialize_pins();
int check_buttons();

int main() 
{   
   initialize_pins();

   while (true) {
      int button_state = check_buttons();
      switch (button_state) {
        case 0b11:
            set_leds(1, 1, 1);
            break;
        case 0b01:
            set_leds(1, 0, 0); 
            break;
        case 0b10:
            set_leds(0, 1, 0); 
            break;
        case 0b00:
            set_leds(0, 0, 1); 
            break;
        }
      sleep_ms(100);
    }
   
}

void initialize_pins() {
    setup_gpio(led_pin_red, true);
    setup_gpio(led_pin_green, true);
    setup_gpio(led_pin_blue, true);
    setup_gpio(btn_pin_a, false);
    setup_gpio(btn_pin_b, false);    
}

void setup_gpio(uint pin, bool is_output) {
    gpio_init(pin);
    gpio_set_dir(pin, is_output ? GPIO_OUT : GPIO_IN);
    
    if (!is_output) {
        gpio_pull_up(pin);  
    }
}

void set_leds(bool red, bool green, bool blue) {
    gpio_put(led_pin_red, red);
    gpio_put(led_pin_green, green);
    gpio_put(led_pin_blue, blue);    
};


int check_buttons() {
    return (!gpio_get(btn_pin_a) << 0) | (!gpio_get(btn_pin_b) << 1);
}



