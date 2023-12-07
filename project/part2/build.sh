#!/bin/bash
echo "Configuring pin P8.16 as an input with pull-up resistor enabled"
config-pin p8.16 gpio_pu
echo "Configuring pin P9.12 as an input"
config-pin p9.12 gpio
echo "Building the transmit/recieveTemperature applications"
g++ transmitTemperature.cpp -o transmitTemperature -lpaho-mqtt3c
g++ recieveTemperature.cpp AnalogIn.cpp -o recieveTemperature -lpaho-mqtt3c
echo "Building the transmit/recieveLED applications"
g++ transmitLED.cpp GPIO.cpp -o transmitLED -pthread -lpaho-mqtt3c
g++ recieveLED.cpp GPIO.cpp -o recieveLED -pthread -lpaho-mqtt3c
echo "Finished"