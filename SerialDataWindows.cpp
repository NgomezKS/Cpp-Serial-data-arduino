

#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#include "SerialPort.h"

char output[MAX_DATA_LENGTH];
const char* port = "\\\\.\\COM3";
char incoming[MAX_DATA_LENGTH];

int main() {


	SerialPort arduino(port);
	if (arduino.isConnected()) {cout << "Connection is established\n";}
	else {cout << "ERROR: Connection could not be established  \n";}

	while (arduino.isConnected()) {

		string command;
		cin >> command; 
		
		char* charArray = new char[command.size() + 1];
		copy(command.begin(), command.end(), charArray);
		charArray[command.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);

		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		cout << output;

		delete[] charArray;

	}	

	/*while (arduino.isConnected()) {

		string command;

		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		std::cout << output << "";

		Sleep(200);

	}*/		

	return 0;
}
