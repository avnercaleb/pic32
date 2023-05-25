/*
 * File:   M1_RF.c
 * Author: André Gomes
 *
 * Created on 6 de Maio de 2015, 11:03
 */

#include <stdint.h>
#include "M1_RF.h"


#if AES128_ENC

__attribute__((mips16)) uint8_t SRF_msgType2Len(uint8_t msgT)
{
    uint8_t newL;

    switch(msgT)
    {
        case CONF_NET:
            newL = CONF_NET_LEN;
            break;
        case ACK_CONF_NET:
            newL = ACK_CONF_NET_LEN;
            break;
        case CAL_UPDATE:
            newL = CAL_UPDATE_LEN;
            break;
        case CONF_PROFILE:
            newL = CONF_PROFILE_LEN;
            break;
        case ACK_CONF_PROFILE:
            newL = ACK_CONF_PROFILE_LEN;
            break;
        case ASK_PROFILE:
            newL = ASK_PROFILE_LEN;
            break;
        case ANS_PROFILE:
            newL = ANS_PROFILE_LEN;
            break;
        case CONF_ASTOCLK:
            newL = CONF_ASTOCLK_LEN;
            break;            
        case ACK_CONF_ASTOCLK:
            newL = ACK_CONF_ASTOCLK_LEN;
            break;             
        case CONF_PWM:
            newL = CONF_PWM_LEN;
            break;
        case ACK_CONF_PWM:
            newL = ACK_CONF_PWM_LEN;
            break;
        case CONF_GENERAL:
            newL = CONF_GENERAL_LEN;
            break;
        case ACK_CONF_GENERAL:
            newL = ACK_CONF_GENERAL_LEN;
            break;
        case ASK_TELEM_EXT:
            newL = ASK_TELEM_EXT_LEN;
            break;
        case ANS_TELEM_EXT:
            newL = ANS_TELEM_EXT_LEN;
            break;
        case CONF_SENSORS:
            newL = CONF_SENSORS_LEN;
            break;
        case ACK_CONF_SENSORS:
            newL = ACK_CONF_SENSORS_LEN;
            break;
        case CONF_ALARMS:
            newL = CONF_ALARMS_LEN;
            break;
        case ACK_CONF_ALARMS:
            newL = ACK_CONF_ALARMS_LEN;
            break;
        case CONF_ADDON:
            newL = CONF_ADDON_LEN;
            break;
        case ACK_CONF_ADDON:
            newL = ACK_CONF_ADDON_LEN;
            break;
        case SYS_MONITORING:
            newL = SYS_MONITORING_LEN;
            break;
        case ANS_SYS_MONITORING:
            newL = ANS_SYS_MONITORING_LEN;
            break;
        case SYS_TOTALTEL            :
            newL = SYS_TOTALTEL_LEN;
            break;
        case ANS_SYS_TOTALTEL:
            newL = ANS_SYS_TOTALTEL_LEN;
            break;
        case PIR_CONTROL:
            newL = PIR_CONTROL_LEN;
            break;
        case ALARM_MSG:
            newL = ALARM_MSG_LEN;
            break;
        case ASK_WHOIS:
            newL = ASK_WHOIS_LEN;
            break;
        case ANS_WHOIS:
            newL = ANS_WHOIS_LEN;
            break;
        case ASK_WHAT_CLK:
            newL = ASK_WHAT_CLK_LEN;
            break;
        case ANS_WHAT_CLK:
            newL = ANS_WHOIS_LEN;
            break;
        default:
            newL = 0;
            break;
    }

    return newL;
}


#endif
