#include "hose_cutting.h"


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  my_setup();
  change_mode();
  home_position();
 
};

void loop() {
  
   if (digitalRead(cycle_switch)){

     if (return_mode() && check_ready()){
       loop_auto();
     }

     else{
       if (check_ready()){
         loop_manual();
       }
     }
   }
}
    
  