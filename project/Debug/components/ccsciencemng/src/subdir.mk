################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccsciencemng/src/CCScienceMngC.cpp \
../components/ccsciencemng/src/CCScienceMngE.cpp 

OBJS += \
./components/ccsciencemng/src/CCScienceMngC.o \
./components/ccsciencemng/src/CCScienceMngE.o 

CPP_DEPS += \
./components/ccsciencemng/src/CCScienceMngC.d \
./components/ccsciencemng/src/CCScienceMngE.d 


# Each subdirectory must supply rules for building sources it contributes
components/ccsciencemng/src/%.o: ../components/ccsciencemng/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/workspace/asw_rtems_project/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/atcsol/workspace/asw_rtems_project/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/atcsol/workspace/asw_rtems_project/swpackages/emu_sc_channel_drv_slib_head/include/emu_sc_channel_drv_slib" -I"/home/atcsol/workspace/asw_rtems_project/components/icuasw/include" -I"/home/atcsol/workspace/asw_rtems_project/dataclasses/CDEventList/include" -I"/home/atcsol/workspace/asw_rtems_project/dataclasses/CDRecovAction/include" -I"/home/atcsol/workspace/asw_rtems_project/dataclasses/CDTCDescriptor/include" -I"/home/atcsol/workspace/asw_rtems_project/dataclasses/CDTMList/include" -I"/home/atcsol/workspace/asw_rtems_project/dataclasses/CDTMMemory/include" -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/atcsol/workspace/asw_rtems_project/components/ccbgtcexec/include" -I"/home/atcsol/workspace/asw_rtems_project/components/ccepdmanager/include" -I"/home/atcsol/workspace/asw_rtems_project/components/ccsciencemng/include" -I"/home/atcsol/workspace/asw_rtems_project/config/include" -I"/home/atcsol/workspace/asw_rtems_project/edroom_glue/include" -I"/home/atcsol/workspace/asw_rtems_project/edroombp_swr/include" -I"/home/atcsol/workspace/asw_rtems_project/edroomsl_swr/include" -I"/home/atcsol/workspace/asw_rtems_project/edroomsl_types_swr/include" -I"/home/atcsol/workspace/asw_rtems_project/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


