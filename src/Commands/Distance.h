/*
 * Distance.h
 *
 *  Created on: 28 janv. 2018
 *      Author: Majdi
 */

#ifndef COMMANDS_DISTANCE_H_
#define COMMANDS_DISTANCE_H_
#include "../ICommand.hpp"

namespace FWK {
namespace Command {

//how to diff from get or set
// if distance = 0 it means get distance if no means set
namespace Boby {
class DistanceBody: public IBody {
public:
	const BasicDTO::Distance getDistance() {
		return _Distance;
	}

	void setDistance(const BasicDTO::Distance& distance) {
		_Distance = distance;
	}

	void setDistance(const float& distance) {
		_Distance.distance = distance;
	}

	uint8_t* Serialise(){
		return (uint8_t*) &_Distance.distance;
	}

	void Unserialise(uint8_t* CommandeBytes){
		_Distance = *(BasicDTO::pDistance) CommandeBytes;
	}

private:
	BasicDTO::Distance _Distance;
};
}/* namespace Boby */

class Distance: public ICommand<Boby::DistanceBody> {
public:
	Distance();
	virtual ~Distance(){};


};

} /* namespace Command */
} /* namespace FWK */

#endif /* COMMANDS_DISTANCE_H_ */
