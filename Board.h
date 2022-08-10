#ifndef Board_H
#define Board_H
#include "Player.h"
#include <string>
#include <iostream>
#include <vector>
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
	void apply_states(int state[][3]);
	bool check_for_winner(const Player p);
	void get_grid();
	int get_size() const;
	void make_move(const Player p);
	void AI_move(int move[]);
	string get_winner() const;
};
#endif // !_Board
