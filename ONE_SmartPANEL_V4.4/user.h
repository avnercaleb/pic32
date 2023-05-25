/*
 * File:   user.h
 * Author: André Gomes
 *
 */
#ifndef USER_H
#define	USER_H

#include <xc.h>         /* Defines special funciton registers, CP0 regs  */
#include <stdint.h>     /* For uint32_t definition                       */
#include <float.h>
#include <math.h>

#include "system.h"
#include "UART.h"
#include "SPI.h"
#include "Timers.h"
#include "RTC_MCP7952X.h"
#include "PWM.h"
#include "eepromMap.h"
#include "delay.h"
#include "adc.h"
#include "MEMS_LIS331DL.h"
#include "PM_MCP39F511.h"
#include "DALI.h"
#include "AES/AES_ECB_PIC32.h"

#include "M1_RF.h"

#ifdef RF_RFM22B
#include "RF_RFM22B.h"
#endif
#ifdef RF_RFM69HCW
#include "RF_RFM69HCW.h"
#endif
#ifdef RF_RFM95W
#include "RF_RFM95W.h"
#endif

/******************************************************************************/
/* User Level #define Macros - Hardware Configurations                        */
/******************************************************************************/
#define OLD_SYSTEM              /* Define to enable the use of the old protocol */
//#define M1_RF                 /* Define to enable the use of the SensingRF Protocol */

/******************************************************************************/
/* Enable/Disable Debug Messages                                              */
/******************************************************************************/
//#define DEBUG_VERSION_MSG       (0)
//#define DEBUG_RF_INT            (0)
//#define DEBUG_RF_INTERROR       (0)
//#define DEBUG_RF_RX_MSGPRINT    (0)
//#define DEBUG_RF_RX_MSGHANDLER  (0)
//#define DEBUG_RCV_RF            (0)
//#define DEBUG_WRONG_MSG         (0)
//#define DEBUG_RESEND_RF         (0)
//#define DEBUG_RF_ERROR          (0)
//#define DEBUG_RF_5S             (0)
//#define DEBUG_RF_RESET          (0)
//#define DEBUG_RTC_UPDATE        (0)
//#define DEBUG_SEND_RF_MSG       (0)
//#define DEBUG_SYS_STT           (0)
//#define DEBUG_PROF_UPDATE       (0)
//#define DEBUG_GCONF_UPDATE      (0)
//#define DEBUG_PWR_FAIL          (0)
//#define DEBUG_STAB_ALR          (0)
//#define DEBUG_RTC_CALIB         (0)
//#define DEBUG_PWR_CALC          (0)
//#define DEBUG_PM_FAIL           (0)
//#define DEBUG_PM_RCVMSG         (0)
//#define DEBUG_ASTROCLK          (0)
//#define DEBUG_LDR               (0)
//#define DEBUG_CHECK_DEBUGCTRL   (0)

#define DEBUG_1SFLAG            (1)
#define JIG_ON  1
#define JIG_OFF 0

/******************************************************************************/
/* User Level #define Macros - System Settings                                */
/******************************************************************************/

#define RS485_TX_EN         mPORTASetBits(BIT_4);
#define RS485_TX_DIS        mPORTAClearBits(BIT_4);

#define DIGIN_1             PORTBbits.RB10
#define DIGIN_2             PORTBbits.RB11  
#define DIGIN_3             PORTBbits.RB12                                                            
#define DIGIN_4             PORTBbits.RB13

#define DIGOUT_1            PORTAbits.RA0  //OD2
#define DIGOUT_2            PORTBbits.RB3  //OD1
#define DIGOUT_3            PORTAbits.RA2  //OD3
#define DIGOUT_4            PORTAbits.RA3  //OD4

#define DIGOUT_1_ON         mPORTASetBits(BIT_0);
#define DIGOUT_1_OFF        mPORTAClearBits(BIT_0);
#define DIGOUT_2_ON         mPORTBSetBits(BIT_3);
#define DIGOUT_2_OFF        mPORTBClearBits(BIT_3);
#define DIGOUT_3_ON         mPORTASetBits(BIT_2);
#define DIGOUT_3_OFF        mPORTAClearBits(BIT_2);
#define DIGOUT_4_ON         mPORTASetBits(BIT_3);
#define DIGOUT_4_OFF        mPORTAClearBits(BIT_3);

#define PIR_PIN_STT         PORTBbits.RB1

/* Define for the different time for the relay */
#define RELAY_ALQ309        (0)
#define RELAY_ALQ306        (1)

/* Definitions for the dimming process */
//#define DIM_TIME                                              /* Time to increment the PWM in s - It depends on: PWM*0.00002+0.00001*/
#define TMR_PRE_DIM         32                                  /* Pre-scaler timer */
//#define PR_TIMER_DIM        3907                              /* (SYS_FREQ * DIM_TIME) / TMR_PRE_DIM - Depends on: -PWM*35+35035 */
#define PR_TIMER_DIM(PWM)   (uint16_t)((-PWM*35)+37500)


/* Definitions for relay */
#define TMR_PRE_CNT         256         /* Timer 3 Pre-scaler - counting ms */

