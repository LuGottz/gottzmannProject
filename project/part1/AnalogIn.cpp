/** File name: AnalogIn.cpp
*   Class for Analog to Digital Converter on the BB
*   Written by Luke Gottzmann for CPE 422
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include "AnalogIn.h"
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

AnalogIn::AnalogIn() {
}

AnalogIn::AnalogIn(unsigned int n) {
        number = n;
}

void AnalogIn::setNumber(unsigned int n) {
        number = n;
}

int AnalogIn::readADC() {
        stringstream ss;
        ss << ADC_PATH << number << "_raw";
        fstream fs;
        fs.open(ss.str().c_str(), fstream::in);
        fs >> number;
        fs.close();
        return number;
}

AnalogIn::~AnalogIn() {
}