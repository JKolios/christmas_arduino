#define LIGHT 100
#define TICK_DELAY 200

#include "Arduino.h"

void binary_count(int *return_array,int *tick_delay){
  static byte count = 0;
  
  for (int i=0;i<6;i++){
    return_array[i] = bitRead(count, i) * LIGHT;
  }
  count++;
  *tick_delay = TICK_DELAY;
}
