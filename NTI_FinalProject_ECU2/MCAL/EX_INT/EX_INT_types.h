/*
 * EX_INT_types.h
 *
 *  Created on: Feb 24, 2023
 *      Author: alish
 */

#ifndef EX_INT_EX_INT_TYPES_H_
#define EX_INT_EX_INT_TYPES_H_

typedef enum {

	EX_INT_low_level = 0,
	EX_INT_both_edges,
	EX_INT_falling,
	EX_INT_rising,

}EX_INT_trigger_t;

typedef enum{
	EX_INT_disabled = 0,
	EX_INT_enabled,
}EX_INT_state_t;

typedef enum{

	EX_INT_INT0 = 0,
	EX_INT_INT1,
	EX_INT_INT2,
}EX_INT_source_t;


#endif /* EX_INT_EX_INT_TYPES_H_ */
