#include "Errors.h"
#include <Log/Log.h>

namespace Errors
{
	Log::Log log;

	Errors::Errors()
	{
		log.info("Error detector constructed");
	}

	Errors::~Errors()
	{
		log.info("Error detector destroied");
	}

}