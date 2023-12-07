#!/bin/bash
echo "Configuring pin P8.16 as an input with pull-up resistor enabled"
config-pin p8.16 gpio_pu
echo "Configuring pin P9.12 as an input"
config-pin p9.12 gpio
echo "Finished"