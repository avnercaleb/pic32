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
ifeq "$(wildcard nbproject/Makefile-local-PIC32MX130F064B_RFM69HCW.mk)" "nbproject/Makefile-local-PIC32MX130F064B_RFM69HCW.mk"
include nbproject/Makefile-local-PIC32MX130F064B_RFM69HCW.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC32MX130F064B_RFM69HCW
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
	${MAKE}  -f nbproject/Makefile-PIC32MX130F064B_RFM69HCW.mk ${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/a47f796303d2f7dd8746d7c5c053184035597840 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/interrupts.o: interrupts.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/1ff8029c47810d8d42ff22ab8379d4473d0be956 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/391eabc1be1a0b4c4d15c906fac5fd1e1bc09025 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/e7fb632178e4ef6952fdb1708f1cb2c2d7221a17 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/user.o: user.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/13612f1bc3c7e199453317cf7c41426c6c4bf57 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/UART.o: UART.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/40058c3010b2f331210ac6adc712a88ce77bede6 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/delay.o: delay.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/b9651dd271a86ec1a20048a647f39bccce6a5739 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/Timers.o: Timers.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/93369289a1848ebeff3b0ac1d3d1ba707011d17d .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timers.o.d 
	@${RM} ${OBJECTDIR}/Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/Timers.o.d" -o ${OBJECTDIR}/Timers.o Timers.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/4f6b9203e16bec4e38032833532847689b86f936 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/SPI.o.d" -o ${OBJECTDIR}/SPI.o SPI.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RTC_MCP7952X.o: RTC_MCP7952X.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/b6fff57bb0e527d6d38a93ae6c6e10c55b8e992a .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o.d 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RTC_MCP7952X.o.d" -o ${OBJECTDIR}/RTC_MCP7952X.o RTC_MCP7952X.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/PWM.o: PWM.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/b4d52960e5bec9d970faaab45840cce6aaed0e83 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${RM} ${OBJECTDIR}/PWM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RF_RFM22B.o: RF_RFM22B.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/ded51011bff42b85c46718cd514e4fcf833b8e9b .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RF_RFM22B.o.d" -o ${OBJECTDIR}/RF_RFM22B.o RF_RFM22B.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/94e33ad171e9a3215086bd3ef72cc517f39bbfec .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/exceptions.o: exceptions.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/411a9f51673c84d2bc0fda38372ac5e42ba864fd .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${RM} ${OBJECTDIR}/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/MEMS_LIS331DL.o: MEMS_LIS331DL.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/1b67764aaf47b919ab556892459617a095de4abf .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o.d 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/MEMS_LIS331DL.o.d" -o ${OBJECTDIR}/MEMS_LIS331DL.o MEMS_LIS331DL.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/DALI.o: DALI.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/45a92d454ac42fd681945b744c0a203838877aac .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DALI.o.d 
	@${RM} ${OBJECTDIR}/DALI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/DALI.o.d" -o ${OBJECTDIR}/DALI.o DALI.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/AES/AES_ECB_PIC32.o: AES/AES_ECB_PIC32.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/45ae8dbf92e7bb671a7259d84905eb0f37c712c2 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}/AES" 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o.d 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/AES/AES_ECB_PIC32.o.d" -o ${OBJECTDIR}/AES/AES_ECB_PIC32.o AES/AES_ECB_PIC32.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RF_RFM69HCW.o: RF_RFM69HCW.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/e42c38553b75f9a1641388be577eb0f4ccd444dc .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RF_RFM69HCW.o.d" -o ${OBJECTDIR}/RF_RFM69HCW.o RF_RFM69HCW.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/PM_MCP39F511.o: PM_MCP39F511.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/32d04b8c1b18fa53726b872c410638162622ebd4 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o.d 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/PM_MCP39F511.o.d" -o ${OBJECTDIR}/PM_MCP39F511.o PM_MCP39F511.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RF_RFM95W.o: RF_RFM95W.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/201ca3234e196daba035ecdad9624e620c8e2255 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RF_RFM95W.o.d" -o ${OBJECTDIR}/RF_RFM95W.o RF_RFM95W.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/f331d56def770fef1b89040ca65121b20b1e186 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/configuration_bits.o.d" -o ${OBJECTDIR}/configuration_bits.o configuration_bits.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/interrupts.o: interrupts.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/49d6b5e44289a77c6d06dfbdcd91adb0c8ce6bbe .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/832a5648c890d4bd20b9a048b3ee4e1daa4c1efe .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/eb46e1488f8a7efd85ddc5929f67151cb119884 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/user.o: user.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/2d6ec887914922260177f7417e99094b4acd591e .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/user.o.d" -o ${OBJECTDIR}/user.o user.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/UART.o: UART.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/bb65e7212de2b2d792bb93a425438a606ef371b5 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/delay.o: delay.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/f5ac426bcdd36d62f1cd08a1f9e14150260217a6 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/Timers.o: Timers.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/7dac316924ac4b0730d7154ee8ad3efea918f352 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timers.o.d 
	@${RM} ${OBJECTDIR}/Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/Timers.o.d" -o ${OBJECTDIR}/Timers.o Timers.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/SPI.o: SPI.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/f991da65447b8945f9bc8034ac6a7429120b573e .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI.o.d 
	@${RM} ${OBJECTDIR}/SPI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/SPI.o.d" -o ${OBJECTDIR}/SPI.o SPI.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RTC_MCP7952X.o: RTC_MCP7952X.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/1a6b86b7e0ce91232e2cc3fd82011ccf5419f36f .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o.d 
	@${RM} ${OBJECTDIR}/RTC_MCP7952X.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RTC_MCP7952X.o.d" -o ${OBJECTDIR}/RTC_MCP7952X.o RTC_MCP7952X.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/PWM.o: PWM.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/a740c21a8a59474addbbe2bda2e7d959df21ae0 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${RM} ${OBJECTDIR}/PWM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RF_RFM22B.o: RF_RFM22B.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/588adb0434fca3dc38b29c20fb0b2b73eea0adbf .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM22B.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RF_RFM22B.o.d" -o ${OBJECTDIR}/RF_RFM22B.o RF_RFM22B.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/543ba2cbf5242a015fd365ab61bd3c88f9bd1cef .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/adc.o.d" -o ${OBJECTDIR}/adc.o adc.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/exceptions.o: exceptions.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/36b381e0033ae048f0e8f8984b626ae5bcb3f5de .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exceptions.o.d 
	@${RM} ${OBJECTDIR}/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/exceptions.o.d" -o ${OBJECTDIR}/exceptions.o exceptions.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/MEMS_LIS331DL.o: MEMS_LIS331DL.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/a2a68c26052eba47b79b61701a067d2e5dea0de4 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o.d 
	@${RM} ${OBJECTDIR}/MEMS_LIS331DL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/MEMS_LIS331DL.o.d" -o ${OBJECTDIR}/MEMS_LIS331DL.o MEMS_LIS331DL.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/DALI.o: DALI.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/4e11bb9cc43e240b80b701d60f12be8896b8640e .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DALI.o.d 
	@${RM} ${OBJECTDIR}/DALI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/DALI.o.d" -o ${OBJECTDIR}/DALI.o DALI.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/AES/AES_ECB_PIC32.o: AES/AES_ECB_PIC32.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/32bb90016f14be33f580121b25f6ca061e787327 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}/AES" 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o.d 
	@${RM} ${OBJECTDIR}/AES/AES_ECB_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/AES/AES_ECB_PIC32.o.d" -o ${OBJECTDIR}/AES/AES_ECB_PIC32.o AES/AES_ECB_PIC32.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RF_RFM69HCW.o: RF_RFM69HCW.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/bc012ddc3e8ee816fd6a748b817c0bd7f7a1cc90 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM69HCW.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RF_RFM69HCW.o.d" -o ${OBJECTDIR}/RF_RFM69HCW.o RF_RFM69HCW.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/PM_MCP39F511.o: PM_MCP39F511.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/775d5a4ec91d454ac215765642fcb85176a6b39b .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o.d 
	@${RM} ${OBJECTDIR}/PM_MCP39F511.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/PM_MCP39F511.o.d" -o ${OBJECTDIR}/PM_MCP39F511.o PM_MCP39F511.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/RF_RFM95W.o: RF_RFM95W.c  .generated_files/flags/PIC32MX130F064B_RFM69HCW/e71d4d6d1ae5102fd5c23932f0b56b37ad01f974 .generated_files/flags/PIC32MX130F064B_RFM69HCW/9bdc039ab25767db4821768bfc7d5cc7791804f2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o.d 
	@${RM} ${OBJECTDIR}/RF_RFM95W.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -Os -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -D_SUPPRESS_PLIB_WARNING -D_RFM69HCW_ -Wall -MP -MMD -MF "${OBJECTDIR}/RF_RFM95W.o.d" -o ${OBJECTDIR}/RF_RFM95W.o RF_RFM95W.c    -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -Os -mips16 -o ${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD3=1,--gc-sections,--report-mem 
	
else
${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -Os -mips16 -o ${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_PIC32MX130F064B_RFM69HCW=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--gc-sections,--report-mem 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/ONE_SmartPANEL_V4.4.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
