################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modules/ismc/ismc_code.c \
../Core/Src/modules/ismc/ismc_code_data.c \
../Core/Src/modules/ismc/ismc_code_initialize.c \
../Core/Src/modules/ismc/ismc_code_terminate.c 

OBJS += \
./Core/Src/modules/ismc/ismc_code.o \
./Core/Src/modules/ismc/ismc_code_data.o \
./Core/Src/modules/ismc/ismc_code_initialize.o \
./Core/Src/modules/ismc/ismc_code_terminate.o 

C_DEPS += \
./Core/Src/modules/ismc/ismc_code.d \
./Core/Src/modules/ismc/ismc_code_data.d \
./Core/Src/modules/ismc/ismc_code_initialize.d \
./Core/Src/modules/ismc/ismc_code_terminate.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modules/ismc/%.o Core/Src/modules/ismc/%.su Core/Src/modules/ismc/%.cyclo: ../Core/Src/modules/ismc/%.c Core/Src/modules/ismc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/app" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/app" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modules-2f-ismc

clean-Core-2f-Src-2f-modules-2f-ismc:
	-$(RM) ./Core/Src/modules/ismc/ismc_code.cyclo ./Core/Src/modules/ismc/ismc_code.d ./Core/Src/modules/ismc/ismc_code.o ./Core/Src/modules/ismc/ismc_code.su ./Core/Src/modules/ismc/ismc_code_data.cyclo ./Core/Src/modules/ismc/ismc_code_data.d ./Core/Src/modules/ismc/ismc_code_data.o ./Core/Src/modules/ismc/ismc_code_data.su ./Core/Src/modules/ismc/ismc_code_initialize.cyclo ./Core/Src/modules/ismc/ismc_code_initialize.d ./Core/Src/modules/ismc/ismc_code_initialize.o ./Core/Src/modules/ismc/ismc_code_initialize.su ./Core/Src/modules/ismc/ismc_code_terminate.cyclo ./Core/Src/modules/ismc/ismc_code_terminate.d ./Core/Src/modules/ismc/ismc_code_terminate.o ./Core/Src/modules/ismc/ismc_code_terminate.su

.PHONY: clean-Core-2f-Src-2f-modules-2f-ismc

