#include "Arduino.h"

int oscillator(float counter, int range, float phase_shift){
  return range - ((range + sin(counter + phase_shift) * range) / 2);
}

int* phased_led_values(int* led_values, float period_counter, int range, const float* phase_shifts){  
  for(int i=0;i<6;i++) {
    led_values[i] = oscillator(period_counter, range, phase_shifts[i]);
   }
   return led_values;
}

int* multiperiod_led_values(int* led_values, const float* period_counters, int range){  
  for(int i=0;i<6;i++) {
    led_values[i] = oscillator(period_counters[i], range, 0);
   }
   return led_values;
}
