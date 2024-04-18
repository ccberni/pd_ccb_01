################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modules/lpf/lpf_i1.c \
../Core/Src/modules/lpf/lpf_i1_initialize.c \
../Core/Src/modules/lpf/lpf_i1_terminate.c \
../Core/Src/modules/lpf/lpf_i2.c \
../Core/Src/modules/lpf/lpf_i2_initialize.c \
../Core/Src/modules/lpf/lpf_i2_terminate.c \
../Core/Src/modules/lpf/lpf_i3.c \
../Core/Src/modules/lpf/lpf_i3_initialize.c \
../Core/Src/modules/lpf/lpf_i3_terminate.c \
../Core/Src/modules/lpf/lpf_o1.c \
../Core/Src/modules/lpf/lpf_o1_initialize.c \
../Core/Src/modules/lpf/lpf_o1_terminate.c 

OBJS += \
./Core/Src/modules/lpf/lpf_i1.o \
./Core/Src/modules/lpf/lpf_i1_initialize.o \
./Core/Src/modules/lpf/lpf_i1_terminate.o \
./Core/Src/modules/lpf/lpf_i2.o \
./Core/Src/modules/lpf/lpf_i2_initialize.o \
./Core/Src/modules/lpf/lpf_i2_terminate.o \
./Core/Src/modules/lpf/lpf_i3.o \
./Core/Src/modules/lpf/lpf_i3_initialize.o \
./Core/Src/modules/lpf/lpf_i3_terminate.o \
./Core/Src/modules/lpf/lpf_o1.o \
./Core/Src/modules/lpf/lpf_o1_initialize.o \
./Core/Src/modules/lpf/lpf_o1_terminate.o 

C_DEPS += \
./Core/Src/modules/lpf/lpf_i1.d \
./Core/Src/modules/lpf/lpf_i1_initialize.d \
./Core/Src/modules/lpf/lpf_i1_terminate.d \
./Core/Src/modules/lpf/lpf_i2.d \
./Core/Src/modules/lpf/lpf_i2_initialize.d \
./Core/Src/modules/lpf/lpf_i2_terminate.d \
./Core/Src/modules/lpf/lpf_i3.d \
./Core/Src/modules/lpf/lpf_i3_initialize.d \
./Core/Src/modules/lpf/lpf_i3_terminate.d \
./Core/Src/modules/lpf/lpf_o1.d \
./Core/Src/modules/lpf/lpf_o1_initialize.d \
./Core/Src/modules/lpf/lpf_o1_terminate.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modules/lpf/%.o Core/Src/modules/lpf/%.su Core/Src/modules/lpf/%.cyclo: ../Core/Src/modules/lpf/%.c Core/Src/modules/lpf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/app" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/app" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modules-2f-lpf

clean-Core-2f-Src-2f-modules-2f-lpf:
	-$(RM) ./Core/Src/modules/lpf/lpf_i1.cyclo ./Core/Src/modules/lpf/lpf_i1.d ./Core/Src/modules/lpf/lpf_i1.o ./Core/Src/modules/lpf/lpf_i1.su ./Core/Src/modules/lpf/lpf_i1_initialize.cyclo ./Core/Src/modules/lpf/lpf_i1_initialize.d ./Core/Src/modules/lpf/lpf_i1_initialize.o ./Core/Src/modules/lpf/lpf_i1_initialize.su ./Core/Src/modules/lpf/lpf_i1_terminate.cyclo ./Core/Src/modules/lpf/lpf_i1_terminate.d ./Core/Src/modules/lpf/lpf_i1_terminate.o ./Core/Src/modules/lpf/lpf_i1_terminate.su ./Core/Src/modules/lpf/lpf_i2.cyclo ./Core/Src/modules/lpf/lpf_i2.d ./Core/Src/modules/lpf/lpf_i2.o ./Core/Src/modules/lpf/lpf_i2.su ./Core/Src/modules/lpf/lpf_i2_initialize.cyclo ./Core/Src/modules/lpf/lpf_i2_initialize.d ./Core/Src/modules/lpf/lpf_i2_initialize.o ./Core/Src/modules/lpf/lpf_i2_initialize.su ./Core/Src/modules/lpf/lpf_i2_terminate.cyclo ./Core/Src/modules/lpf/lpf_i2_terminate.d ./Core/Src/modules/lpf/lpf_i2_terminate.o ./Core/Src/modules/lpf/lpf_i2_terminate.su ./Core/Src/modules/lpf/lpf_i3.cyclo ./Core/Src/modules/lpf/lpf_i3.d ./Core/Src/modules/lpf/lpf_i3.o ./Core/Src/modules/lpf/lpf_i3.su ./Core/Src/modules/lpf/lpf_i3_initialize.cyclo ./Core/Src/modules/lpf/lpf_i3_initialize.d ./Core/Src/modules/lpf/lpf_i3_initialize.o ./Core/Src/modules/lpf/lpf_i3_initialize.su ./Core/Src/modules/lpf/lpf_i3_terminate.cyclo ./Core/Src/modules/lpf/lpf_i3_terminate.d ./Core/Src/modules/lpf/lpf_i3_terminate.o ./Core/Src/modules/lpf/lpf_i3_terminate.su ./Core/Src/modules/lpf/lpf_o1.cyclo ./Core/Src/modules/lpf/lpf_o1.d ./Core/Src/modules/lpf/lpf_o1.o ./Core/Src/modules/lpf/lpf_o1.su ./Core/Src/modules/lpf/lpf_o1_initialize.cyclo ./Core/Src/modules/lpf/lpf_o1_initialize.d ./Core/Src/modules/lpf/lpf_o1_initialize.o ./Core/Src/modules/lpf/lpf_o1_initialize.su ./Core/Src/modules/lpf/lpf_o1_terminate.cyclo ./Core/Src/modules/lpf/lpf_o1_terminate.d ./Core/Src/modules/lpf/lpf_o1_terminate.o ./Core/Src/modules/lpf/lpf_o1_terminate.su

.PHONY: clean-Core-2f-Src-2f-modules-2f-lpf

