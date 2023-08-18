#include <Arduino.h> 
#include"hose_cutting.h"

hose_cutting_machine::setup(){
  
  Serial.begin(9600);
  
  // INPUTs
  pinMode(air_pressure, INPUT);
  pinMode(blade_dia, INPUT);
  pinMode(servo_ready, INPUT);
  pinMode(main_motor_ready, INPUT);

  // OUTPUTs
  pinMode(ready_led, OUTPUT);

  // initial setup
  if (digitalRead(air_pressure) == HIGH && digitalRead(blade_dia) == HIGH && \
    digitalRead(servo_ready) == HIGH && digitalRead(main_motor_ready) == HIGH){
    digitalWrite(ready_led, HIGH);
    hose_cutting_machine::Mode = true;


  }

};

hose_cutting_machine::loop(){
  Serial.println(hose_cutting_machine::Mode);
  
};