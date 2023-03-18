/*
 * GIE_private.h
 *
 *  Created on: Feb 25, 2023
 *      Author: alish
 */

#ifndef GIE_GIE_PRIVATE_H_
#define GIE_GIE_PRIVATE_H_

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)

#endif /* GIE_GIE_PRIVATE_H_ */
