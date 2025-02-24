#pragma once

#include <iostream>
#include <Log/Errors/Errors.h>

namespace Log
{

	class Log
	{

	public:

		Log();
		virtual ~Log();

		void info(const char* message);

		void warn(const char* message);

		void error(const char* message);

	};

}