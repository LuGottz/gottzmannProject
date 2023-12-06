#!/bin/bash
echo "Building the subscribeAC application"
g++ subscribeAC.cpp gpio.cpp -o subscribeAC -lpaho-mqtt3c
echo "Finished"