#ifdef _NEMA_
    /* Power frequency - 50Hz */
    #define CNT_MS_ON_50        0.0139      /* Time to be counted by the timer in seconds - Turn ON relay */
    #define CNT_MS_OFF_50       0.0031      /* Time to be counted by the timer in seconds - Turn OFF relay */

    #define PR_TMR_CNT_ON_50    2172        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
    #define PR_TMR_CNT_OFF_50   484

    /* Power frequency - 60Hz */
    #define CNT_MS_ON_60        0.0103      /* Time to be counted by the timer in seconds - Turn ON relay - ALQ309 */
    #define CNT_MS_OFF_60       0.0173      /* Time to be counted by the timer in seconds - Turn OFF relay - ALQ309 */

    #define PR_TMR_CNT_ON_60    1609        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
    #define PR_TMR_CNT_OFF_60   2703
#else 
    #if RELAY_ALQ309
        /* Power frequency - 50Hz */
        #define CNT_MS_ON_50        0.0143      /* Time to be counted by the timer in seconds - Turn ON relay */
        #define CNT_MS_OFF_50       0.00165     /* Time to be counted by the timer in seconds - Turn OFF relay */

        #define PR_TMR_CNT_ON_50    2235        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
        #define PR_TMR_CNT_OFF_50   258

        /* Power frequency - 60Hz */
        #define CNT_MS_ON_60        0.0103      /* Time to be counted by the timer in seconds - Turn ON relay - ALQ309 */
        #define CNT_MS_OFF_60       0.0173      /* Time to be counted by the timer in seconds - Turn OFF relay - ALQ309 */

        #define PR_TMR_CNT_ON_60    1609        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
        #define PR_TMR_CNT_OFF_60   2703    
    #elif RELAY_ALQ306
        /* Power frequency - 50Hz */
        #define CNT_MS_ON_50        0.0157      /* Time to be counted by the timer in seconds - Turn ON relay */
        #define CNT_MS_OFF_50       0.00345     /* Time to be counted by the timer in seconds - Turn OFF relay */

        #define PR_TMR_CNT_ON_50    2500        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
        #define PR_TMR_CNT_OFF_50   539

        /* Power frequency - 60Hz */
        #define CNT_MS_ON_60        0.0117      /* Time to be counted by the timer in seconds - Turn ON relay - ALQ309 */
        #define CNT_MS_OFF_60       0.0187      /* Time to be counted by the timer in seconds - Turn OFF relay - ALQ309 */

        #define PR_TMR_CNT_ON_60    1828        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
        #define PR_TMR_CNT_OFF_60   2922
    #else
        /* Power frequency - 50Hz */
        //Not defined

        /* Power frequency - 60Hz */
        #define CNT_MS_ON_60        0.0102      /* Time to be counted by the timer in seconds - Turn ON relay */
        #define CNT_MS_OFF_60       0.0176      /* Time to be counted by the timer in seconds - Turn OFF relay */

        #define PR_TMR_CNT_ON_60    1594        /* (SYS_FREQ * CNT_MS) / TMR_PRE_CNT */
        #define PR_TMR_CNT_OFF_60   2750
    #endif
#endif

/* Definitions for the Uart detection of End Of Message */
#define EOM_TIME            0.005       /* Time to detect a End Of Message in seconds - UART1 */
#define TMR_PRE_EOM         64          /* Pre-scaler timer */
#define PR_TIMER_EOM        3125        /* (SYS_FREQ * EOM_TIME) / TMR_PRE_EOM */


/* Defines for system update */
#define NO_UPDATE               0
#define RTC_UPDATE              1
#define PROF_UPDATE             2
#define ASTRO_UPDATE            3
#define CONFIGS_UPDATE          4
#define UPDATE_SYS_CONFIG       5
#define ADDON_CONFIGS_UPDATE    6
#define PWR_FREQ_UPDATE         7
#define ENCRYPTION_UPDATE       8
#define CONFIG_SENSORS_UPDATE   9

/* Defines for the Pins */
#define DISABLE         0
#define ENABLE          1

/* Management for pwm with duty factor */
#define PWM_WITH_DTFACT(x)          (uint16_t)(x * sys.dutyFact)

/* Defines for System State Machine */
#define SYS_OFF             0
#define SYS_ON              1
#define SYS_SOS             2

/* Defines for Dimming Management */
#define DIM_MANUAL          0x00            /* Manual set for the dimming */
#define DIM_PROF_ON         0x01            /* Dimming is controlled by the profiles configured in the system */
#define DIM_ASTROCLK_ON     0x02            /* Dimming is controlled by the astronomical clock configured - turns ON/OFF at the Sunset/Sunrise */
#define DIM_PROF_ASTO_ON    0x03            /* Dimming is controlled by the profiles and the astro clock, when the lamp is ON the system use the profile information
                                                then the lamp goes OFF when the astro clk set the lamp OFF */

#define PWM_ASTROCLK_DEFAULT    500         /* Dimming when there is no dimming to be configured with Astro clock */
#define PWM_LDR_DEFAULT         1000        /* Dimming when there is no dimming to be configured with LDR control */


/* Defines for LDR control & configs */
//#define LDR_KP            0.15         /* Constant to adjust the Proporcional LDR Control */
//#define LDR_KI            0.3          /* Constant to adjust the Integral LDR Control */
#define LDR_KP              0.1         /* Constant to adjust the Proporcional LDR Control */
#define LDR_KI              0.25        /* Constant to adjust the Integral LDR Control */
#define LDR_MIN             5           /* Minimum value to assume the measure - in ADC value */
#define LDR_MAX             900         /* Max value to assume the measure - in ADC value */
#define LDR_MIN_ABS_AMS302  5           /* Min value to ensure that the calculations doesn't overflow - AMS302 Sensor */
#define LDR_MAX_ABS_AMS302  341         /* Max value to ensure that the calculations doesn't underflow - AMS302 Sensor */
#define LDR_MIN_ABS         45          /* Min value to ensure that the calculations doesn't overflow */
#define LDR_MAX_ABS         1020        /* Max value to ensure that the calculations doesn't underflow */
#define LDR_HYST            10          /* Value to create an hysteresis when the LDR ctrl by threshold is ON */
#define LDR_MIN_INT         3           /* Minimum "error" value to increment the dimming */

