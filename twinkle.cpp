#include "Arduino.h"
#include "sine_oscillator.h"

#define MINIMUM 20
#define MAXIMUM 120
#define TICK_DELAY 50

const float led_periods[6] = {3000, 4000, 2000, 5000, 1000, 6000};

float counter_change_for_period(int period, int tick_delay) {
  return (2 * PI) / (period / tick_delay);
}

void twinkle(int *return_array,int *tick_delay) {
    
  static float led_counters[6];
  for (int i=0;i<6;i++) {
    if (led_counters[i] > 1000000 || led_counters[i] < -1000000) {
    led_counters[i] = 0.0;
  }
    led_counters[i] = led_counters[i] + counter_change_for_period(led_periods[i], TICK_DELAY);
  }
  
  return_array = multiperiod_led_values(return_array, led_counters, MAXIMUM-MINIMUM);
  *tick_delay = TICK_DELAY;
}
