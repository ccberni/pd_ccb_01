################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modules/cr2/cr2_code.c \
../Core/Src/modules/cr2/cr2_code_data.c \
../Core/Src/modules/cr2/cr2_code_initialize.c \
../Core/Src/modules/cr2/cr2_code_terminate.c 

OBJS += \
./Core/Src/modules/cr2/cr2_code.o \
./Core/Src/modules/cr2/cr2_code_data.o \
./Core/Src/modules/cr2/cr2_code_initialize.o \
./Core/Src/modules/cr2/cr2_code_terminate.o 

C_DEPS += \
./Core/Src/modules/cr2/cr2_code.d \
./Core/Src/modules/cr2/cr2_code_data.d \
./Core/Src/modules/cr2/cr2_code_initialize.d \
./Core/Src/modules/cr2/cr2_code_terminate.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modules/cr2/%.o Core/Src/modules/cr2/%.su Core/Src/modules/cr2/%.cyclo: ../Core/Src/modules/cr2/%.c Core/Src/modules/cr2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/app" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/app" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modules-2f-cr2

clean-Core-2f-Src-2f-modules-2f-cr2:
	-$(RM) ./Core/Src/modules/cr2/cr2_code.cyclo ./Core/Src/modules/cr2/cr2_code.d ./Core/Src/modules/cr2/cr2_code.o ./Core/Src/modules/cr2/cr2_code.su ./Core/Src/modules/cr2/cr2_code_data.cyclo ./Core/Src/modules/cr2/cr2_code_data.d ./Core/Src/modules/cr2/cr2_code_data.o ./Core/Src/modules/cr2/cr2_code_data.su ./Core/Src/modules/cr2/cr2_code_initialize.cyclo ./Core/Src/modules/cr2/cr2_code_initialize.d ./Core/Src/modules/cr2/cr2_code_initialize.o ./Core/Src/modules/cr2/cr2_code_initialize.su ./Core/Src/modules/cr2/cr2_code_terminate.cyclo ./Core/Src/modules/cr2/cr2_code_terminate.d ./Core/Src/modules/cr2/cr2_code_terminate.o ./Core/Src/modules/cr2/cr2_code_terminate.su

.PHONY: clean-Core-2f-Src-2f-modules-2f-cr2