#define LDR_OFF         0
#define LDR_THR         1
#define LDR_SP          2


#define SYS_TPCB_OFFSET         6

/* Defines for profiles handling */
#define MINUTES_24H     1440            /* 24h * 60minutes = 1440 */
#define N_PROFILES      4

#define NO_PROFILES     0
#define PROF_1          1
#define PROF_2          2
#define PROF_3          3
#define PROF_4          4

#define PROFILE_CHANGE  1               /* New profile */


#define NO_ALARMS       0x00
#define LAMP_POS        0
#define TEMPLAMP_POS    1
#define TEMPPCB_POS     2
#define STAB_POS        3
#define VOLT_POS        4
#define CURR_POS        5
#define LDR_POS         6


/* Defines for the Alarms control */
#define ALR_INT_SENT        3630        /* Time in seconds between the sent of alarm messages */

/* Default values for the Alarms control */
#define ALR_TLAMP_MAX       75          /* Maximum ºC for the Lamp */
#define ALR_TLAMP_MIN       0           /* Minimum ºC for the Lamp */

#define ALR_TPCB_MAX        75          /* Maximum ºC for the harware */
#define ALR_TPCB_MIN        0           /* Minimum ºC for the hardware */
#define ALR_TPCB_TIME       60          /* Interval for duty control when the pcb temp is in alarm */

#define ALR_STAB_THR        10          /* Value for the detection of a stability alarm */
#define ALR_STAB_INT        50          /* Value in seconds that the stability should stay in alarm state*/

#define ALR_VOLT_MAX        60          /* Maximum VOLT for the system - ONE_LED_DRIVER board */
#define ALR_VOLT_MIN        9           /* Minimum VOLT for the system - ONE_LED_DRIVER board */

#define ALR_CURR_MOC_MAX    11          /* Maximum AMPERE for the ONE_MOC board */

#define ALR_LDR_MIN         10          /* Minimum value in LUX for the respective percentage of duty */
#define ALR_LDR_DUTY        50          /* Duty for comparison with minimum LUX */

#define ALR_L_PERCENT_INF   0.9         /* Percentage for Lamp Alarm - Dimming*MAX_Current*ALR_L_PERCENT */
#define ALR_L_PERCENT_SUP   1.1         /* Percentage for Lamp Alarm - Dimming*MAX_Current*ALR_L_PERCENT */
#define ALR_L_TIME          50          /* Value in seconds that the lamp should stay in alarm state */
#define ALR_L_MIN_PWM       300         /* Minimum PWM to start detecting Lamp alarm */

#define ALR_V_MOC_MAX       250         /* Max voltage for the ONE_MOC board */
#define ALR_V_MOC_MIN       90          /* Min voltage for the ONE_MOC board */
#define ALR_V_TIME          50          /* Value in seconds that the voltage should stay in alarm state */

/* Defines for the Stability control */
#define ALR_STAB_CONFIG     1
#define ALR_STAB_NOTCONFIG  0

/* Defines for data monitoring */
#define PWR_FREQ_MAX            65      /* Frequency in Hz */
#define PWR_FREQ_MIN            45      /* Frequency in Hz */
#define PWR_FREQ_50Hz           50      /* Frequency in Hz */
#define PWR_FREQ_60Hz           60      /* Frequency in Hz */

#define PWR_FREQ_50Hz_MIN       47000   /* Frequency in mHz */
#define PWR_FREQ_50Hz_MAX       53000   /* Frequency in mHz */
#define PWR_FREQ_60Hz_MIN       57000   /* Frequency in mHz */
#define PWR_FREQ_60Hz_MAX       63000   /* Frequency in mHz */

/* Defines for maximum current calibration */
#define PWR_LF_CAL_OFF              0
#define PWR_LF_CAL_ON               1
#define PWR_LF_CAL_2NDSTT           2       /* 2nd State for the calibration - 1st goes to a init PWM and 2nd goes to final PWM */
#define PWR_LF_CAL_INITDIMTIME      20
#define PWR_LF_CAL_TOTDIMTIME       40
#define PWR_LF_CAL_INITPWM          200     /* Fist measure for the power consumption is going to be at this PWM valur */
#define PWR_LF_CAL_FINALPWM         1000    /* The final measure is going to be at this value */
#define PWR_LF_CAL_DEFAULT_MIN      0.001   /* Minimum value to avoid a false alarm - kW*/
#define PWR_LF_CAL_DEFAULT_MAX      1.000   /* Maximum value to avoid a false alarm - kW*/

/* Defines for power consumption calculation */
#define PWR_KWH_MIN         0.001

/* PIR defines */
#define PIR_TIMEOUT         1200        /* Timeout for PIR detecion in seconds */
#define PIR_CNT_MAX         65530       /* Max value for PIR counter */
#define PIR_DUTY            1000        /* Duty value to be used when PIR is ON */
#define PIR_RESEND_TM       6           /* Seconds to send another PIR control message */

#define PIR_DISABLE         0
#define PIR_ENABLE          1
#define PIR_PIN_OFF         2
#define PIR_PIN_ON          3
#define PIR_OFF             0
#define PIR_ON              1

