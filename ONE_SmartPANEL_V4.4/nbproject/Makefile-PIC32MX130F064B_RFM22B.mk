#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-PIC32MX130F064B_RFM22B.mk)" "nbproject/Makefile-local-PIC32MX130F064B_RFM22B.mk"
include nbproject/Makefile-local-PIC32MX130F064B_RFM22B.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC32MX130F064B_RFM22B
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=configuration_bits.c interrupts.c main.c system.c user.c UART.c delay.c Timers.c SPI.c RTC_MCP7952X.c PWM.c RF_RFM22B.c adc.c exceptions.c MEMS_LIS331DL.c DALI.c AES/AES_ECB_PIC32.c RF_RFM69HCW.c PM_MCP39F511.c RF_RFM95W.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/user.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/Timers.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/RTC_MCP7952X.o ${OBJECTDIR}/PWM.o ${OBJECTDIR}/RF_RFM22B.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/exceptions.o ${OBJECTDIR}/MEMS_LIS331DL.o ${OBJECTDIR}/DALI.o ${OBJECTDIR}/AES/AES_ECB_PIC32.o ${OBJECTDIR}/RF_RFM69HCW.o ${OBJECTDIR}/PM_MCP39F511.o ${OBJECTDIR}/RF_RFM95W.o
POSSIBLE_DEPFILES=${OBJECTDIR}/configuration_bits.o.d ${OBJECTDIR}/interrupts.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/user.o.d ${OBJECTDIR}/UART.o.d ${OBJECTDIR}/delay.o.d ${OBJECTDIR}/Timers.o.d ${OBJECTDIR}/SPI.o.d ${OBJECTDIR}/RTC_MCP7952X.o.d ${OBJECTDIR}/PWM.o.d ${OBJECTDIR}/RF_RFM22B.o.d ${OBJECTDIR}/adc.o.d ${OBJECTDIR}/exceptions.o.d ${OBJECTDIR}/MEMS_LIS331DL.o.d ${OBJECTDIR}/DALI.o.d ${OBJECTDIR}/AES/AES_ECB_PIC32.o.d ${OBJECTDIR}/RF_RFM69HCW.o.d ${OBJECTDIR}/PM_MCP39F511.o.d ${OBJECTDIR}/RF_RFM95W.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/user.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/Timers.o ${OBJECTDIR}/SPI.o ${OBJECTDIR}/RTC_MCP7952X.o ${OBJECTDIR}/PWM.o ${OBJECTDIR}/RF_RFM22B.o ${OBJECTDIR}/adc.o ${OBJECTDIR}/exceptions.o ${OBJECTDIR}/MEMS_LIS331DL.o ${OBJECTDIR}/DALI.o ${OBJECTDIR}/AES/AES_ECB_PIC32.o ${OBJECTDIR}/RF_RFM69HCW.o ${OBJECTDIR}/PM_MCP39F511.o ${OBJECTDIR}/RF_RFM95W.o

# Source Files
SOURCEFILES=configuration_bits.c interrupts.c main.c system.c user.c UART.c delay.c Timers.c SPI.c RTC_MCP7952X.c PWM.c RF_RFM22B.c adc.c exceptions.c MEMS_LIS331DL.c DALI.c AES/AES_ECB_PIC32.c RF_RFM69HCW.c PM_MCP39F511.c RF_RFM95W.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-PIC32MX130F064B_RFM22B.mk dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX130F064B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/UART.o: UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/Timers.o: Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timers.o.d 
	@${RM} ${OBJECTDIR}/Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/Timers.o.d" -o ${OBJECTDIR}/Timers.o Timers.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/SPI.o: SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/SPI.o.d" -o ${OBJECTDIR}/SPI.o SPI.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RTC_MCP7952X.o: RTC_MCP7952X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o.d 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o 
	@${FIXDEPS} "${OBJECTDIR}/RTC_MCP7952X.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RTC_MCP7952X.o.d" -o ${OBJECTDIR}/RTC_MCP7952X.o RTC_MCP7952X.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/PWM.o: PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${RM} ${OBJECTDIR}/PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RF_RFM22B.o: RF_RFM22B.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o 
	@${FIXDEPS} "${OBJECTDIR}/RF_RFM22B.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RF_RFM22B.o.d" -o ${OBJECTDIR}/RF_RFM22B.o RF_RFM22B.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/adc.o: adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/exceptions.o: exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${RM} ${OBJECTDIR}/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/MEMS_LIS331DL.o: MEMS_LIS331DL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o.d 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o 
	@${FIXDEPS} "${OBJECTDIR}/MEMS_LIS331DL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/MEMS_LIS331DL.o.d" -o ${OBJECTDIR}/MEMS_LIS331DL.o MEMS_LIS331DL.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/DALI.o: DALI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DALI.o.d 
	@${RM} ${OBJECTDIR}/DALI.o 
	@${FIXDEPS} "${OBJECTDIR}/DALI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/DALI.o.d" -o ${OBJECTDIR}/DALI.o DALI.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/AES/AES_ECB_PIC32.o: AES/AES_ECB_PIC32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/AES" 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o.d 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o 
	@${FIXDEPS} "${OBJECTDIR}/AES/AES_ECB_PIC32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/AES/AES_ECB_PIC32.o.d" -o ${OBJECTDIR}/AES/AES_ECB_PIC32.o AES/AES_ECB_PIC32.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RF_RFM69HCW.o: RF_RFM69HCW.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o 
	@${FIXDEPS} "${OBJECTDIR}/RF_RFM69HCW.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RF_RFM69HCW.o.d" -o ${OBJECTDIR}/RF_RFM69HCW.o RF_RFM69HCW.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/PM_MCP39F511.o: PM_MCP39F511.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o.d 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o 
	@${FIXDEPS} "${OBJECTDIR}/PM_MCP39F511.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/PM_MCP39F511.o.d" -o ${OBJECTDIR}/PM_MCP39F511.o PM_MCP39F511.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RF_RFM95W.o: RF_RFM95W.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o 
	@${FIXDEPS} "${OBJECTDIR}/RF_RFM95W.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RF_RFM95W.o.d" -o ${OBJECTDIR}/RF_RFM95W.o RF_RFM95W.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
