/** File name: subscribe.cpp
*   Class for Adafruit IO usage on BB
*   Original code by Derek Molloy
*   Modified by Luke Gottzmann for CPE 422
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"
#include "derek_LED.h"
using namespace std;

#define ADDRESS "tcp://io.adafruit.com:1883"
#define CLIENTID "Beagle2"
#define TOPIC "Lugottz/feeds/project.temperature"
#define AUTHMETHOD "Lugottz"
#define AUTHTOKEN ""
#define QOS 1
#define TIMEOUT 10000L
#define THRESHOLD 30

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt) {
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    LED USR0(0);
    int i;
    char* payloadptr;
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");
    payloadptr = (char*) message->payload;
    float temperature = atof(payloadptr);
    printf("The temperature is %f\n", temperature);
    if (temperature < THRESHOLD) {
        USR0.turnOn();
    }
    else {
        USR0.turnOff();
    }
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause) {
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int main(int argc, char* argv[]) {
    MQTTClient readTemp;
    MQTTClient_connectOptions opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    MQTTClient_create(&readTemp, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    opts.keepAliveInterval = 20;
    opts.cleansession = 1;
    opts.username = AUTHMETHOD;
    opts.password = AUTHTOKEN;
    MQTTClient_setCallbacks(readTemp, NULL, connlost, msgarrvd, delivered);
    if ((rc = MQTTClient_connect(readTemp, &opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
    MQTTClient_subscribe(readTemp, TOPIC, QOS);

    do {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');
    MQTTClient_disconnect(readTemp, 10000);
    MQTTClient_destroy(&readTemp);
    return rc;
}