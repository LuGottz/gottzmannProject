#!/bin/bash
echo "Building the publishButton application"
g++ publishButton.cpp GPIO.cpp -o publishButton -lpaho-mqtt3c
echo "Finished"