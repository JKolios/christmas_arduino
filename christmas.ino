#include "sine_fade.h"
#include "even_odd.h"
#include "binary_count.h"


void (*effects[3]) (int*, int*) = {&sine_fade, &binary_count, &even_odd};
volatile int effect_index;

void setup() {
  // put your setup code here, to run once:
 
 Serial.begin(9600);
 randomSeed(analogRead(0));
 pinMode(2, INPUT_PULLUP);
 attachInterrupt(0, next_effect, FALLING);
 effect_index = 0;
}

void loop() {
  display_effect(effect_index);  
}

void next_effect()
  {
    if (effect_index == 2){
      effect_index = 0;
    }else{
      effect_index++;
    }
  }


void display_effect(int effect) {
  // put your main code here, to run repeatedly:
  
  int led_values[6];
  int tick_delay;
  
  effects[effect_index](led_values, &tick_delay);
  
  write_led_values(led_values);  
  delay(tick_delay);
}

void write_led_values(int *led_values){
 analogWrite(3, led_values[0]);
 analogWrite(5, led_values[1]);
 analogWrite(6, led_values[2]);
 analogWrite(9, led_values[3]);
 analogWrite(10, led_values[4]);
 analogWrite(11, led_values[5]);
}

  


