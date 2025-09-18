################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCALL/UART/subdir.mk
-include MCALL/I2C/subdir.mk
-include MCALL/DIO/subdir.mk
-include HAL/Ultrasonic/subdir.mk
-include HAL/Servo/subdir.mk
-include HAL/MOTOR/subdir.mk
-include HAL/LCD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
RC-CAR.lss \

FLASH_IMAGE += \
RC-CAR.hex \

EEPROM_IMAGE += \
RC-CAR.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: RC-CAR.elf secondary-outputs

# Tool invocations
RC-CAR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,RC-CAR.map -mmcu=atmega16 -o "RC-CAR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RC-CAR.lss: RC-CAR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S RC-CAR.elf  >"RC-CAR.lss"
	@echo 'Finished building: $@'
	@echo ' '

RC-CAR.hex: RC-CAR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex RC-CAR.elf  "RC-CAR.hex"
	@echo 'Finished building: $@'
	@echo ' '

RC-CAR.eep: RC-CAR.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex RC-CAR.elf  "RC-CAR.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RC-CAR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 RC-CAR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) RC-CAR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
