/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC12F1572
        Driver Version    :  2.00
 */

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pwm1.h"
#include "mcc_generated_files/pwm2.h"

# define RED_LED_PWM   1
# define WHITE_LED_PWM 2
# define LED_PWM_DUTY_CYCLE_0    0
# define LED_PWM_DUTY_CYCLE_60   9
# define LED_PWM_DUTY_CYCLE_100 15
# define LED_PWM_DUTY_CYCLE_OFF LED_PWM_DUTY_CYCLE_0
# define LED_PWM_DUTY_CYCLE_ON LED_PWM_DUTY_CYCLE_100



struct led_pwm_state {
    uint16_t duty_cycle;
};

struct state {
    struct led_pwm_state red_light;
    struct led_pwm_state white_light;
};

static uint8_t current_state = 0;

static struct state states [3] = {
    // 0: OFF
    {
        /* r_light */ {LED_PWM_DUTY_CYCLE_OFF},
        /* w_light */ {LED_PWM_DUTY_CYCLE_OFF}
    },
    // 1: White ON, Red OFF
    {
        /* r_light */ {LED_PWM_DUTY_CYCLE_OFF},
        /* w_light */ {LED_PWM_DUTY_CYCLE_ON}
    },
    // 2: White OFF, Red ON
    {
        /* r_light */ {LED_PWM_DUTY_CYCLE_ON},
        /* w_light */ {LED_PWM_DUTY_CYCLE_OFF}
    }
};

void set_duty_cycle(uint8_t pwm_channel, uint16_t duty_cycle){
    switch (pwm_channel) {
        case RED_LED_PWM:
            PWM1_DutyCycleSet(duty_cycle);
            break;
        case WHITE_LED_PWM:
            PWM2_DutyCycleSet(duty_cycle);
            break;
    }
}

void set_state(struct state desired_state){
    set_duty_cycle(RED_LED_PWM, desired_state.red_light.duty_cycle);
    set_duty_cycle(WHITE_LED_PWM, desired_state.white_light.duty_cycle);
    PWM1_LoadBufferSet();
    PWM2_LoadBufferSet();
}

void set_state_by_index(uint8_t desired_state) {
    set_state(states[desired_state]);
}

void next_light_state() {
    uint8_t next_state = current_state + 1;
    if (next_state > 2){
        next_state = 0;
    }
    set_state_by_index(next_state);
    current_state = next_state;
}

void initialize_state() {
    current_state = 0;
    set_state_by_index(current_state);
}
void initialize_lights(){
    initialize_state();
    PWM2_Start();
    PWM1_Start();
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
        
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    initialize_lights();
    INT_SetInterruptHandler(&next_light_state);

    while (1)
    {
        // Add your application code
    }
}
