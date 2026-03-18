################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/animations.c \
../board/board.c \
../board/clock_config.c \
../board/emotions.c \
../board/hardware_init.c \
../board/oled_shapes.c \
../board/peripherals.c \
../board/pin_mux.c \
../board/shield_oled.c 

C_DEPS += \
./board/animations.d \
./board/board.d \
./board/clock_config.d \
./board/emotions.d \
./board/hardware_init.d \
./board/oled_shapes.d \
./board/peripherals.d \
./board/pin_mux.d \
./board/shield_oled.d 

OBJS += \
./board/animations.o \
./board/board.o \
./board/clock_config.o \
./board/emotions.o \
./board/hardware_init.o \
./board/oled_shapes.o \
./board/peripherals.o \
./board/pin_mux.o \
./board/shield_oled.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DMCXN947_cm33_core0_SERIES -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\drivers" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\CMSIS" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\CMSIS\m-profile" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\device" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\device\periph" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\utilities" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\utilities\str" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\utilities\debug_console_lite" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\component\uart" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\source" -I"C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\board" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -imacros "C:\Users\Mark0\Documents\MCUXpressoIDE_25.6.136\workspace\frdmmcxn947_hello_world_cm33_core0_-demo\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/animations.d ./board/animations.o ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/emotions.d ./board/emotions.o ./board/hardware_init.d ./board/hardware_init.o ./board/oled_shapes.d ./board/oled_shapes.o ./board/peripherals.d ./board/peripherals.o ./board/pin_mux.d ./board/pin_mux.o ./board/shield_oled.d ./board/shield_oled.o

.PHONY: clean-board

