#pragma once

#include <macros.h>

DECLARE(string, String)

namespace logger
{
	enum class Level
	{
		All,
		Info,
		Debug,
		Warning,
		Error,
		Nothing
	};

	void log(Level severity, const string::String& message);
	void log(Level severity, const char* message);
}

