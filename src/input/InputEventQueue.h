#pragma once

#include "macros.h"

DECLARE(input, InputEvent)

namespace input
{
	class InputEventQueue
	{
		public:
			InputEventQueue();
			~InputEventQueue();
			InputEvent pop();
			InputEvent& peak();
			void push(InputEvent& event);
		private:
			InputEvent* events;
			size_t eventCount;
	};
}
