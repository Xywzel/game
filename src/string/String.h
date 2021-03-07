#pragma once

// Get rid of this in header at some point
#include <string>

namespace string
{
	class String
	{
		public:
			String();
			// From null termined string, mostly for literals
			String(const char* str);
			~String();

			// Access internal data
			//char* getData();
			const char* getData() const;
			// String length in characters
			size_t getLength() const;
			// Storage size of the string
			size_t getSize() const;

		private:
				std::string data;
	};

	// Uses printf syntax for formating a string
	String format(const String format...);
	String format(const char* format...);
}
