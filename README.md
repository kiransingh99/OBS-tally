# OBS Tally Light

## Description
This project facilitates a tally light/ on-air light when OBS is recording and/or
streaming. The idea came from the fact that it is becoming more and more popular
to stream programmes at Gurdwaras and it's very useful for the sangat to know
when it is being recorded, mainly so:
 * they can choose whether they want to be on camera, and
 * they know they don't need to record on their phones

## Usage
Outlined below is the required software and hardware setup for an OBS Tally
Light.

### Hardware

#### Requirements
* Arduino Uno
* Light @@@ TBC

#### Steps
1. Connect Arduino to PC via USB
2. Connect light @@@ expand on this when model is decided

### Software

#### Requirements
* Arduino IDE
* OBS installed - at least version 28.1.2

#### Steps
1. Install python 3.6 (https://www.python.org/downloads/release/python-360/)
   * Note if other versions of python are installed
2. Install the `pyserial` python package
   ```py
   pip install pyserial
   ```
   If multiple versions of python are installed, you will need to specify
   that you want to install `pyserial` to python 3.6
   ```py
   py -3.6 -m pip install pyserial
   ```
3. Load the python version into OBS
   Tools -> Scrips -> Python Settings
4. Download the Arduino script in this repository
   (src/controller/controller.ino) and upload it to the Arduino
5. Download the python script in this repository (src/tally.py)
6. Modify the tally.py script to set the COM port
   * This may need updating upon rebooting the computer. The COM port **should**
     stay the same if the same device is plugged into the same USB port, but
     the presence of another device may change this - bear this in mind if the
     tally light doesn't work upon reboot.
7. Load the tally.py script into OBS
   Tools -> Scripts -> Scripts -> +

Then you can use OBS as normal.

## Support
Get in contact if you have any problems with setting this up! I'm not actively
monitoring this for changes in dependencies, so if something stops working, I
probably won't notice.

## Contributing
If you have ideas for features you'd like to add to this, please get in touch,
or raise a PR

## Credits
This code was created by Gurkiran Singh.