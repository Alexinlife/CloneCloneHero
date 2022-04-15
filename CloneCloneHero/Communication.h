#include <iostream>
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"

using json = nlohmann::json;
using namespace std;

#define BAUD 115200
#define MAX_MSG_SIZE 1024


#ifndef COMMUNICATION_H
#define COMMUNICATION_H

/**
* Author: Alex Lajeunesse
* Date: 03-03-2022
*
* Class: Communication
* Description: Links the controller powered by Arduino Mega with the game using Serial
*              Inspired by code available on Projet S2's website
**/
class Communication
{
public:
	/**
	* Default constructor for Communication
	*/
	Communication();

	/**
	* Destructor for Chart
	*/
	~Communication();

	bool sendTo(SerialPort* arduino, json j_msg);

	bool receiveFrom(SerialPort* arduino, string& msg);

	int* fetch(int sp);

private:
	SerialPort* arduino;
	json j_msg_send, j_msg_rcv;
	string raw_msg;
	string* input_names;

	// Structure de donnees JSON pour envoie et reception
	int led_state = 1;
	/*
	* 0: switch verte
	* 1: switch rouge
	* 2: switch jaune
	* 3: switch bleue
	* 4: switch orange
	* 5: joystick x
	* 6: joystick y
	* 7: accelerometre x
	* 8: accelerometre y
	* 9: accelerometre z
	*/
	int inputs[10];
	int ledState = 0;
	int ledModifier = 1;
};

#endif