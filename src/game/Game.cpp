#include "Game.h"

#include "window/Window.h"
#include "string/String.h"

namespace game
{
	void parseArgs(std::vector<string::String> args)
	{
		// Parse args
		for(size_t i = 0; i < args.size(); ++i)
		{
			// All proper flags start with char '-' and be two characters long
			if (args[i][0] != '-' || args[i].size() != 2)
				continue;
			// Continued by letter that tells what should be done
			switch (args[i][1])
			{
				case 't':
					// Run tests instead of the actual game
					break;
				case 'f':
					// Read configs from specified file
					break;
				case 'c':
					// Write configs to specific file
					break;
				default:
					break;
			}
		}
	}

	int run(std::vector<string::String> args)
	{
		parseArgs(args);

		// Initialise everything
		window::Window window;
		input::registerCallbacks(window);

		while(!window.shouldClose())
		{
			// Get time for this update
			// Get input events and state
			// Create next updated state
			// Create render instructions for the state
			// Send render instructions for the renderer
			// Check if still running
			// Wait for minimum update time
			// Set new state as old one
		}
		return 0;
	}
}
