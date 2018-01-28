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
	FWK::Command::Boby::DistanceBody& a1 = d.accessBody();
	a1.setDistance(10);

	FWK::Command::Boby::DistanceBody a2 = d.accessBody();
	cout << a2.getDistance().distance<< endl;

	const uint8_t* tab = d.Serialise();

	cout << (int)tab<< endl;

	FWK::Command::Boby::DistanceBody a = d.getBody();

	if(d.isSerialised()){
		d.Unserialise();
		cout << a.getDistance().distance<< endl;
	}
	else
		cout << "obj not serialized" << endl;

	return 0;
}