/* Defines for the switching Relay management */
#define SWITCH_RELAY_OFF        0       /* No order to switch the relay */
#define SWITCH_RELAY_WAIT       1       /* Order pending */
#define SWITCH_RELAY_READY      2       /* Order ready to be executed */

#define ZERO_CROSS_MIN          2       /* Times for the zero-cross detection to verify if is zero-cross or PIR signal */

/* Auxiliary defines */
#define N_MEAN               9               /* Number of values for mean calculations */

/* General Time - Used in time flags */
#define ONE_HOUR_INT            3599        /* 3600s - 1 - time in seconds */
#define FIFTEEN_MINUTES_INT     899         /* 900s - 1 - time in seconds  */
#define FIVE_MINUTES_INT        299         /* 300s - 1 - time in seconds  */
#define ONE_MINUTE_INT          59          /* 60s - 1 - time in seconds  */
#define HALF_MINUTE_INT         29          /* 30s - 1 - time in seconds  */
#define ONE_SECOND_INT          9           /* 10-1 - time in 100miliseconds

/* PWR Calc Time */
#define ONE_HOUR                3600        /* 60 minutes */
#define FIFTEEN_MINUTES         900         /* 15 minutes */
#define FIVE_MINUTES            300         /* 5 minutes */
#define ONE_MINUTE              60          /* 1 minute */
#define HALF_MINUTE             30          /* 30 seconds */


