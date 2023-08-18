/*
ALL THE COPY RIGHTS RESERVED BY SSG ENGINEERING 
LAST EDITED : 16/8/2023
*/

#ifndef HOSE_CUTTING_H
#define HOSE_CUTTING_H

// Ready state
#define air_pressure 2
#define blade_dia 3
#define servo_ready 4
#define main_motor_ready 5

// Indication 

#define ready_led  6   // machine is ready to work

// Action

#define auto_manual 6 // cycle mode 
#define cycle_start 7

// manual switch signals

#define inlet_guide 8
#define hose_feed 9
#define pressure_roller 10
#define cutting_clamp 11
#define cutting_blade 12

//limit switches

#define cutting_clamp_up_state 13
#define cutting_clamp_down_state 14
#define cutting_blade_up 15
#define cutting_blade_down 16

// counter

#define hose_lenght_counter 17
#define hose_quantity_counter 18


// output alaram 

#define air_pressure_state 19
#define cutting_blade_under_size 20
#define hose_empty 21
#define servo_not_ok 22
#define main_motor_not_ok 23

// machine cycle
#define inlet_guide_close_valve 23
#define inlet_guide_open_valve 24
#define pressure_roller_up 25
#define pressure_roller_down 26
#define cutting_clamp_up_action 27
#define cutting_clamp_down_action 28
#define servo_run 29
#define cycle_over 30

class hose_cutting_machine{
    public:
      int setup();
      int loop();   

    private:
      bool Mode = false; 
};

#endif