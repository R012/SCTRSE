################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/cctmchannelctrl/src/CCTMChannelCtrlB.cpp \
../components/cctmchannelctrl/src/CCTMChannelCtrlS.cpp 

OBJS += \
./components/cctmchannelctrl/src/CCTMChannelCtrlB.o \
./components/cctmchannelctrl/src/CCTMChannelCtrlS.o 

CPP_DEPS += \
./components/cctmchannelctrl/src/CCTMChannelCtrlB.d \
./components/cctmchannelctrl/src/CCTMChannelCtrlS.d 


# Each subdirectory must supply rules for building sources it contributes
components/cctmchannelctrl/src/%.o: ../components/cctmchannelctrl/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"/home/user/workspace/asw_pus_rtems_project_students/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/user/workspace/asw_pus_rtems_project_students/swinterfaces/datapool_mng_iface_v1/include" -I"/home/user/workspace/asw_pus_rtems_project_students/swpackages/emu_sc_channel_drv_slib_head/include" -I"/home/user/workspace/asw_pus_rtems_project_students/dataclasses/CDSensorTMBufferStatus/include" -I"/home/user/workspace/asw_pus_rtems_project_students/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/user/workspace/asw_pus_rtems_project_students/swpackages/emu_sc_channel_drv_slib_head/include/emu_sc_channel_drv_slib" -I"/home/user/workspace/asw_pus_rtems_project_students/components/icuasw/include" -I"/home/user/workspace/asw_pus_rtems_project_students/dataclasses/CDEventList/include" -I"/home/user/workspace/asw_pus_rtems_project_students/dataclasses/CDRecovAction/include" -I"/home/user/workspace/asw_pus_rtems_project_students/dataclasses/CDTCDescriptor/include" -I"/home/user/workspace/asw_pus_rtems_project_students/dataclasses/CDTMList/include" -I"/home/user/workspace/asw_pus_rtems_project_students/dataclasses/CDTMMemory/include" -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/user/workspace/asw_pus_rtems_project_students/components/ccepdmanager/include" -I"/home/user/workspace/asw_pus_rtems_project_students/components/cctmchannelctrl/include" -I"/home/user/workspace/asw_pus_rtems_project_students/config/include" -I"/home/user/workspace/asw_pus_rtems_project_students/edroom_glue/include" -I"/home/user/workspace/asw_pus_rtems_project_students/edroombp_swr/include" -I"/home/user/workspace/asw_pus_rtems_project_students/edroomsl_swr/include" -I"/home/user/workspace/asw_pus_rtems_project_students/edroomsl_types_swr/include" -I"/home/user/workspace/asw_pus_rtems_project_students/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


