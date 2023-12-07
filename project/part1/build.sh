#!/bin/bash
echo "Configuring pin P8.16 as an input with pull-up resistor enabled"
config-pin p8.16 gpio_pu
echo "Configuring pin P9.12 as an input"
config-pin p9.12 gpio
echo "Building the publishTemperature application"
g++ publishTemperature.cpp  AnalogIn.cpp -o publishTemperature -lpaho-mqtt3c
echo "Building the subscribeTemperature application"
g++ subscribeTemperature.cpp derek_LED.cpp -o subscribeTemperature -lpaho-mqtt3c
echo "Building the subscribeBlinks application"
g++ subscribeBlinks.cpp derek_LED.cpp -o subscribeBlinks -lpaho-mqtt3c
echo "Building the publishButton application"
g++ publishButton.cpp GPIO.cpp -o publishButton -pthread -lpaho-mqtt3c
echo "Building the subscribeAC application"
g++ subscribeAC.cpp GPIO.cpp -o subscribeAC -pthread -lpaho-mqtt3c
echo "Finished"