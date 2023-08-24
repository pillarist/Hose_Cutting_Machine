#include "Arduino.h"
/*
ALL THE COPY RIGHTS RESERVED BY SSG ENGINEERING 
LAST EDITED : 16/8/2023
*/

#ifndef HOSE_CUTTING_H
#define HOSE_CUTTING_H


//                                  INPUTs

// Ready state // 5+1
#define air_pressure 2  
#define blade_ready 3
#define servo_ready 4 
#define cutting_motor_ready 5 
#define door_close 6 

// secondary ready
#define hose_pressence 7 

// Working Mode  3
#define machine_ready 8
#define auto_manual 9

#define auto_cycle_switch 10 

//manual switch signals  6

#define inlet_guide_switch 11 
#define hose_feed_switch 12
#define pressure_roller_switch 13
#define cutting_clamp_switch 14
#define cutting_blade_switch 15
#define exit_guide_switch 16

//limit switches

#define cutting_clamp_up_ls 17
#define cutting_clamp_down_ls 18
#define cutting_blade_up_ls 19
#define cutting_blade_down_ls 20

// counter
#define hose_lenght_counter_read 21
#define hose_quantity_counter_read 22


//   OUTPUTs

// Indication 1
#define ready_signal  23  // machine is ready to work

// counter  2
#define house_length_counter_reset 24
#define hose_quantity_counter_reset 25

// output alaram  6 
#define air_pressure_alaram 26
#define cutting_blade_alaram 27 
#define hose_empty_alaram 28
#define servo_alaram 29
#define cutting_motor_alaram 30
#define door_open_alaram  31



// machine cycle
#define inlet_guide_open 32
#define inlet_guide_close 33

#define pressure_roller_up 34
#define pressure_roller_down 35
#define cutting_clamp_up 36
#define cutting_clamp_down 37
#define cutting_blade_up 38
#define cutting_blade_down 39
#define exit_guide_open 40 //
#define exit_guide_close 41


#define cycle_over 42




// timing
#define counter_reset_time 1000
#define numatics_time_delay 500
#define cutting_time_delay 3000
#define dwell_time 1000

// class hose_cutting_machine{
//     public:
//       int setup();
//       int loop_manual();
//       int loop_auto();
//       int change_mode();
//       bool return_mode();
//       bool check_ready();
//       static void emergencyIntrupt();
//       volatile int lock = false;
 
//     private:
//       bool Mode = false;
      
     
     
       
// };

int my_setup();
int loop_manual();
int loop_auto();
int change_mode();
bool return_mode();
bool check_ready();
static void emergencyInterrupt();
int hoseCut();
int home_position();

static bool Mode = false;

#endif 
