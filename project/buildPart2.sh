#!/bin/bash
echo "Building the transmit/recieveTemperature applications"
g++ transmitTemperature.cpp GPIO.h -o transmitTemperature -pthread -lpaho-mqtt3c
g++ recieveTemperature.cpp GPIO.h -o recieveTemperature -pthread -lpaho-mqtt3c
echo "Building the transmit/recieveLED applications"
g++ transmitLED.cpp AnalogIn.h -o transmitLED -pthread -lpaho-mqtt3c
g++ recieveLED.cpp AnalogIn.h -o recieveLED -pthread -lpaho-mqtt3c
echo "Finished"