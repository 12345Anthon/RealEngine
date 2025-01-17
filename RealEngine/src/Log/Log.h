#pragma once

#include <iostream>
#include <Log/Errors/Errors.h>

class Log
{

public:
		
	void info(const char* message) {

		std::cout << "[INFO] " << message << std::endl;

	}

	void warn(const char* message) {

		std::cout << "[WARN] " << message << std::endl;

	}

	void error(const char* message) {

		std::cout << "[ERROR] " << message << std::endl;

	}

};