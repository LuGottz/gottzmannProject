/** File name: derek_LED.cpp
*   Class for controlling LEDs on the BB
*   Original code by Derek Molloy
*   Modified by Luke Gottzmann for CPE 422
*/

#include "derek_LED.h"
#include<unistd.h>

LED::LED(int number){
   this->number = number;
   // much easier with C++11 using to_string(number)
   ostringstream s;    // using a stream to contruct the path
   s << LED_PATH << number;   //append LED number to LED_PATH
   path = string(s.str());    //convert back from stream to string
}

void LED::writeLED(string filename, string value){
   ofstream fs;
   fs.open((path + filename).c_str());
   fs << value;
   fs.close();
}

void LED::removeTrigger(){
   writeLED("/trigger", "none");
}

void LED::turnOn(){
   cout << "Turning LED" << number << " on." << endl;
   removeTrigger();
   writeLED("/brightness", "1");
}

void LED::turnOff(){
   cout << "Turning LED" << number << " off." << endl;
   removeTrigger();
   writeLED("/brightness", "0");
}

void LED::flash(string delayms = "50"){
   cout << "Making LED" << number << " flash." << endl;
   writeLED("/trigger", "timer");
   writeLED("/delay_on", delayms);
   writeLED("/delay_off", delayms);
}

void LED::blink(int num) {
   cout << "Making USR3 LED blink " << num << " times for 1 second each." << endl;
   string delayms = "1000";
   removeTrigger();
   for (int i = 0; i < num; i++) {
      // turn on LED
      writeLED("/brightness", "1");
      //writeLED("/delay_on", delayms);
      sleep(1);
      // turn off LED
      writeLED("/brightness", "0");
      //writeLED("/delay_off", delayms);
      sleep(1);
   }
}

void LED::outputState(){
   ifstream fs;
   fs.open( (path + "/trigger").c_str());
   string line;
   while(getline(fs,line)) cout << line << endl;
      fs.close();
}

LED::~LED(){
   cout << "destroying the LED with path: " << path << endl;
}