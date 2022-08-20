#ifndef Minimax_H
#define Minimax_H

class Minimax
{
public:
	Minimax();
	void to_move(int state[][3]);
	bool is_terminal(int state[][3]);
	int utility(int state[][3]);
	void actions(int a[][2], int state[][3]);
	void result(int state[][3], int a[]);
	void max_value(int state[][3], int move[]);
	void min_value(int state[][3], int move[]);
private:
	int transition[3][3];
	int player;
};
#endif
