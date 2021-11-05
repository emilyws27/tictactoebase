#include "tictactoe.h"
#include <iostream>
#include <string>
#include <vector>
#include "Common.h"
#include "pieces.h"


using namespace std;

//definine my member variables for tictactoe class and initializing them.
tictactoe::tictactoe() : X(game_pieces("X", "X")), O(game_pieces("O", "O")), turns(1) {
	game_pieces board[board_rows][board_columns];
	for (int i = 0; i < board_rows; i++) {
		for (int j = 0; j < board_columns; j++) {
			game_pieces blank = game_pieces();
			board[i][j] = blank;
		}
	}
}

//definine << operator so that it knows how to print out the board
ostream& operator<<(ostream& out, const tictactoe& t) {
	for (int i = board_rows - 1; i >= 0; i--) {
		cout << i;
		for (int j = 0; j <= board_columns - 1; j++) {
			out << t.board[i][j].appearance << " ";
		}
		out << endl;
	}
	cout << " " <<  0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
	return out;
}

//created 8 if or else if statements for the 8 possible winning formations, first tested to make sure that there was either a X or a O in the spot before comparing, if none of the 8 possibilities were true than no winner
bool tictactoe::done() {
	if (board[cord3][cord1].appearance != " " && board[cord3][cord1].appearance == board[cord3][cord2].appearance && board[cord3][cord1].appearance == board[cord3][cord3].appearance)
	{ //horizontal 3 in a row top
		return true;
	}
	else if (board[cord3][cord1].appearance != " " && board[cord3][cord1].appearance == board[cord2][cord1].appearance && board[cord3][cord1].appearance == board[cord1][cord1].appearance)
	{ //vertical 3 left
		return true;
	}
	else if (board[cord3][cord1].appearance != " " && board[cord3][cord1].appearance == board[cord2][cord2].appearance && board[cord3][cord1].appearance == board[cord1][cord3].appearance)
	{ //diagnoal top left to bottom right
		return true;
	}
	else if (board[cord3][cord3].appearance != " " && board[cord3][cord3].appearance == board[cord2][cord2].appearance && board[cord3][cord3].appearance == board[cord1][cord1].appearance)
	{ //diagnoal top right to bottom left
		return true;
	}
	else if (board[cord3][cord3].appearance != " " && board[cord3][cord3].appearance == board[cord2][cord3].appearance && board[cord3][cord3].appearance == board[cord1][cord3].appearance)
	{ //right vertical
		return true;
	}
	else if (board[cord1][cord1].appearance != " " && board[cord1][cord1].appearance == board[cord1][cord2].appearance && board[cord1][cord1].appearance == board[cord1][cord3].appearance)
	{ //bottom horizontal
		return true;
	}
	else if (board[cord2][cord1].appearance != " " && board[cord2][cord1].appearance == board[cord2][cord2].appearance && board[cord2][cord1].appearance == board[cord2][cord3].appearance)
	{ //middle Horizontal
		return true;
	}
	else if (board[cord3][cord2].appearance != " " && board[cord3][cord2].appearance == board[cord2][cord2].appearance && board[cord3][cord2].appearance == board[cord1][cord2].appearance)
	{ //middle vertical
		return true;
	}
	else {
		return false; //nobody is a winner
	}
}

//tests for draw, turns starts at 1 so when it hits 10 that means all possible boxes will either be filled with a X or O
bool tictactoe::draw() {
	if (done())
	{
		return false;
	}
	else if (turns != 10) //create another case for when there are no moves left, create member variable for turns increment turns after each turn and when turns hits 9 then no moves left
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Asks the user to type in the coordinate of where they would like to play and if they input it correctly it will replace the comma with a space and wraps it in a istringstream allowing me to extract the first and second coordinates. If they inputted it improperly, will return a message saying such.
int tictactoe::prompt(unsigned int& a, unsigned int& b)
{
	string coordinate;
		cout << "Type quit to quit or type enter two numbers with a comma in the middle to represent the coordinates of where you would like to play example: 0,0" << endl;
		cin >> coordinate;
		if (coordinate == "quit") {
			cout << "you have quit" << endl;
			return user_quit;
		}
		else {
			replace(coordinate.begin(), coordinate.end(), ',', ' ');
			istringstream iss(coordinate);
			if (iss >> a && iss >> b) {
				return coord_extraction_success;
			}
			else {
				cout << "you have inputted the coordinates improperly ";
				return prompt(a, b);
			}
		}
}


//prints out the initial empty game board and says which player is going first. Then it calls on prompt and as long as user doesn't quit and the coordinate is a valid spot it will replace that empty spot with an X or O and print out the board and where the player moved
//To switch between players I usde an odd and even system for a member variable turns and if the user chose a spot that doesn't work, an appropriate message is returned
int tictactoe::turn() {
	vector<int> v_O;
	vector<int> v_X;
	unsigned int x, y;
	if (turns == 1)
	{
		cout << *this << endl;
		cout << "Player O Goes first" << endl;
	}
	if (prompt(x, y) != user_quit) {
		if (turns % 2 == 1) {		//even is player X, odd is player O
			cout << endl << "Next Move is Player X" << endl;
			if (board[x][y].appearance == " " && x >= cord1 && x <= cord3 && y >= cord1 && y <= cord3) //within the boundaries of a valid spot and the spot is empty
			{
				board[x][y] = O;
				v_O.push_back(x);
				v_O.push_back(y);
				cout << *this << endl;
				cout << "Player O Played: " << x << ", " << y << endl << endl;
				turns++;
				return valid_value;
			}
			else
			{
				cout << "Cannot move there, try again" << endl;
				return turn();
			}
		}
		else
		{
			cout << endl << "Next Move is Player O" << endl;
			if (board[x][y].appearance == " " && x >= cord1 && x <= cord3 && y >= cord1 && y <= cord3) //within the boundaries of a valid spot and the spot is empty
			{
				board[x][y] = X;
				v_X.push_back(x);
				v_X.push_back(y);
				cout << *this << endl;
				cout << "Player X Played: " << x << ", " << y << "; " << v_X[0] << v_X[1] << endl << endl;
				turns++;
				return valid_value;
			}
			else
			{
				cout << "Cannot move there, try again" << endl;
				return turn();
			}
		}
	}
	else {
		return turn_userquit;
	}
}


//checks if there is a winner, draw, or if someone quit and will output appropriate message, amount of turns is turns-1 because I started turns at 1. If there is no winner, draw, or quit, then it will keep recursively calling itself and turn for the players input on where to move.
int tictactoe::play(){
	if (done() == true)
	{
		if (turns % 2 == 0)
		{
			cout << "Player O won the game";
			return success;
		}
		else
		{
			cout << "Player X won the game";
			return success;
		}
	}
	else if (draw() == true)
	{
		cout << "There were: " << turns -1 << " turns and there are no winning moves remaining, game is a draw" << endl;
		return game_draw;
	}
	else if (turn() == turn_userquit)
	{
		cout << "There were " << turns-1 << " turns" << endl;
		return play_userquit;
	}
	else {
		return play();
	}
}
