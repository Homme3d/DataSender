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
	accessBody().setDistance(0);
}

} /* namespace Command */
} /* namespace FWK */
