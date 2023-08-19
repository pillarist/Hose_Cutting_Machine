#include <Arduino.h> 
#include"hose_cutting.h"

hose_cutting_machine::setup(){
  
  Serial.begin(9600);
  
  // INPUTs

  pinMode(air_pressure, INPUT);
  pinMode(blade_ready, INPUT);
  pinMode(servo_ready, INPUT);
  pinMode(main_motor_ready, INPUT);
  pinMode(auto_manual, INPUT);

  pinMode(inlet_guide_switch, INPUT);
  pinMode(hose_feed_switch, INPUT);
  pinMode(pressure_roller_switch, INPUT);
  pinMode(cutting_clamp_switch, INPUT);
  pinMode(cutting_blade_switch, INPUT);



  // OUTPUTs

  pinMode(ready_led, OUTPUT);

  pinMode(inlet_guide_close, OUTPUT);
  pinMode(inlet_guide_open, OUTPUT);
  pinMode(pressure_roller_down, OUTPUT);
  pinMode(pressure_roller_up, OUTPUT);
  pinMode(cutting_clamp_up, OUTPUT);
  pinMode(cutting_clamp_down, OUTPUT);
  pinMode(cutting_blade_up, OUTPUT);
  pinMode(cutting_blade_down, OUTPUT);
  pinMode(servo_run, OUTPUT);


  // initial setup
  if (digitalRead(air_pressure)  && digitalRead(blade_ready)  && \
    digitalRead(servo_ready)  && digitalRead(main_motor_ready) ){
    digitalWrite(ready_led, HIGH);

    if (digitalRead(auto_manual)){
      hose_cutting_machine::Mode = true;
    }
   
  }

};

hose_cutting_machine::loop_manual(){
 
    if (digitalRead(inlet_guide_switch)){
      digitalWrite(inlet_guide_open,HIGH);
      digitalWrite(inlet_guide_close,LOW);
      
      }
    else {
      digitalWrite(inlet_guide_open,LOW);
      digitalWrite(inlet_guide_close,HIGH);
      }

    if (digitalRead(pressure_roller_switch))
      {
        digitalWrite(pressure_roller_up,HIGH);
        digitalWrite(pressure_roller_down,LOW);
        }
    else {
      digitalWrite(pressure_roller_down,HIGH);
      digitalWrite(pressure_roller_up,LOW);
      }

    if (digitalRead(cutting_clamp_switch))
      {
        digitalWrite(cutting_clamp_up,HIGH);
        digitalWrite(cutting_clamp_down,LOW);
        }

    else {
      digitalWrite(cutting_clamp_down,HIGH);
      digitalWrite(cutting_clamp_up,LOW);
      }

    if (digitalRead(exit_guide_switch)){

      digitalWrite(exit_guide_open,HIGH);
      digitalWrite(exit_guide_close,LOW);
      }
    else {
      digitalWrite(exit_guide_open,LOW);
      digitalWrite(exit_guide_close,HIGH);
      }

    if (digitalRead(cutting_blade_switch)){

      digitalWrite(cutting_blade_up,HIGH);
      digitalWrite(cutting_blade_down,LOW);;
      }
    else {
      digitalWrite(cutting_blade_up,LOW);
      digitalWrite(cutting_blade_down,HIGH);
      }

    if (digitalRead(hose_feed_switch)){
      
      digitalWrite(servo_run,HIGH);
      }
    else {
      digitalWrite(servo_run,LOW);
      }

  
  
};