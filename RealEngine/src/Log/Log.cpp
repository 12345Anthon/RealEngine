#include "Log.h"

namespace Log
{

	Log::Log()
	{
		Log::info("Log Constructed");
	}

	Log::~Log()
	{
		Log::info("Log Destroid");
	}

	void Log::info(const char* message)
	{
		std::cout << "[INFO]: " << message << std::endl;
	}

	void Log::warn(const char* message)
	{
		std::cout << "[WARN]: " << message << std::endl;
		std::wcerr << "[WARN]: " << message << std::endl;
	}

	void Log::error(const char* message)
	{
		std::cerr << "[ERROR]: " << message << std::endl;
	}

}