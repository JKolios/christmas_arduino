#define MINIMUM 0
#define MAXIMUM 120
#define PERIOD 10000
#define TICK_DELAY 50

#include "Arduino.h"

int counter_increment_per_tick(int period, int tick_delay){
 return (period / tick_delay) * 2 * PI;
}

int oscillator(float counter, int range, float phase_shift){
  return range - ((range + sin(counter + phase_shift) * range) / 2);
}

void pulsed_led_values(float counter, int range, int *return_array){
  float phase_shift = 0.0;
  for(int i=0;i<6;i++) {
    return_array[i] = oscillator(counter, range, phase_shift);
    phase_shift += PI/6;
   }
}

void sine_fade(int *return_array,int *tick_delay) {
  static float counter = 0.0;
  if (counter > 1000000 || counter < -1000000) {
    counter = 0.0;
  }
  pulsed_led_values(counter, MAXIMUM-MINIMUM, return_array);
  counter += counter_increment_per_tick(PERIOD, TICK_DELAY);
  *tick_delay = TICK_DELAY;
}





