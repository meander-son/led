################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/hello_world.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/hello_world.d \
./source/semihost_hardfault.d 

OBJS += \
./source/hello_world.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DMCXN947_cm33_core0_SERIES -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\drivers" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\CMSIS" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\CMSIS\m-profile" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\device" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\device\periph" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\utilities" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\utilities\str" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\utilities\debug_console_lite" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\component\uart" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\source" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\board" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -imacros "C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/hello_world.d ./source/hello_world.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

