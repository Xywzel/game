#include "Logger.h"

#include <iostream>
#include <string>

namespace logger
{
	class Logger {
		public:
			Logger()
			{
				minimumSeverity = LogLevel::All;
			}

			void queue(LogLevel severity, const string::String& message)
			{
				if (severity >= minimumSeverity)
					std::cout << message << std::endl;
			}
		private:
			LogLevel minimumSeverity;
	};

	Logger& getLogger()
	{
		static Logger logger;
		return logger;
	}

	void log(Level severity, const string::String& message)
	{
		Logger& logger = getLogger();
		logger.queue(severity, message);
	}

	void log(Level severity, const char* message)
	{
		log(severity, string::String(message));
	}
}