/******************************************************************************/
/* User System Structs                                                         /
/******************************************************************************/
#ifdef OLD_SYSTEM

    /* Auxiliary buffer for the mean calculations */
    typedef struct
    {
        uint32_t    buff[N_MEAN];
        uint8_t     ind;

    }MEAN_STRUCT;


    /* LDR Control Struct */
    typedef struct
    {
        int16_t     dif;            /* Diference between the Setpoint of Lux and the vlue measured by the LDR */
        int16_t     difK;           /* Proporcional Control */
        int16_t     difI;           /* Integrative Control */
        double      kp;
        double      ki;
        uint8_t     inFlag;         /* Flag that indicate if the measures from the Input of the LDR sensor are OK */
        uint8_t     ready;          /* Flag that indicate that a new measure of Lux arrived by RF - when there is no local LDR */
        uint8_t     ldrDuty;        /* Variable to store PWM duty broadcasted by network light sensor */

    }LDR_STRUCT;


    typedef struct
    {
        /* Saved and used data in the RF msgs */
        uint16_t    net;            /* Network number for RF communication */
        uint16_t    sn;             /* Serial number for RF communication */
        uint16_t    ldr;            /* LDR measured */
        int8_t      tempLED;        /* Temperature of the LEDs measured */
        int8_t      tempPCB;        /* Temperature of the PCB measured */
        uint16_t    volt;           /* Input voltage measured */
        uint16_t    current;        /* Current of the system LDR measured */
        uint8_t     sysStt;         /* System ON/OFF */
        uint8_t     profileStt;     /* Profiles ON/OFF */
        uint16_t    setLDR;         /* LDR Setpoint - LUX */
        uint8_t     ldrCtrl;        /* LDR control OFF/Setpoint/Threshold */
        uint8_t     ttlMAX;         /* MAX value for the TTL */
        uint16_t    dutyTmp;        /* Duty-Cycle information for the PWM channels */
        uint16_t    dutyInit;       /* Duty-Cycle used when the user want a fixed Initial duty */
        uint16_t    dutyAux;        /* Duty-Cycle for use when System is configuraed as ON/OFF */
        double      dutyFact;       /* Value to adjust the medium current to the LED - DUTY * FACTOR */
        uint8_t     ldrOffset;      /* LDR offset to calibrate the LDR sensor */
        uint32_t    workHours;      /* Total of hours that the system is ON */
        uint8_t     pirCtrl;        /* Movement detected ON/OFF - Local and Remote */
        uint16_t    pirCnt;         /* Counter to control change of state and the timeout */
        uint16_t    dutyPIR;        /* Save the duty configuration before PIR detection */
        uint8_t     pirENABLE;      /* Flag that enables the local PIR Detection */
        uint8_t     debugCtrl;      /* Flag to control the "print" of informations to the UART */
        uint8_t     tLedENABLE;     /* Flag to control if the temperature of PCB is monitored */
        uint8_t     encCtrl;        /* Flag to control if the RF messages are encripted or not */
        /* TODO <Colocar variáveis para configuração da recta dos sensores> */
        int16_t     currOffSet;     /* Offset for the current measurement */
        uint8_t     pwrFreq;        /* Power supply frequency - 50000 or 60000 mHz */
        /* Unsaved and unused data in the RF msgs */
        uint16_t    duty;           /* Real Duty-Cycle of the PWM channels */
        uint16_t    dtSttMch;       /* Variable to handle with the duty-cycle when alarms are ON */
        uint8_t     flagDim;        /* Flag that informs the system that a new PWM is ready to be configured*/
        uint8_t     dimInt;         /* Configuration for the dimming steps */
        uint8_t     switchRelay;    /* Flag to control the switch oh the Relay */
        uint16_t    voltDC;         /* DC voltage of the 7V */
        MEAN_STRUCT ldrMean;        /* Buffer to get the mean value for the LDR sensor */
        LDR_STRUCT  ldrS;           /* Structure for the LDR monitoring and control */
        uint8_t     sysSttAnt;      /* Anterior System Status */
        uint8_t     updateID;       /* Update ID order by RF message - Calendar, Profiles*/
        uint8_t     calib;          /* Value for the temperature compensation for the RTC */
        uint8_t     flag1s;         /* flag for 1s control */
        uint8_t     flag1min;       /* flag for 1minute control */
        uint16_t    flag1h;         /* flag for 1h control */
        uint8_t     flag12h;        /* flag for 12h control */        
        uint8_t     flag24h;        /* flag for 24h/1 day control */
        uint8_t     flagTempComp;   /* flag for temperature compensation control */
        uint8_t     flagChkProf;    /* flag for the check profile control */
        uint8_t     flagInit;       /* flag that indicates the first cycle */
        uint8_t     pirSendCnt;     /* Variable to send another PIR message after PIR_RESEND_TM seconds */

    }SYS_STRUCT;


    typedef struct
    {
        uint8_t     hhBeg1;
        uint8_t     mmBeg1;
        uint8_t     hhEnd1;
        uint8_t     mmEnd1;
        uint8_t     dim1;
        uint8_t     hhBeg2;
        uint8_t     mmBeg2;
        uint8_t     hhEnd2;
        uint8_t     mmEnd2;
        uint8_t     dim2;
        uint8_t     hhBeg3;
        uint8_t     mmBeg3;
        uint8_t     hhEnd3;
        uint8_t     mmEnd3;
        uint8_t     dim3;
        uint8_t     hhBeg4;
        uint8_t     mmBeg4;
        uint8_t     hhEnd4;
        uint8_t     mmEnd4;
        uint8_t     dim4;
        uint16_t    minAbsPbeg[N_PROFILES];
        uint16_t    minAbsPend[N_PROFILES];
        uint8_t     profFlag;

    }PROF_STRUCT;


    /* Astronomical Clock Struct */
    typedef struct
    {
        uint8_t     hhSset;
        uint8_t     mmSset;
        uint8_t     hhSrise;
        uint8_t     mmSrise;
        uint16_t    minAbsSset;
        uint16_t    minAbsSrise;
        uint16_t    dimCurr;            /* Dimming when the sunset starts - it will be used if the profiles aren't set */
        uint8_t     dimSttAnt;          /* Anterior Dimming State */
        uint8_t     dimStt;             /* This is intended to have the State OFF when the dimming should be ZERO */

    }ASTRO_STRUCT;


    /* Structure for Power consumption calculation */
    typedef struct
    {
        uint8_t         flag;           /* Flag fot Power consuption calculation */
        uint8_t         intrSec;        /* Interval for the Power Calculation in seconds */
        uint16_t        intrF;          /* Interval for the Power Calculation in seconds - Interrupt Flag */
        double          intr2hs;        /* Conversion of the interval in seconds to hour share */
        double          kw;             /* Active power */
        double          kvar;           /* Reactive power */
        double          pwrFact;        /* Power factor */         
        double          kva;            /* Apparent power */
        double          kwh;            /* Active power consumption */
        double          kvarh;          /* Reactive power consumption */
        double          kwhSum;         /* Sum of the active power consumption */
        double          kvarhSum;       /* Sum of the reactive power consumption */
        uint8_t         flagInit;       /* Variable to control if any power consumption had been saved */               
        MEAN_STRUCT     currMean;       /* Struct to do a mean calculation for the current value */
        MEAN_STRUCT     voltMean;       /* Struct to do a mean calculation for the voltage value */
    
    }PWR_CONSUME_STRUCT;



    /* Structure for power consumption calibration - Lamp Failure*/
    typedef struct
    {
        uint8_t     cnt;
        uint8_t     set;
        uint16_t    actDim;
        double      valMin;
        double      valMax;

    }PWR_LF_CAL_STRUCT;


    /* Structures for alarm handling */
    typedef struct
    {
        uint8_t     set;
        int8_t      minVal;
        int8_t      maxVal;
        uint16_t    time;                   /* Time to control do the dimming control */
        uint16_t    spTime;                 /* Set-point for the time */


    }ALARM_T_ITEM;                          /* Alarm for temperature sensors */

    typedef struct
    {
        uint8_t     set;
        uint16_t    minVal;
        uint16_t    maxVal;
        uint16_t    time;                   /* Time that the alarm situation should be active to send an alarm */
        uint16_t    spTime;                 /* Set-point for the time */

    }ALARM_E_ITEM;                          /* Alarm for electrical stuff - voltage and current */

    typedef struct
    {
        uint8_t     init;                   /* Flag that informs the system if the Initial coordenates are set */
        uint8_t     set;
        uint8_t     limit;                  /* Limit of the difference between the current position and the initial */
        uint8_t     time;                   /* Time that the alarm situation should be active to send an alarm */
        uint16_t    spTime;                 /* Set-point for the time */

    }ALARM_S_ITEM;                          /* Alarm for stability sensor */

    typedef struct
    {
        uint8_t     set;
        uint16_t    time;                   /* Time that the alarm situation should be active to send an alarm */
        uint16_t    spTime;                 /* Set-point for the time */

    }ALARM_L_ITEM;                          /* Alarm for Lamp failure */


    typedef struct
    {
	ALARM_L_ITEM    lamp;
	ALARM_T_ITEM	tempLamp;
	ALARM_T_ITEM	tempPCB;
	ALARM_S_ITEM	stability;
	ALARM_E_ITEM	voltage;
	ALARM_E_ITEM	current;
	ALARM_L_ITEM	ldr;
	uint16_t        sent;
    uint16_t        dutyAlarm;          /* Variable to save the duty when the system is in Alarm mode */
    uint8_t         resume;             /* Byte where each bit is one alarm flag
                                         * Bit0-lamp | Bit1-tempLamp | bit2-tempPCB |...| Bit7-ldr*/
    uint8_t         resumeAnt;          /* Anterior resume - used to detect new alarms and send alarm message*/
    
    }ALARM_STRUCT;

