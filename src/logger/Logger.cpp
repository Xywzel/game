#include "Logger.h"

#include <iostream>
#include "string/String.h"

namespace logger
{
	class Logger {
		public:
			Logger()
			{
				minimumSeverity = Level::All;
			}

			void queue(Level severity, const string::String& message)
			{
				if (severity >= minimumSeverity)
					std::cout << message.getData() << std::endl;
			}
		private:
			Level minimumSeverity;
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
