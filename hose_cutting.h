/*
ALL THE COPY RIGHTS RESERVED BY SSG ENGINEERING 
LAST EDITED : 16/8/2023
*/

#ifndef HOSE_CUTTING_H
#define HOSE_CUTTING_H

// Ready state
#define air_pressure 2
#define blade_ready 3
#define servo_ready 4
#define main_motor_ready 5

// Indication 

#define ready_led  6   // machine is ready to work

// Action

#define auto_manual 7 // cycle mode 

#define cycle_switch 8

// manual switch signals

#define inlet_guide_switch 9
#define hose_feed_switch 10
#define pressure_roller_switch 11
#define cutting_clamp_switch 12
#define cutting_blade_switch 13
#define exit_guide_switch 14

//limit switches

#define cutting_clamp_up_ls 15
#define cutting_clamp_down_ls 16
#define cutting_blade_up_ls 17
#define cutting_blade_down_ls 18

// counter

#define hose_lenght_counter 19
#define hose_quantity_counter 20


// output alaram 

#define air_pressure_low 21
#define cutting_blade_not_ready 22
#define hose_empty 23
#define servo_not_ready 24
#define main_motor_not_ready 25

// machine cycle
#define inlet_guide_close 26
#define inlet_guide_open 27
#define pressure_roller_up 28
#define pressure_roller_down 29
#define cutting_clamp_up 30
#define cutting_clamp_down 31
#define cutting_blade_up 32
#define cutting_blade_down 33
#define exit_guide_close 34
#define exit_guide_open 35
#define servo_run 36
#define cycle_over 37

class hose_cutting_machine{
    public:
      int setup();
      int loop_manual();
      int loop_auto();
      int change_mode();
      int return_mode();


      bool Mode = false;    

    private:
     
       
};

#endif