# include "lights.h"

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
            PWM1_DutyCycleSet(duty_cycle);
            break;
        default:
            // Do Nothing;
            continue;
    }
}

void set_state(struct state desired_state){
    set_duty_cycle(RED_LED_PWM, desired_state.red_light);
    set_duty_cycle(WHITE_LED_PWM, desired_state.white_light);
}

void set_state(uint8_t desired_state) {
    set_state(states[desired_state]);
}
void initialize_state() {
    current_state = 0;
    set_state(current_state);
}
void next_light_state() {
    uint8_t next_state = current_state + 1;
    if (next_state > 2){
        next_state = 0;
    }
    set_state(next_state);
    current_state = next_state;
}

void initialize_lights(){
    initialize_state();
    PWM2_Start();
    PWM1_Start();
}