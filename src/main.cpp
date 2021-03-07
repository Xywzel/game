#include <vector>

#include "game/Game.h"
#include "string/String.h"

int main(int argc, char** argv)
{
	std::vector<string::String> args;
	for(int i = 0; i < argc; ++i)
		args.push_back(string::String(argv[i]));
	return game::run(args);
}
