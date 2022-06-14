# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

CUSTOM_MATRIX = lite
SRC += analog.c atmel/matrix.c atmel/ec_switch_matrix.c