#endif /* OLD_SYSTEM */



#ifdef SENSING_RF

    typedef struct
    {
        uint32_t    sn;                 /* Serial Number of the system */
        uint16_t    net;                /* Network Number of the system */
        uint32_t    bridge;             /* Bridge Number associated to this system */
        uint8_t     sysMode;            /* System Mode - ON/OFF */
        uint8_t     profMode;           /* Profiles Mode - ON/OFF */
        uint8_t     ldrMode;            /* LDR Mode - Set-Point / Threshold / OFF*/
        uint8_t     ldrSet;             /* LDR Value for the set-point or the threshold */

        uint8_t     alrStt;             /* Byte Containing the status of the alarms of the board */
        uint32_t    wh;                 /* Work Hours - Hour counter for the ON Time of the system */

    }SYS_STRUCT;

#endif /* SENSING_RF */

uint8_t jigFlag;

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/


 /**
 * Function to config the IO Ports and the Peripherals
 */
__attribute__((mips16)) void Config_IO_Peripherals(void);



/**
 * Function for processing the messages received in the UART1
 * @param 1 - UART_STRUCT pointer
 * @param 2 - SYS_STRUCT pointer
 * @param 3 - 
 */
__attribute__((mips16)) void UART_ProcessMsg(UART_STRUCT *uartData, SYS_STRUCT *sysData, PM_STRUCT *pmData,\
                                             PWR_CONSUME_STRUCT *pwrData, RF_STRUCT *rfData, RTC_DATA *rtcData);


/* RF Functions */

/**
 * Function to process the received RF message
 * @param 1 - RF_STRUCT pointer
 * @param 2 - SYS_STRUCT pointer
 * @param 3 - RTC_STRUCT pointer
 * @param 4 - PROF_STRUCT pointer
 */
__attribute__((mips16)) void RF_ProcessMsg(RF_STRUCT *rfData, MSGBUFF_STRUCT *msgBuffData, SYS_STRUCT *sysData, \
                                           RTC_DATA *rtcData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData);


/**
 * Function to send a RF message
 * @param 1 - RF_STRUCT pointer
 * @param 2 - SYS_STRUCT pointer
 * @param 3 - RTC_STRUCT pointer
 * @param 4 - PROF_STRUCT pointer
 * @param 5 - ALARM_STRUCT pointer
 * @param 6 - PWR_CONSUME_STRUCT pointer
 */
__attribute__((mips16)) void RF_SendMsg(RF_STRUCT *rfData, MSGBUFF_STRUCT *msgBuffData, SYS_STRUCT *sysData, RTC_DATA *rtcData,\
                                               PROF_STRUCT *profData, ALARM_STRUCT *alrData, PWR_CONSUME_STRUCT *pwrData, PM_STRUCT *pmData);

#ifdef RF_RFM22B
/**
 * Function to implement the State-Machine for the RF communication
 * @param 1 - RF_STRUCT pointer
 * @param 2 - SYS_STRUCT pointer
 * @param 3 - RTC_STRUCT pointer
 * @param 4 - PROF_STRUCT pointer
 */
__attribute__((mips16)) void RF_RFM22B_SttMachine(RF_STRUCT *rfData, MSGBUFF_STRUCT *msgBuffData, SYS_STRUCT *sysData, \
                                                  RTC_DATA *rtcData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData, PM_STRUCT *pmData);
#endif
#ifdef RF_RFM69HCW
/**
 * Function to implement the State-Machine for the RF communication
 * @param 1 - RF_STRUCT pointer
 * @param 2 - SYS_STRUCT pointer
 * @param 3 - RTC_STRUCT pointer
 * @param 4 - PROF_STRUCT pointer
 */
__attribute__((mips16)) void RF_RFM69HCW_SttMachine(RF_STRUCT *rfData, MSGBUFF_STRUCT *msgBuffData, SYS_STRUCT *sysData, \
                                                    RTC_DATA *rtcData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData);
#endif
#ifdef RF_RFM95W
/**
 * Function to implement the State-Machine for the RF communication
 * @param 1 - RF_STRUCT pointer
 * @param 2 - SYS_STRUCT pointer
 * @param 3 - RTC_STRUCT pointer
 * @param 4 - PROF_STRUCT pointer
 */
__attribute__((mips16)) void RF_RFM95W_SttMachine(RF_STRUCT *rfData, MSGBUFF_STRUCT *msgBuffData, SYS_STRUCT *sysData, \
                                                    RTC_DATA *rtcData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData);
#endif


#ifdef RF_RFM22B
/**
 * Function to Set a Software Reset on the RF module
 * @param 1 - RF_STRUCT pointer
 */
void RF_RFM22B_Reset(RF_STRUCT *rfData);
#endif
#ifdef RF_RFM69HCW
/**
 * Function to Set a Software Reset on the RF module
 * @param 1 - RF_STRUCT pointer
 */
void RF_RFM69HCW_Reset(RF_STRUCT *rfData);
#endif
#ifdef RF_RFM95W
/**
 * Function to Set a Software Reset on the RF module
 * @param 1 - RF_STRUCT pointer
 */
