

#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#include "SerialPort.h"

char output[MAX_DATA_LENGTH];
const char* port = "\\\\.\\COM3";
char incoming[MAX_DATA_LENGTH];

// Para cambiar los baudios esta en Serialport.cpp

int main() {


	SerialPort arduino(port);
	if (arduino.isConnected()) {cout << "Connection is established\n";}
	else {cout << "ERROR: Connection could not be established  \n";}

	
	// Esta sección de codigo envia
	while (arduino.isConnected()) {

		string command;
		cin >> command; //Aqui se introduce el dato por consola tambien se puede introducir mediante variable

		char* charArray = new char[command.size() + 1];
		copy(command.begin(), command.end(), charArray);
		charArray[command.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);

		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		cout << output;

		delete[] charArray;

	}	

	// Esta sección de codigo recibe 
	/*while (arduino.isConnected()) {

		string command;

		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		std::cout << output << "";

		Sleep(200);
		// En el caso de que los datos se reciban el realtime es importante poner el Sleep delay.... igual tanto en el codigo Arduino o donde se ejecute
	}*/		

	return 0;
}
