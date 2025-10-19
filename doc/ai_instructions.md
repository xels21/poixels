# Poixels

## project name
mixture of poi + pixel + author (xels)

## hardware
- ESP32 c3 super mini
- 18650 mah battery
- usb-c charger
- on/off switch
- step up converter
- ws2812b
- SD-card reader (future)
- gyro sensor (future)

## dev HW
adjusted stubs for running on windows

## general
This SW will be flashed on an microcontroller which will be installed in a 3d printed case for controlling ws2812b led stipes
The led stipe will be rotated and within this rotation the pixel stipe should be working as a display.
Lets assume the pois will spinn with 800ms per turn.
The led should be controlled based on multiple pictures as an input.
If the led stripe has e.g. 50 pixel, the pixture should be shrinked to a width of 50. the height of the pixel should be shrinked accordingly without changing the screen aspect ratios.
one picture row should be displayed for a specific time (e.g. 5 mili seconds) and then the next pixel row should be displayd.
at the end of the picture it should start from row 0.
After a specific time (e.g. 5s) the next picture should be displayed

## tools
- Platformio
- libs for all hw used (should be stubbed for windows execution)

## features
### webinterface
a webinterface with the current display output should be visible.
some static files should be provided and the display output should be fast and lightweight synchronized (maybe with websockets).
Also some parameters should be adjusted via web (e.g. seconds per row (1ms..100ms) and picture interval (1s - 20s))
It should be possible to uplaod pictures via webinterface and they should be synchronized to the 2nd poi

### bluetooth
the software hsould be flashed on 2 microcontroller.
They should be linked to each other and one is working as the master and the other as slave.
When one poi is changing its picture, the other should follow

### sd card reader
tbd
### gyro sensor
tbd


## 1st step:
please implement firstly a windows version where the display is realized with a webinterface.
The pixel should just show the color red