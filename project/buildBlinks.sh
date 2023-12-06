#!/bin/bash
echo "Building the subscribeBlinks application"
g++ subscribeBlinks.cpp derek_LED.cpp -o subscribeBlinks -lpaho-mqtt3c
echo "Finished"