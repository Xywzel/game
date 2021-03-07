#pragma once

namespace input
{
	enum Key
	{
		KeyStart,
		KeyCount,
	};

	struct KeyState
	{
		bool pressed;
		uint64_t changed;
	};

	struct InputState
	{
		KeyState keys[KeyCount];
	};
}
