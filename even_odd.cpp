#define DARK 0
#define LIGHT 120
#define TICK_DELAY 250

#include "Arduino.h"

void even_odd(int *return_array,int *tick_delay){
  static bool state = false;
  
  for (int i=0;i<6;i++){
    if ((state && i%2 == 0) || (!state && i%2 != 0)) {
      return_array[i] = LIGHT;    
    }else{
      return_array[i] = DARK;
    }
  }
  
  *tick_delay = TICK_DELAY;
  state = !state;
}

