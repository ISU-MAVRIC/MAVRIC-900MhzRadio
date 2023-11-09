# MAVRIC-900MhzRadio
Code for ISU-MAVRIC's 900 MHz interface

## Table of Contents
- [Useful Documentation](#useful-documentation)
- [Environment Setup](#environment-setup)
- [Basic Project Structure](#basic-project-structure)
- [PlatformIO Folder Layout](#platformio-folder-layout)

## Useful Documentation
- [PlatformIO documentation](https://docs.platformio.org/en/latest/)
- [PlatformIO Install and Setup](https://platformio.org/install/ide?install=vscode)
- [PlatformIO Environment Tutorials and Examples](https://docs.platformio.org/en/stable/tutorials/index.html)
- [PySerialTransfer Library](https://github.com/PowerBroker2/pySerialTransfer)

## Environment Setup
A generic platformIO environment setup can be found here: [jetbrains.com](https://platformio.org/install/ide?install=vscode). This will help you install and open platformio.

This repository contains two PlatformIO folders: [Transmitter](https://github.com/ISU-MAVRIC/MAVRIC-900MhzRadio/tree/main/Transmitter) and [Reciever](https://github.com/ISU-MAVRIC/MAVRIC-900MhzRadio/tree/main/Reciever).
To open one of these directories, you need to first clone the repository with: 
```bash:
git clone https://github.com/ISU-MAVRIC/MAVRIC-900MhzRadio
```
In VSCode, open the file Explorer *(Ctrl+Shift+E)* and navigate to the repository. **Before opening a folder**, make sure to select the microcontroller you want to open. I.E. If you want the Reciever, select the Reciever folder.

You must now install the PlatformIO VSCode extension. Open the extensions menu *(Ctrl+Shift+X)* and search for "PlatformIO IDE". It looks like the icon below

<p align="center">
    <img src="https://platformio.gallerycdn.vsassets.io/extensions/platformio/platformio-ide/3.3.1/1690566415047/Microsoft.VisualStudio.Services.Icons.Default" width=100>
</p>

Once PlatformIO is installed, reload the VSCode window with *Ctrl+Shift+P* and type ```Reload Window``` until you see the option ```Developer: Reload Window```

Platform IO will now take over and automatically install dependencies and set up the build environment.

You can make changes to the firmware and check them by selecting the **Blue Check Box** on the VSCode status bar.
To upload firmware, select a port with the port button on the VSCode status bar, then select the upload firmware button, which looks like a right pointing arrow.

## Basic Project Structure
```.
├── Base Station
│   ├── pySerialTransfer
|   ├── baseStation.py
|   └── baseStationSimple.py
├── Reciever
├── Rover
|   ├── pySerialTransfer
|   └── 900Mhz.py
├── Transmitter
└── README.md
```
### Base Station
Contains older test code that can take an Xbox input from a pc and send it to the RF95 Transmitter. It also contains a copy of the [pySerialTransfer library](https://github.com/PowerBroker2/pySerialTransfer). There are two versions of the base station, a simple and full one. The simple one takes inputs from the command line for simple testing, and the full one integrates the pyGame library for xbox inputs.

### Reciever
This folder is a platformIO project that contains everything needed to compile and upload reciever firmware. This folder is opened in VSCode and automatically activates the PlatformIO IDE VSCode extension. Information about this folder's layout can be found [here](#platformio-folder-layout)

### Rover
This folder contains test code used during development that tested the rover's ability to pull data from the Reciever. It can be run on a PC by specifying the com port in the script.

### Transmitter
This folder is a platformIO project that contains everything needed to compile and upload transmitter firmware. This folder is opened in VSCode and automatically activates the PlatformIO IDE VSCode extension. Information about this folder's layout can be found [here](#platformio-folder-layout)

## PlatformIO folder layout
```.
├── PlatformIO Project Directory
|   ├── include [directory]
|   ├── lib [directory]
|   ├── src
|   |   ├── Defines.h
|   |   └── main.cpp
|   ├── test [directory]
|   └── platformio.ini

```
### include
This directory is currently unused by this project
### lib
This directory contains all libraries that aren't in a github repository. So far, the project does not require any of these.
### src
This directory contains all compiled code that gets put on the microprocessor. This code is compiled first.
#### Defines.h
This file sets up pin defines that are used by the code. To compile for a different board, change these defines
#### main.cpp
This is the main program for the board. It contains all the functions and code that the radios run on. This is the code that's compiled by the PlatformIO Compiler.
### test
This directory is unused but can be used to create test scripts to test functions in the firmware.
### platformio.ini
This is the configuration for the development environment. It contains the boards and dependencies needed to build the script in [main.cpp](#maincpp).
