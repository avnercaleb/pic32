/* 
 * File:   PW_MCP39F501.h
 * Author: André Gomes
 *
 * Created on 26 de Fevereiro de 2014, 10:34
 */

#ifndef PW_MCP39F501_H
#define	PW_MCP39F501_H


#include <plib.h>
#include <stdint.h>

#include "SPI.h"
#include "delay.h"
#include "eepromMap.h"


#define RESET_PM_OFF        LATAbits.LATA0=1    /*mPORTAClearBits(BIT_0)*/
#define RESET_PM_ON         LATAbits.LATA0=0    /*mPORTASetBits(BIT_0)*/

/* Timings for the PM */
#define PM_TIMEOUT_CAL      30      /* Time for the timeout of the calibration in seconds */
#define PM_TIME2INIT        1       /* Time to reset the PM */
#define PM_TIME2START       2       /* Time to start the interaction with the PM */

/* States for the Power-Meter State Machine*/
#define PM_STT_WAIT         0
#define PM_STT_INIT         1
#define PM_STT_CAL          2
#define PM_STT_READVALS     3

/* Defines for Save to Flash action */
#define PM_SAVE2FLASH_DISABLE   0
#define PM_SAVE2FLASH_WAIT      1
#define PM_SAVE2FLASH_READY     2
#define PM_SAVE2FLASH_DONE      3


/* Absolute Max values for the current and voltage */
#define MAXMAX_CURRENT      110000
#define MAXMAX_VOLT         5000

#define PM_ERROR            -1
#define PM_OK               0


/* Protocol defines */
#define PM_HEADER           0xA5

#define PM_ACK              0x06
#define PM_NACK             0x15

#define PM_HEADER_ANS_LEN       2
#define PM_ACK_NACK_LEN         1

#define PM_DATAREAD_LEN         4*DOUBLE_SIZE+4*UINT16_SIZE
#define PM_V_HZ_ANALOG_PF_LEN   3*UINT16_SIZE+INT16_SIZE
#define PM_A_W_VAR_VA_LEN       4*DOUBLE_SIZE

#define PM_SET_GAINS_B2W        8       /* Bytes to write in the command to set the Gains */
//#define PM_SET_OFFSET_B2W       12    /* Bytes to write in the command to set the offsets */
#define PM_SET_OFFSET_B2W       16      /* Bytes to write in the command to set the offsets */
#define PM_SYSTEM_CONF_B2W      4       /* Bytes to write in the command to set the System Configurations */

#define PM_W_16BIT_REG_B2W      2       /* Bytes to write in a 2 bytes register */    

#define PM_READ_VALS_B2R        24      /* Bytes to read in the command to read values */
#define PM_R_16BIT_REG_B2R      2       /* Bytes to read in a 2 bytes register */      

#define PM_PCBTEMP_POS          7       /* The pcb temperature position in the message */

#define PM_PWR_DIV              0.00001


/* Messages length */
#define PM_READVALS_LEN         8
#define PM_CALTEMP_LEN          10
#define PM_SET_TGT_RNG_LEN      26
#define PM_SET_TGT_FREQ_LEN     10
#define PM_CALIB_FREQ_LEN       4
#define PM_CALIB_ACT_LEN        4
#define PM_CALIB_REACT_LEN      4
#define PM_SET_GAINS_LEN        16
#define PM_SET_GAIN_FREQ_LEN    10
//#define PM_SET_OFFSET_LEN       20
#define PM_SET_OFFSET_LEN       24      /* Calibration from the Offset Current to the Phase compensation */
#define PM_SAVE_REG_FLASH_LEN   4
#define PM_SYSTEM_CONF_LEN      12


/* Msg ID */
#define PM_READVALS_ID          1
#define PM_CALTEMP_ID           2
#define PM_SET_TGT_RNG_ID       3
#define PM_SET_TGT_FREQ_ID      4
#define PM_CALIB_FREQ_ID        5
#define PM_CALIB_ACT_ID         6
#define PM_CALIB_REACT_ID       7
#define PM_READ_CALGAINS_ID     8
#define PM_SET_GAINS_ID         9
#define PM_SET_OFFSET_ID        10
#define PM_SAVE_REG_FLASH_ID    11
#define PM_SYSCONF_ADC_OFF_ID   12
#define PM_SYSCONF_ADC_ON_ID    13


/* States for the calibration process */
#define PM_SET_TGT_RNG_STT      0
#define PM_SET_GAINS_STT        1
#define PM_SET_OFFSET_STT       2
#define PM_SYSCONF_ADC_OFF_STT  3
#define PM_SYSCONF_ADC_ON_STT   4

