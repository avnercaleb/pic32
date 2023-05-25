/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include "Timers.h"


__attribute__((mips16)) void CoreTimer_Init(uint32_t period)
{
    // configure the core timer
    OpenCoreTimer(period);

    // set up the core timer interrupt with a prioirty of 1 and zero sub-priority
    mConfigIntCoreTimer((CT_INT_ON | CT_INT_PRIOR_1 | CT_INT_SUB_PRIOR_0));

}
