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
  - Fused
  - ESD protection

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

![is0Topre Proto Front](/Assets/images/PCB_proto_front.png)

![is0Topre Proto Back](/Assets/images/PCB_proto_back.png)

![is0Topre Plate Front](/Assets/images/plate_proto_front.png)

## WIP

Atmel MCU based firmware is validated, you can find the precompiled `.hex` (Vial compatible) and `.json` file for VIA in the firmware folder.

STM32 based MCU version is in development.

## Compatibility with is0 case

Given the difference in height and mounting system some modifications are needed.

At the time of ordering the PCBs be sure to use the following specs:

- 1.2mm thickness for the main PCB
- 0.6mm for the plates

In order to have the correct fit place in the marked spots adhesive tape, specifically:

- 2pcs, 0.4mm thick on the main PCB
- 4pcs, 0.1mm thick on the plates

These will ensure that all the tollerances are met and a secure fit is achieved.

## License

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
