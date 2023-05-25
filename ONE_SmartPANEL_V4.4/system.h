/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <plib.h>


/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        40000000UL
#define FCY             SYS_FREQ

#define	GetSystemClock()              (SYS_FREQ)
#define	GetPeripheralClock()          (GetSystemClock()/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()         (GetSystemClock())

/* Utilizado em alternativa ao GetInstructionClock() */
#define PB_FREQ         10000000UL


/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */


#endif /* __SYSTEM_H */