void RF_RFM95W_Reset(RF_STRUCT *rfData);
#endif


/**
 * Function to clear the RF buffer
 */
__attribute__((mips16)) void RF_ClrMsg(RFMSG_STRUCT *msg);


/**
 * Function to calculate the checksum of buffer of x bytes
 */
__attribute__((mips16)) uint8_t RF_CksCalc(RFMSG_STRUCT *msg);



/* PWM Functions */

/**
 * Function to config the dimming
 * @param 1 - SYS_STRUCT pointer
 */
__attribute__((mips16)) void PWM_ConfigDimming(SYS_STRUCT *sysData);


/**
 * Function to set the dimming/duty
 * @param 1 - SYS_STRUCT pointer
 */
__attribute__((mips16)) void PWM_Dimming(SYS_STRUCT *sysData);


/**
 * Function to save the current dimming/duty
 * @param 1 - SYS_STRUCT pointer
 */
__attribute__((mips16)) void PWM_SaveAuxDimming(SYS_STRUCT *sysData);


/* RTC_EEPROM Functions */

/**
 * Function to load the system with the saved data
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - MEMS_STRUCT pointer
 * @param 3 - PROF_STRUCT pointer
 * @param 4 - ASTRO_STRUCT pointer
 * @param 5 - ALARM_STRUCT pointer
 * @param 6 - MAX_I_CAL_STRUCT pointer
 * @param 7 - PWR_CONSUME_STRUCT pointer
 */
__attribute__((mips16)) void RTC_MCP7952x_GetSavedData(SYS_STRUCT *sysData, MEMS_STRUCT *memsData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData, ALARM_STRUCT *alrData,\
                                                       PWR_LF_CAL_STRUCT *pwrLFcalData, PWR_CONSUME_STRUCT *pwrCalcData, RF_STRUCT *rfData);

/**
 * Function to compensate the RTCC using calibration register, relation between temperature and frenquency clock
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - Current Hours
 */
__attribute__((mips16)) void RTC_MCP7952x_TempComp(SYS_STRUCT *sysData, uint8_t hours);



/* System Functions */

/**
 * Function to handle with system updates - clock, profiles or configs
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - RTC_DATA pointer
 * @param 3 - PROF_STRUCT pointer
 * @param 4 - ASTRO_STRUCT pointer
 * @param 5 - MEMS_STRUCT pointer
 * @param 6 - ALARM_STRUCT pointer
 * @param 7 - PWR_LF_CAL_STRUCT pointer
 * @param 8 - PWR_CONSUME_STRUCT pointer
 */
__attribute__((mips16)) void SYS_Update(SYS_STRUCT *sysData, RTC_DATA *rtcData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData,\
                                         MEMS_STRUCT *memsData, ALARM_STRUCT *alrData, PWR_LF_CAL_STRUCT *pwrLFcalData);


/**
 * Function to get the mean values from the ADC and normalize those values
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - ADC_STRUCT pointer
 */
__attribute__((mips16)) void SYS_MeanADCcalc(SYS_STRUCT *sysData, ADC_STRUCT *adcData);


/**
 * Function to normalize Voltage value - convert from ADC (0-1024) to voltage
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - mean value corresponding to the voltage
 */
__attribute__((mips16)) void SYS_VoltDCCalc(SYS_STRUCT *sysData, uint16_t val);


/**
 * Function to normalize LDR value - convert from ADC (0-1024) to voltage
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - mean value corresponding to Lux from the LDR sensor
 */
__attribute__((mips16)) void SYS_LDRcalc(SYS_STRUCT *sysData, uint16_t val);


/**
 * Function to normalize Temperature value - convert from ADC (0-1024) to voltage
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - mean value corresponding to the temperature from the sensor
 */
__attribute__((mips16)) void SYS_MCP9700Acalc(SYS_STRUCT *sysData, uint16_t val);


/**
 * Function to implement system state-machine
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PROF_STRUCT pointer
 * @param 3 - RTC_DATA pointer
 * @param 4 - ALARM_STRUCT pointer
 */
__attribute__((mips16)) void SYS_SttMachine(SYS_STRUCT *sysData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData, RTC_DATA *rtcData, ALARM_STRUCT *alrData,\
                                            RF_STRUCT *rfData, PWR_LF_CAL_STRUCT *pwrLFcalData, PWR_CONSUME_STRUCT *pwrData, DALI_STRUCT *daliData);


/**
 * Function to search if the system should be inside of a profile
 * @param 1 - PROF_STRUCT pointer
 * @param 2 - RTC_DATA pointer
 * @return  - Flag that indicates a profile change
 */
__attribute__((mips16)) uint8_t SYS_ProfCheck(PROF_STRUCT *profData, RTC_DATA *rtcData);


/**
 * Function to check if there is any alarm situation
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - MEMS_STRUCT pointer
 * @param 3 - ALARM_STRUCT pointer
 * @param 4 - RF_STRUCT pointer
 * @param 5 - PWR_LF_CAL_STRUCT pointer
 * @param 6 - PWR_CONSUME_STRUCT pointer
 */
__attribute__((mips16)) void SYS_CheckAlarm(SYS_STRUCT *sysData, MEMS_STRUCT *memsData, ALARM_STRUCT *alrData, RF_STRUCT *rfData,\
                                            PWR_LF_CAL_STRUCT *pwrLFcalData, PWR_CONSUME_STRUCT *pwrData);


