#pragma once

// Input handless input from devices, these should be translated to
#include "macros.h"

// controls, based on keybindings.
DECLARE(window, Window)

namespace input
{
	class InputState;
	class InputEventQueue;
	// Primary method for initialisation for input, sets callback functions 
	void registerCallbacks(window::Window& window);
	// Called once a frame to gather events since last call
	void pollEvents();
	// Returns the state of the input devices at the time poll was called
	const InputState& getInputState();
	// Return input events between two privious calls to pollEvents
	InputEventQueue getInputEvents();

}