/* Extended calibration - when used should be renumbered */
#define PM_SET_TGT_FREQ_STT     5
#define PM_AUTO_CALFREQ_STT     6
#define PM_AUTO_CALACT_STT      7
#define PM_AUTO_CALREACT_STT    8
#define PM_CALIBTEMP_STT        9

#define PM_END_CAL              0xFF


/* Instruction Set */ 
#define PM_READ_N           0x4E 
#define PM_WRITE_N          0x4D 
#define PM_SET_ADD_PT       0x41
#define PM_SAVE_REG_FLASH   0x53 
#define PM_EEPROM_READ_P    0x42 
#define PM_EEPROM_WRITE_P   0x50 
#define PM_EEPROM_ERASE     0x4F 
#define PM_AUTO_CAL_G       0x5A 
#define PM_AUTO_CAL_RG      0x7A 
#define PM_AUTO_CAL_F       0x76


/****************/
/* Register MAP */
/****************/
/* 2 bytes - Once the MSB is always zero we use only the LSB */

/* Output Registers */
#define PM_ADDRESS_PT           0x00
#define PM_SYSTEM_STT           0x02
#define PM_SYSTEM_VERSION       0x04
#define PM_VOLTAGE_RMS          0x06
#define PM_LINE_FREQ            0x08
#define PM_ANALOG_IN_VOLTAGE    0x0A
#define PM_PWR_FACTOR           0x0C
#define PM_CURRENT_RMS          0x0E
#define PM_ACTIVE_PWR           0X12
#define PM_REACTIVE_PWR         0x16
#define PM_APPARENT_PWR         0x1A

/* Calibration Registers */
#define PM_CAL_DELIMITER        0x5E
#define PM_GAIN_CURR_RMS        0x60
#define PM_GAIN_VOLT_RMS        0x62
#define PM_GAIN_ACT_PWR         0x64
#define PM_GAIN_REACT_PWR       0x66
#define PM_OS_CURR_RMS          0x68
#define PM_OS_ACT_PWR           0x6C
#define PM_OS_REACT_PWR         0x70
#define PM_DC_OS_CURR           0x74
#define PM_PHASE_COMP           0x76
#define PM_APP_PWR_DIV          0x78

/* Design Configuration Registers */
#define PM_SYSTEM_CONF          0x7A
#define PM_EVENT_CONF           0x7E
#define PM_RANGE                0x82

/* Event Notification Registers */
#define PM_LINE_FREQ_REF        0x94

/* Temperature Compensation Registers */
#define PM_AMBTEMP_REF          0xCC


/* State of the received message */
#define PM_MSG_OK               1
#define PM_WAITING              0
#define PM_MSG_ERROR            -1

/* State of the sent message */
#define PM_NO_MSG_SENT          0
#define PM_MSG_SENT             1


/* System Configuration Options */
#define PM_SYSCONF_ADC_OFF      0x78
#define PM_SYSCONF_ADC_ON       0x00


/* Structure for Power-meter values */
typedef struct
{
    uint16_t    volt;               /* value read from PM */
    uint16_t    freq;               /* value read from PM */
    uint16_t    analogInVolt;       /* value read from PM */
    int16_t     pwrFact;            /* value read from PM */    
    uint32_t    curr;               /* value read from PM */ 
    uint32_t    actPwr;             /* value read from PM */
    uint32_t    reactPwr;           /* value read from PM */
    uint32_t    appPwr;             /* value read from PM */
    uint8_t     msgID;              /* ID of the message to be send - will be reset after the ACK/NACK */
    int8_t      msgAnsRcv;          /* Flag that indicates a received answer of the power-meter */
    uint8_t     msgLen;             /* Message len of the current message that will be send */
    uint8_t     msgSent;            /* Flag that indicates a sent message */
    uint8_t     buff[64];
    uint8_t     flagCal;            /* flag that indicate the state of the PM calibration */
    uint8_t     calTimeOut;         /* Flag that indicate the timeout of the calibration, after the timeout a new calibration will be realized */
    uint8_t     initCnt;            /* Set the time needed for starting the communication */
    uint8_t     initFlag;           /* Flag to indicate the first measurements */
    uint8_t     stt;                /* Current State of the Power-Meter */
    uint8_t     flagSave2Flash;     /* Flag to indicate and order to save the registers to the flash */
    //uint8_t     debugBuff[64];

}PM_STRUCT;



__attribute__((mips16)) void PM_MCP39F501_Init(void);


__attribute__((mips16)) uint8_t PM_MCP39F501_CksCalc(uint8_t *msg, uint8_t len);



#endif	/* PW_STPM10_H */

