//============================================================================
// Name        : DataSender.cpp
// Author      : KHARROUBI Majdi
// Version     :
// Copyright   : © 2017-2018 KHARROUBI Majdi ALL RIGHTS RESERVED
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include "Commands/Distance.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	FWK::Command::Distance d;

	const uint8_t* tab = d.serialise();

	cout << (int)tab<< endl;


	if(d.isSerialised())
		d.Unserialise();
	else
		cout << "obj not serialized" << endl;

	return 0;
}
