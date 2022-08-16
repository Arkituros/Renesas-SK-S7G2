/*
 * millis.h
 *      Author: Arkituros
 * 		Library made for Renesas SK-S7G2
 */

#ifndef MILLIS_H_
#define MILLIS_H_

#include "r_timer_api.h"

typedef unsigned long millis_t;

#define millis() millis_get()
/**
* Initialise, must be called before anything else!
*
* @return (none)
*/
void millis_init(const timer_instance_t temp);

/**
* Get milliseconds.
*
* @return Milliseconds.
*/
millis_t millis_get(void);

/**
* Turn on timer and resume time keeping.
*
* @return (none)
*/
void millis_start(const timer_instance_t temp);

/**
* Pause time keeping and turn off timer to save power.
*
* @return (none)
*/
void millis_stop(const timer_instance_t temp);

/**
* Reset milliseconds count to 0.
*
* @return (none)
*/
void millis_reset(void);

/**
* Add time.
*
* @param [ms] Milliseconds to add.
* @return (none)
*/
void millis_add(millis_t ms);

/**
* Subtract time.
*
* @param [ms] Milliseconds to subtract.
* @return (none)
*/
void millis_subtract(millis_t ms);

#endif /* MILLIS_H_ */
