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
	const BasicDTO::Distance& getDistance() {
		return _Distance;
	}

	void setDistance(const BasicDTO::Distance& distance) {
		_Distance = distance;
	}

	void setDistance(const float& distance) {
		_Distance.distance = distance;
	}

private:
	BasicDTO::Distance _Distance;
};
}/* namespace Boby */

class Distance: public ICommand<Boby::DistanceBody> {
public:
	Distance();
	virtual ~Distance(){};

	const uint8_t* serialise();
	void Unserialise();

};

} /* namespace Command */
} /* namespace FWK */

#endif /* COMMANDS_DISTANCE_H_ */
