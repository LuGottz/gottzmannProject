#!/bin/bash
echo "Configuring pin P8.16 as an input with pull-up resistor enabled"
config-pin -q p8.16
config-pin p8.16 gpio_pu
config-pin -q p8.16
echo "Configuring pin P9.12 as an input"
config-pin -q p9.12
config-pin -l p9.12
config-pin p9.12 gpio
config-pin -q p9.12
echo "Finished"