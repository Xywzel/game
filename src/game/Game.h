#include <vector>

#include "macros.h"

DECLARE(string, String)

namespace game
{
	// Initialise and start the main loop for this game
	// Returns a status code 0 if run was suggesful
	int run(std::vector<string::String> args);
}
