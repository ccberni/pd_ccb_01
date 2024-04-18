################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modules/types/rtGetInf.c \
../Core/Src/modules/types/rtGetNaN.c \
../Core/Src/modules/types/rt_nonfinite.c 

OBJS += \
./Core/Src/modules/types/rtGetInf.o \
./Core/Src/modules/types/rtGetNaN.o \
./Core/Src/modules/types/rt_nonfinite.o 

C_DEPS += \
./Core/Src/modules/types/rtGetInf.d \
./Core/Src/modules/types/rtGetNaN.d \
./Core/Src/modules/types/rt_nonfinite.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modules/types/%.o Core/Src/modules/types/%.su Core/Src/modules/types/%.cyclo: ../Core/Src/modules/types/%.c Core/Src/modules/types/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/lpf" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/types" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/pid" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/ismc" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules/cr2" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Src/app" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/modules" -I"C:/Users/Cassio.PC64_CASSIO/Documents/doutorado/posicionador_digital/sw/uc/pd_ccb_01/Core/Inc/app" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modules-2f-types

clean-Core-2f-Src-2f-modules-2f-types:
	-$(RM) ./Core/Src/modules/types/rtGetInf.cyclo ./Core/Src/modules/types/rtGetInf.d ./Core/Src/modules/types/rtGetInf.o ./Core/Src/modules/types/rtGetInf.su ./Core/Src/modules/types/rtGetNaN.cyclo ./Core/Src/modules/types/rtGetNaN.d ./Core/Src/modules/types/rtGetNaN.o ./Core/Src/modules/types/rtGetNaN.su ./Core/Src/modules/types/rt_nonfinite.cyclo ./Core/Src/modules/types/rt_nonfinite.d ./Core/Src/modules/types/rt_nonfinite.o ./Core/Src/modules/types/rt_nonfinite.su

.PHONY: clean-Core-2f-Src-2f-modules-2f-types

