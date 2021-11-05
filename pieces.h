#pragma once
#include <string>

struct game_pieces {
	game_pieces();

	game_pieces(std::string name, std::string appearance);

	std::string name;
	std::string appearance;
};