/**
 * Function to check if there is a Lamp alarm
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PWR_LF_CAL_STRUCT pointer
 * @param 3 - PWR_CONSUME_STRUCT pointer
 * @return - 1 for alarm detected 0 for no alarm
 */
__attribute__((mips16)) uint8_t checkLampAlarm(SYS_STRUCT *sysData, PWR_LF_CAL_STRUCT *pwrLFcalData, PWR_CONSUME_STRUCT *pwrData);


/**
 * Function to start the calibration of the power consumption to detect a lamp failure
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PWR_LF_CAL_STRUCT pointer
 */
__attribute__((mips16)) void SYS_PwrLFset(SYS_STRUCT *sysData, PWR_LF_CAL_STRUCT *pwrLFcalData);


/**
 * Function to calibrate the power consumption to detect a lamp failure
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PWR_LF_CAL_STRUCT pointer
 * @param 3 - PWR_CONSUME_STRUCT pointer
 */
__attribute__((mips16)) void SYS_PwrLFcal(SYS_STRUCT *sysData, PWR_LF_CAL_STRUCT *pwrLFcalData, PWR_CONSUME_STRUCT *pwrData);


/**
 * Function to calculate power conumption
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PWR_CONSUME_STRUCT pointer
 * @param 3 - PM_STRUCT pointer
 */
__attribute__((mips16)) void SYS_calcKWh(PWR_CONSUME_STRUCT *pwrData);



/* Power-Meter Funcions */

/* Function to process the messages received of the Power-Meter */
__attribute__((mips16)) int8_t PM_MCP39F501_ProcessMsg(SYS_STRUCT *sysData, UART_STRUCT *uartData,\
                                                       PM_STRUCT *pmData, PWR_CONSUME_STRUCT *pwrData);


/* Function to calibrate the Power-Meter */
__attribute__((mips16)) uint8_t PM_MCP39F501_Calib( PM_STRUCT *pmData, SYS_STRUCT *sysData);


/* Function to send the messages for the Power-Meter */
__attribute__((mips16)) void PM_MCP39F501_SendMsg(PM_STRUCT *pmData, SYS_STRUCT *sysData);


/**
 * Function to normalize measures of the Power-meter
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PWR_CONSUME_STRUCT pointer
 * @param 3 - PM_STRUCT pointer
 */
__attribute__((mips16)) int8_t PM_MedianCalc(SYS_STRUCT *sysData, PWR_CONSUME_STRUCT *pwrData, PM_STRUCT *pmData);


/**
 * Function to manage the power-meter
 * @param 1 - SYS_STRUCT pointer
 * @param 2 - PM_STRUCT pointer
 */
__attribute__((mips16)) void PM_SttMachine(SYS_STRUCT *sysData, PM_STRUCT *pmData, RF_STRUCT *rfData);


/**
 * Function to calculate the get a more accurate value of an ADC channel
 * @param 1 - buffer pointer (buffer must have 9 samples)
 */
__attribute__((mips16)) uint32_t mediana9(uint32_t *buff);



/* Check if the lights should be OFF or ON, according with the astronomical clock configurations */
__attribute__((mips16)) uint8_t SYS_AstroClkCheck(ASTRO_STRUCT *astroData, RTC_DATA *rtcData);


/* Astronomical Clock - Check if the dimming state has changed */
__attribute__((mips16)) void SYS_AstroClk_DimChg(ASTRO_STRUCT *astroData, SYS_STRUCT *sysData, uint8_t stt);


/* LDR Control*/
__attribute__((mips16)) void SYS_ldrSPctrl(SYS_STRUCT *sysData);


/* Control the system within 1min interval - LDR and clock update */
__attribute__((mips16)) void SYS_1minCtrl(SYS_STRUCT *sysData, RTC_DATA *rtcData, PROF_STRUCT *profData, RF_STRUCT *rfData, PWR_LF_CAL_STRUCT *pwrLFcalData);


/* Update system within 1s interval, if configured send debug information by serial port */
__attribute__((mips16)) void SYS_1sUpdate(RF_STRUCT *rfData, SYS_STRUCT *sysData, RTC_DATA *rtcData, PROF_STRUCT *profData, ASTRO_STRUCT *astroData,\
                                          PWR_LF_CAL_STRUCT *pwrLFcalData, ALARM_STRUCT *alrData, PWR_CONSUME_STRUCT *pwrData, PM_STRUCT *pmData);


/**
 * Function to implement 1h system updates
 * @param 1 - SYS_STRUCT pointer 
 * @param 2 - RF_STRUCT pointer
 */
__attribute__((mips16)) void SYS_1hUpdate(SYS_STRUCT *sysData, RF_STRUCT *rfData);


/* Encryption functions */
__attribute__((mips16)) uint8_t AES128_Encrypt(uint8_t *buff, uint8_t buffLen, uint8_t *buffEnc, void *sessionKey);


__attribute__((mips16)) uint8_t AES128_Decrypt(uint8_t *buffEnc, uint8_t buffLen, uint8_t *buffDec, void *sessionKey);


__attribute__((mips16)) void SYS_ClearBuff(uint8_t *buff, uint8_t len);

/**
 *VI methods 
 */
__attribute__((mips16)) void SYS_calcVolume(PWR_CONSUME_STRUCT *pwrData);

__attribute__((mips16)) void CalcFlowSum(void);

__attribute__((mips16)) void ConvertLittleToBigEndian(uint8_t *b, uint8_t index);

__attribute__((mips16)) uint16_t CRC16(uint8_t *nData, uint16_t wLength);


#endif

