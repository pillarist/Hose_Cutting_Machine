
#include "HardwareSerial.h"
#include "pins_arduino.h"
#include <Arduino.h> 
#include"hose_cutting.h"

my_setup(){
  
  // INPUTs
  pinMode(air_pressure, INPUT);
  pinMode(blade_ready, INPUT);
  pinMode(servo_ready, INPUT);
  pinMode(cutting_motor_ready, INPUT);
  pinMode(auto_manual, INPUT);

  // SWITCHs

  pinMode(inlet_guide_switch, INPUT);
  pinMode(hose_feed_switch, INPUT);
  pinMode(pressure_roller_switch, INPUT);
  pinMode(cutting_clamp_switch, INPUT);
  pinMode(cutting_blade_switch, INPUT);

  // INDICATION

  pinMode(ready_led, OUTPUT);

  // OUTPUTs

  pinMode(inlet_guide_close, OUTPUT);
  pinMode(inlet_guide_open, OUTPUT);
  pinMode(pressure_roller_down, OUTPUT);
  pinMode(pressure_roller_up, OUTPUT);
  pinMode(cutting_clamp_up, OUTPUT);
  pinMode(cutting_clamp_down, OUTPUT);
  pinMode(cutting_blade_up, OUTPUT);
  pinMode(cutting_blade_down, OUTPUT);
  pinMode(servo_run, OUTPUT);

  // Stop pin

  pinMode(cutting_motor_ready, OUTPUT);


  // initial setup

  if (bool (check_ready())){
    digitalWrite(ready_led, HIGH);

  }
};


loop_manual(){
 
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
      digitalWrite(pressure_roller_up,LOW);
      digitalWrite(pressure_roller_down,HIGH);
      }

    if (digitalRead(cutting_clamp_switch))
      {
        digitalWrite(cutting_clamp_up,HIGH);
        digitalWrite(cutting_clamp_down,LOW);
        }

    else {
      digitalWrite(cutting_clamp_up,LOW);
      digitalWrite(cutting_clamp_down,HIGH);
      
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

change_mode(){
Mode = (digitalRead(auto_manual)) ? true : false ;
  };

bool return_mode(){
  return Mode;
};

void emergencyIntrupt(){
 
  digitalWrite(intruppter, LOW);
  Serial.println("emergancy situation");
  exit(0);
};


bool check_ready(){
  return (digitalRead(air_pressure)  && digitalRead(blade_ready)  && \
    digitalRead(servo_ready)  && digitalRead(cutting_motor_ready) );
};

hoseCut(){
  
   if(digitalRead(hose_lenght_counter_read)){ // delay 1000 
      digitalWrite(cutting_clamp_down, HIGH);
      delay(numatics_time_delay);
      if(digitalRead(cutting_clamp_down_ls)){
        digitalWrite(cutting_blade_down,HIGH);
        delay(cutting_time_delay);
        digitalWrite(cutting_blade_down,LOW);  
        digitalWrite(cutting_clamp_down, LOW);
        digitalWrite(cutting_blade_up,HIGH);  
        digitalWrite(cutting_clamp_up, HIGH);
}
   }
}

home_position(){
  if (!(digitalRead(cutting_clamp_up_ls))){
    digitalWrite(cutting_clamp_up,HIGH);
  }
  if (!(digitalRead(cutting_blade_up))){
    digitalWrite(cutting_blade_up,HIGH);
  }
}

loop_auto(){
  // home position
  home_position();
  if (digitalRead(hose_pressence)){
    digitalWrite(house_length_counter_reset, HIGH);
    digitalWrite(hose_quantity_counter_reset, HIGH);
    delay(counter_reset_time);
    digitalWrite(house_length_counter_reset, LOW);
    digitalWrite(hose_quantity_counter_reset, LOW);
    digitalWrite(inlet_guide_open,HIGH );
    digitalWrite(servo_run, HIGH);
    while (check_ready()) {
      hoseCut();
     
      }
      

      }
    }




