#ifndef Board_H
#define Board_H
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;
class Board
{
private:
	int size;
	char grid[6][12] = { { '_', '|', '_', '|', '_', '|', '_', '|', '_', '|', '_'},
		{ '_','|' ,'_','|','_','|','_','|','_', '|','_'},
		{ '_','|' ,'_','|','_','|','_','|','_', '|','_'},
		{ '_','|' ,'_','|','_','|','_','|','_', '|','_'},
		{ '_','|' ,'_','|','_','|','_','|','_', '|','_'},
		{ '_','|' ,'_','|','_','|','_','|','_', '|','_'} };
	string winner;
public:
	Board(const int _size);
	bool check_for_winner(const Player p);
	void get_grid();
	void make_move(const Player p);
	string get_winner();
};
#endif // !_Board
