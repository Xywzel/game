#include "String.h"

#include <cstdarg>
#include <cstring>
#include <cassert>

#include <string>
#include <memory>

namespace string
{
	String::String()
	{
	}

	String::String(const char* str)
		: data(str)
	{
	}

	String::~String()
	{
	}

	/*
	char* String::getData()
	{
		return data.c_str();
	}
	*/

	const char* String::getData() const
	{
		return data.c_str();
	}

	size_t String::getLength() const
	{
		return data.size();
	}

	size_t String::getSize() const
	{
		return data.size();
	}

	String fromFormatString(const String format, va_list args)
	{
		// Calculate the length of the buffer needed
		int length = std::vsnprintf(nullptr, 0, format.getData(), args);

		// Array in unique pointer, should auto clean up on exiting scope
		std::unique_ptr<char[]> formatted;
		// Reserve space, include null terminator
		formatted.reset(new char[length + 1]);
		// Print out the text to the buffer
		int fullLength = std::vsnprintf(&formatted[0], length+1, format.getData(), args);
		// Check that the length matches
		assert(fullLength == length && "Print string length doesnt match expected length");
    return String(formatted.get());
	}


	String fromFormatString(const String format...)
	{
		std::va_list args;
		va_start(args, format);
		String result = fromFormatString(format, args);
		va_end(args);
		return result;
	}

	String fromFormatString(const char* format...)
	{
		std::va_list args;
		va_start(args, format);
		String formatString(format);
		String result = fromFormatString(formatString, args);
		va_end(args);
		return result;
	}
}