else
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/user.o: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	@${FIXDEPS} "${OBJECTDIR}/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/UART.o: UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/Timers.o: Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timers.o.d 
	@${RM} ${OBJECTDIR}/Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/Timers.o.d" -o ${OBJECTDIR}/Timers.o Timers.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/SPI.o: SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/SPI.o.d" -o ${OBJECTDIR}/SPI.o SPI.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RTC_MCP7952X.o: RTC_MCP7952X.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o.d 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o 
	@${FIXDEPS} "${OBJECTDIR}/RTC_MCP7952X.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RTC_MCP7952X.o.d" -o ${OBJECTDIR}/RTC_MCP7952X.o RTC_MCP7952X.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/PWM.o: PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${RM} ${OBJECTDIR}/PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RF_RFM22B.o: RF_RFM22B.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o 
	@${FIXDEPS} "${OBJECTDIR}/RF_RFM22B.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RF_RFM22B.o.d" -o ${OBJECTDIR}/RF_RFM22B.o RF_RFM22B.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/adc.o: adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/exceptions.o: exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${RM} ${OBJECTDIR}/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/MEMS_LIS331DL.o: MEMS_LIS331DL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o.d 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o 
	@${FIXDEPS} "${OBJECTDIR}/MEMS_LIS331DL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/MEMS_LIS331DL.o.d" -o ${OBJECTDIR}/MEMS_LIS331DL.o MEMS_LIS331DL.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/DALI.o: DALI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DALI.o.d 
	@${RM} ${OBJECTDIR}/DALI.o 
	@${FIXDEPS} "${OBJECTDIR}/DALI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/DALI.o.d" -o ${OBJECTDIR}/DALI.o DALI.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/AES/AES_ECB_PIC32.o: AES/AES_ECB_PIC32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/AES" 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o.d 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o 
	@${FIXDEPS} "${OBJECTDIR}/AES/AES_ECB_PIC32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/AES/AES_ECB_PIC32.o.d" -o ${OBJECTDIR}/AES/AES_ECB_PIC32.o AES/AES_ECB_PIC32.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RF_RFM69HCW.o: RF_RFM69HCW.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o 
	@${FIXDEPS} "${OBJECTDIR}/RF_RFM69HCW.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RF_RFM69HCW.o.d" -o ${OBJECTDIR}/RF_RFM69HCW.o RF_RFM69HCW.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/PM_MCP39F511.o: PM_MCP39F511.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o.d 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o 
	@${FIXDEPS} "${OBJECTDIR}/PM_MCP39F511.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/PM_MCP39F511.o.d" -o ${OBJECTDIR}/PM_MCP39F511.o PM_MCP39F511.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
${OBJECTDIR}/RF_RFM95W.o: RF_RFM95W.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o 
	@${FIXDEPS} "${OBJECTDIR}/RF_RFM95W.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM22B_ -Wall -MMD -MF "${OBJECTDIR}/RF_RFM95W.o.d" -o ${OBJECTDIR}/RF_RFM95W.o RF_RFM95W.c    -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -Os -mips16 -o dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--gc-sections,--report-mem 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -Os -mips16 -o dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_PIC32MX130F064B_RFM22B=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--gc-sections,--report-mem 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ONE_SmartPANEL_V4.0_V2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PIC32MX130F064B_RFM22B
	${RM} -r dist/PIC32MX130F064B_RFM22B

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
