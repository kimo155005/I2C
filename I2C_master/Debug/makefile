################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/USART/subdir.mk
-include MCAL/TIMERS/TIMER1/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Stepper_Motor/subdir.mk
-include HAL/SERVO_MOTOR/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPAD/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/Button/subdir.mk
-include HAL/7-Segment/subdir.mk
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
I2C_master.lss \

FLASH_IMAGE += \
I2C_master.hex \

EEPROM_IMAGE += \
I2C_master.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: I2C_master.elf secondary-outputs

# Tool invocations
I2C_master.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,I2C_master.map -mmcu=atmega32 -o "I2C_master.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

I2C_master.lss: I2C_master.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S I2C_master.elf  >"I2C_master.lss"
	@echo 'Finished building: $@'
	@echo ' '

I2C_master.hex: I2C_master.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex I2C_master.elf  "I2C_master.hex"
	@echo 'Finished building: $@'
	@echo ' '

I2C_master.eep: I2C_master.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex I2C_master.elf  "I2C_master.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: I2C_master.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 I2C_master.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) I2C_master.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
