#!/bin/bash
echo "Building the publishTemperature application"
g++ publishTemperature.cpp  analogin.cpp -o publishTemperature -lpaho-mqtt3c
echo "Building the subscribeTemperature application"
g++ subscribeTemperature.cpp derek_LED.cpp -o subscribeTemperature -lpaho-mqtt3c
echo "Finished"