/* 
 * File:   lights.h
 * Author: arbrick
 *
 * Created on May 7, 2020, 4:17 PM
 */

#ifndef LIGHTS_H
#define	LIGHTS_H

#ifdef	__cplusplus
extern "C" {
#endif

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

void next_light_state(void);
void initialize_lights(void);

#ifdef	__cplusplus
}
#endif

#endif	/* LIGHTS_H */

