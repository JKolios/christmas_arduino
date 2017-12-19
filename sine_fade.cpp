#include "Arduino.h"
#include "sine_oscillator.h"

#define MINIMUM 40
#define MAXIMUM 160
#define PERIOD 2000
#define TICK_DELAY 10

const float phase_shifts[6] = {0, PI/3, 2*PI/3, PI, 4 * PI/3, 5 *PI/3};

float counter_increment_per_tick(int period, int tick_delay){
 return (2 * PI) / (period / tick_delay);
}

void sine_fade(int *return_array,int *tick_delay) {
  static float counter = 0.0;
  if (counter > 1000000 || counter < -1000000) {
    counter = 0.0;
  }
  return_array = phased_led_values(return_array, counter, MAXIMUM-MINIMUM, phase_shifts);
  float phase_shift = 0.0;
  counter += counter_increment_per_tick(PERIOD, TICK_DELAY);
  *tick_delay = TICK_DELAY;
}





