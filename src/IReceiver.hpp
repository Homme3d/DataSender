/*
 * IReciver.hpp
 *
 *  Created on: 20 janv. 2018
 *      Author: Majdi
 */

#ifndef IRECEIVER_HPP_
#define IRECEIVER_HPP_

//TODO define the object channel that will include the address of the object and the type of the channel (WIFI, BT, IR ...)
//To remember a IComande is an object composed of tow part 1- data 2- CommandType

#include <vector>

#include "ICommand.hpp"
#include "IResult.hpp"



/* a Receiver must be able to:
 *		- Set an object of type Icommand (or a vector of Icommand),
 * 		- Provide a list of supported commands,
 * 		- Set the channel of communication,
 * 		- Invoke the send method (maybe by inheritance from the class sender)
 *
 *
 */
class IReceiver
{
public:
	// I'm using a pointer bcz I fell so
	virtual void setCommandToSend(const ICommand *command) = 0;

	// IResult is an object as same as ICommand but without header
	virtual IResult GetResult() = 0;

	// get the list of supported command by sending a command type (to define) with empty data so no need to make it virtual
	const std::vector<const CommandType> SupportedCommad();
};


#endif /* IRECEIVER_HPP_ */
