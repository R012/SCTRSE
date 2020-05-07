################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include swpackages/icuasw_pus_services_slib_head/src/subdir.mk
-include swpackages/emu_tc_programming/src/subdir.mk
-include swpackages/emu_sc_channel_drv_slib_head/src/subdir.mk
-include swpackages/datapool_mng_slib_head/src/subdir.mk
-include edroomsl_types_swr/src/subdir.mk
-include edroomsl_swr/src/subdir.mk
-include edroombp_swr/src/rtemsapi_4_6/rtems_4_6/subdir.mk
-include edroom_glue/src/subdir.mk
-include dataclasses/CDSensorTMBufferStatus/src/subdir.mk
-include components/icuasw/src/subdir.mk
-include components/cctm_channelctrl/src/subdir.mk
-include components/cchk_fdirmng/src/subdir.mk
-include components/ccepdmanager/src/subdir.mk
-include components/ccbkgtcexec/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: asw_pus_12_x_5_x_rtems_project_students

# Tool invocations
asw_pus_12_x_5_x_rtems_project_students: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: SPARC RTEMS C++ Linker'
	sparc-rtems-g++ -msoft-float -o "asw_pus_12_x_5_x_rtems_project_students" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(S_DEPS)$(S_UPPER_DEPS)$(CPP_DEPS)$(C_DEPS) asw_pus_12_x_5_x_rtems_project_students
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
