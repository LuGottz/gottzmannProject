#!/bin/bash
echo "Building the subscribeAC application"
g++ subscribeAC.cpp GPIO.cpp -o subscribeAC -lpaho-mqtt3c -pthread
echo "Finished"