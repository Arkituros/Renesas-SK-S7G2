/*
 * millis.c
 *      Author: Arkituros
 * 		Library made for Renesas SK-S7G2
 */
#include "millis.h"
#include "hal_data.h"

static volatile millis_t milliseconds;

// Initialise library
void millis_init(const timer_instance_t temp)
{
        temp.p_api->open(temp.p_ctrl, temp.p_cfg);
}

// Get current milliseconds
millis_t millis_get()
{
    millis_t ms;
    ms = milliseconds;
    return ms;
}

// Turn on timer and resume time keeping
void millis_start(const timer_instance_t temp)
{
    temp.p_api->start(temp.p_ctrl);
}

// Pause time keeping and turn off timer to save power
void millis_stop(const timer_instance_t temp)
{
    temp.p_api->stop(temp.p_ctrl);
}

// Reset milliseconds count to 0
void millis_reset()
{
        milliseconds = 0;
}

// Add time
void millis_add(millis_t ms)
{
        milliseconds += ms;
}

// Subtract time
void millis_subtract(millis_t ms)
{
        milliseconds -= ms;
}

// Timer interrupt callback
ISR_Timer(timer_callback_args_t *p_args)
{
    SSP_PARAMETER_NOT_USED(p_args);
    ++milliseconds;
}
