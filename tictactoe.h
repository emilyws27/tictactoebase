#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <sstream>
#include "Common.h"
#include "pieces.h"
using namespace std;

class tictactoe {
public:
	tictactoe();
	~tictactoe() {};
	bool done();
	friend ostream& operator<<(ostream& out, const tictactoe& t);
	bool draw();
	int prompt(unsigned int& a, unsigned int& b);
	int turn();
	int play();
private:
	game_pieces X;
	game_pieces O;
	int turns;
	game_pieces board[board_rows][board_columns];
};


