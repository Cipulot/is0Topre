# is0Topre

## Introduction

Topre version of the iconic is0 board.

This project is a continuation of my development of open source EC boards.

Below is the KLE of the supported layout:

![is0Topre KLE](/Assets/images/is0Topre_KLE.jpg)

## Technical information

- Layout size: ISO enter
- Compatible switches: EC switches (Topre and NIZ)
- Microcontroller: Atmega32u4
- Connector: USB Type C
- Firmware compatibility: QMK (with VIA/VIAL support)
- Protection hardware:
  * Fused
  * ESD protection

**Addition: an empty spot for a 3.5x3.5mm SK series LED has been added to the back of the PCB, in case you want to manually add a bit of lighting.

## Renders and Prototypes

### is0Topre PCB

#### Render

![is0Topre PCB Top Render](/Assets/images/PCB_top.png)

![is0Topre PCB Bottom Render](/Assets/images/PCB_bottom.png)

### Plate

#### Render

Topre housing compatible plate:

![is0Topre Plate Render](/Assets/images/is0Topre_Plate.png)

MX plate mounted stabilizer compatible plate:

![is0Topre Plate MX Render](/Assets/images/is0Topre_Plate_MX_PM.png)

#### Prototype

![is0Topre Proto](/Assets/images/is0Topre_PCB_Proto.png)

## WIP

Atmel MCU based firmware is validated, you can find the precompiled `.hex` (Vial compatible) and `.json` file for VIA in the firmware folder.

STM32 based MCU version is in development.

## Copyright notice

This project is released under the MIT License. For the license, please refer to the LICENCE.md file.
