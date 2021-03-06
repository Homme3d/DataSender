/*
 * ICommand.hpp
 *
 *  Created on: 20 janv. 2018
 *      Author: Majdi
 */

#ifndef ICOMMAND_HPP_
#define ICOMMAND_HPP_

#include <cstdint>
#include <stddef.h>
#include <iostream>
#include <cassert>

#include "DTO/BasicDTO.hpp"

//this struct is creating some kind of limit I must create something to read from a file or something else
enum CommandType {
	kNavigate_2D,
	kNavigate_3D,
	//for get/set temp, light and other stuff I need an other type of struct
	kTemp,
	kDistence
};

class IBody {
public:
	virtual ~IBody() {}
	virtual uint8_t* Serialise()=0;
	virtual void Unserialise(uint8_t* CommandeBytes)=0;

};

template <typename T>//, typename = typename std::enable_if<std::is_base_of<IBody, T>::value>::type>
class ICommand {
	static_assert(std::is_base_of<IBody, T>::value, "IBody should be a base of T");
public:
	virtual ~ICommand() {
	}

	const uint8_t* Serialise(){
		std::cout << "obj serialized" << std::endl;
		CommandeBytes = _Body.Serialise();
		return CommandeBytes;
	}
	void Unserialise(){
		std::cout << "obj Unserialised" << std::endl;
		_Body.Unserialise(CommandeBytes);
	}

	size_t size() {
		return sizeof(_Header) + sizeof(_Body);
	}

	bool isSerialised() {
		std::cout<<"sizeof(CommandeBytes) "<<sizeof(CommandeBytes)<<std::endl;
		return sizeof(CommandeBytes);
	}

	const T& getBody() {
		return _Body;
	}

	T& accessBody(){
		return _Body;
	}

	void setBody(const T& body) {
		_Body = body;
	}

	const uint8_t* getCommandeBytes() {
		return CommandeBytes;
	}

	uint8_t* accessCommandeBytes() {
		return CommandeBytes;
	}

	void setCommandeBytes(uint8_t *commandeBytes) {
		CommandeBytes = commandeBytes;
	}

protected:
	const CommandType& getHeader() {
		return _Header;
	}

	CommandType accessHeader() {
		return _Header;
	}

	void setHeader(const CommandType& header) {
		_Header = header;
	}

	T _Body;

private:
	CommandType _Header;


	uint8_t* CommandeBytes;
};

#endif /* ICOMMAND_HPP_ */
