/*
 * GIE_prog.c
 *
 *  Created on: Feb 25, 2023
 *      Author: alish
 */


#include "GIE_private.h"
#include "GIE_interface.h"

void M_GIE_void_EnableGlobalInterrupt(){
	sei();
}
void M_GIE_void_DisableGlobalInterrupt(){

	cli();
}
