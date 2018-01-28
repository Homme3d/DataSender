/*
 * Distance.cpp
 *
 *  Created on: 28 janv. 2018
 *      Author: Majdi
 */

#include "Distance.h"

namespace FWK {
namespace Command {

Distance::Distance() {
	setHeader(kDistence);
	accessBody().setDistance(50);
}



const uint8_t* Distance::serialise() {
	std::cout << "obj serialized" << std::endl;

	setCommandeBytes((uint8_t*) &accessBody().getDistance());

	return (uint8_t*) &accessBody().getDistance();

}

void Distance::Unserialise() {
	std::cout << "obj unserialized" << std::endl;
	BasicDTO::pDistance a = (BasicDTO::pDistance) accessCommandeBytes();
	//assert(a != NULL);
	std::cout << "a->distance :" << a->distance << std::endl;

	accessBody().setDistance(*(BasicDTO::pDistance) getCommandeBytes());
}

} /* namespace Command */
} /* namespace FWK */
