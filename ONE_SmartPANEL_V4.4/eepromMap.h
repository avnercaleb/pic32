/* 
 * File:   eepromMap.h
 * Author: Dell
 *
 * Created on 15 de Fevereiro de 2013, 12:32
 */

#ifndef EEPROMMAP_H
#define	EEPROMMAP_H

/******************************************************************************/
/* EEPROM Address map                                                         */
/******************************************************************************/
#define UINT8_SIZE              1
#define UINT16_SIZE             2
#define INT16_SIZE              2
#define UINT32_SIZE             4
#define DOUBLE_SIZE             4

#define NW_SIZE                 4
#define PROF_SIZE               20      /* 20*UINT8 */
#define CONF_SIZE               6
#define REST_DATA_SIZE          13
#define PIR_DATA_SIZE           5       /* UINT8_SIZE+2*UINT16_SIZE */
#define ALARM_DATA_SIZE         /* TODO <definir...> */
#define PWR_LF_CAL_DATA_SIZE    11      /* UINT8_SIZE+UINT16_SIZE+2*DOUBLE_SIZE */
#define MEMS_DATA_SIZE          3       /* 3*UINT8_SIZE */
#define POWER_CALC_DATA_SIZE    9       /* 3*DOUBLE_SIZE+1*UINT8_SIZE */
#define ADDON_CONF_DATA_SIZE    4       /* 4*UINT8_SIZE */
#define ASTRO_CLK_DATA_SIZE     12      /* 6*UINT8_SIZE+3*UINT16_SIZE */
#define POWER_FREQ_DATA_SIZE    2
#define AN_QUADRATIC_DATA_SIZE  4 
#define AN_SLOPE_DATA_SIZE      4
#define AN_INTERCEPT_DATA_SIZE  4

#define START_STRUCT_ADD        0x00

#define NET_ADD             START_STRUCT_ADD
#define SN_ADD              NET_ADD+UINT16_SIZE
#define SYS_STT_ADD         SN_ADD+UINT16_SIZE         
#define PROF_STT_ADD        SYS_STT_ADD+UINT8_SIZE
#define SET_LDR_ADD         PROF_STT_ADD+UINT8_SIZE
#define LDR_CTRL_ADD        SET_LDR_ADD+UINT16_SIZE
#define TTL_MAX_ADD         LDR_CTRL_ADD+UINT8_SIZE
#define DUTY_TMP_ADD        TTL_MAX_ADD+UINT8_SIZE
#define DUTY_INIT_ADD       DUTY_TMP_ADD+UINT16_SIZE
#define DUTY_AUX_ADD        DUTY_INIT_ADD+UINT16_SIZE
#define DUTY_FACT_ADD       DUTY_AUX_ADD+UINT16_SIZE
#define LDR_OFFSET_ADD      DUTY_FACT_ADD+DOUBLE_SIZE
#define WH_ADD              LDR_OFFSET_ADD+UINT8_SIZE
#define PIR_ADD             WH_ADD+UINT32_SIZE
#define PIR_ENABLE_ADD      PIR_ADD+PIR_DATA_SIZE+4         /* Strange situation resolved with this 4 positions */
#define DEBUG_ADD           PIR_ENABLE_ADD+UINT8_SIZE
#define TLED_ENABLE_ADD     DEBUG_ADD+UINT8_SIZE
#define ENC_ADD             TLED_ENABLE_ADD+UINT8_SIZE
#define RF_FREQ_ADD         ENC_ADD+UINT8_SIZE
#define PROF_ADD            RF_FREQ_ADD+UINT8_SIZE
#define MEMS_ADD            PROF_ADD+PROF_SIZE
#define CURR_OS_ADD         MEMS_ADD+MEMS_DATA_SIZE
#define PWR_LF_CAL_ADD      CURR_OS_ADD+UINT16_SIZE

#define POWER_CALC_ADD      PWR_LF_CAL_ADD+PWR_LF_CAL_DATA_SIZE
#define ASTRO_CLK_ADD       POWER_CALC_ADD+POWER_CALC_DATA_SIZE
#define PWR_FREQ_ADD        ASTRO_CLK_ADD+ASTRO_CLK_DATA_SIZE

#define AN1_QUADRATIC_ADD   PWR_FREQ_ADD+DOUBLE_SIZE
#define AN1_SLOPE_ADD       AN1_QUADRATIC_ADD+DOUBLE_SIZE
#define AN1_INTERCEPT_ADD   AN1_SLOPE_ADD+DOUBLE_SIZE

/* Alarms setpoints definitions */
#define ALARM_TLAMP_SP      PWR_FREQ_ADD+UINT8_SIZE
#define ALARM_TPCB_SP       ALARM_TLAMP_SP+2*UINT8_SIZE
#define ALARM_STAB_SP       ALARM_TPCB_SP+2*UINT8_SIZE
#define ALARM_VOLT_SP       ALARM_STAB_SP+2*UINT8_SIZE
#define ALARM_CURR_SP       ALARM_VOLT_SP+2*UINT16_SIZE
#define ALARM_LDR_SP        ALARM_CURR_SP+UINT16_SIZE
//#define ALARM_LAMP_SP     -> the configuration needed is the max current (when the network is configured, the max current is calibrated)

#endif	/* EEPROMMAP_H */

