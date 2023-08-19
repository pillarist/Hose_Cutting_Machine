#include "hose_cutting.h"


hose_cutting_machine my_machine;

void setup() {
  // put your setup code here, to run once:
  my_machine.setup();
  
};

void loop() {
  // put your main code here, to run repeatedly:
   if (!(my_machine.Mode) && digitalRead(cycle_switch)){
    my_machine.loop_manual();
    Serial.println(my_machine.Mode);
   }
  
  
  

};
