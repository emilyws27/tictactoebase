#include "Common.h"
#include <iostream>
int usage_message(char* name)
{
std::cout << "usage:" << name << " TicTacToe" << std::endl; //outputs the helpful message telling user to include the name of the program which is the prameter name and then to also include the textfile.txt
return Inc_cmdargs; //returns the outcome for incorrect number of command line arguments
}
