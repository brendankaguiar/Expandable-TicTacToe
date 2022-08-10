#include "Board.h"
Board::Board(const int _size) :size(_size) {}

bool Board::check_for_winner(const Player p)
{
	bool hoz = false;
	bool vert = false;
	bool diag1 = false;
	bool diag2 = false;
	bool tie = false;
	int hcount = 0;//increment to check pieces on board in alignment
	int vcount = 0;
	int tcount = 0;
	int d1count = 0;
	int d2count = 0;
	for (int n = 0; n < size; n++)
	{
		for (int m = 0; m < (2 * size) - 1; m = m + 2)//check horizontal and tie
		{
			if (p.getToken() == grid[n][m])
				hcount++;
			if (grid[n][m] != '_')
				tcount++;
		}
		if (hcount < size)
			hcount = 0;
		else
			hoz = true;
		if (tcount == size * size)
			tie = true;
	}
	for (int m = 0; m < (2 * size) - 1; m = m + 2)//check vertical
	{
		for (int n = 0; n < size; n++)//check diagonal 1
		{
			if (p.getToken() == grid[n][m])
				vcount++;
		}
		if (vcount < size)
			vcount = 0;
		else
			vert = true;
	}
	for (int m = 0; m < size; m++)//check diagonal 2
	{
		if (p.getToken() == grid[m][m * 2])
			d1count++;
	}
	if (d1count == size)
		diag1 = true;
	int n = 0;
	for (int m = size - 1; m >= 0; m--)
	{
		if (p.getToken() == grid[m][n])
			d2count++;
 		n = n + 2;
	}
	if (d2count == size)
		diag2 = true;
	if (hoz || vert || diag1 || diag2)
		winner = p.getToken();
	if (tie)
		winner = "Tie";
	return hoz || vert || diag1 || diag2 || tie;
}
string Board::get_winner() const
{
	return winner;
}
int Board::get_size() const
{
	return size;
}
void Board::get_grid()
{	
	for (int n = 65; n < size + 65; n++)
		cout << char(n) << " ";
	cout << endl;
	for (int n = 0; n < size; n++)
	{
		for (int m = 0; m < (2 * size) - 1; m++)
		{
			cout << grid[n][m];
		}
		cout << " " << n << endl;
	}
}
void Board::make_move(const Player p)
{
	char coordinates[2];
	bool grant = true;
	while (grant)
	{
		get_grid();
		cout << "Enter your coordinates player: " << p.getToken() << " to make your move\n";
		cout << "Enter Letter : ";
		cin >> coordinates[0];
		cout << "Enter Number : ";
		cin >> coordinates[1];
		if (int(coordinates[1]) - 48 >= 0 && int(coordinates[1]) - 48 <= size - 1 && (int(coordinates[0]) - 65) * 2 >= 0 && (int(coordinates[0]) - 65) * 2 < size * 2 - 1)
		{
			if (grid[int(coordinates[1]) - 48][(int(coordinates[0]) - 65) * 2] == '_')
			{
				grid[int(coordinates[1]) - 48][(int(coordinates[0]) - 65) * 2] = p.getToken();
				cout << "\n\n\n\n\n";
				grant = false;
			}
			else
				cout << "Space taken. Try again.\n\n\n\n\n\n";
		}
		else
			cout << "Space outside of grid. Try again.\n\n\n\n\n\n";

	}
}

void Board::AI_move(int move[])
{
	grid[move[0]][move[1] * 2] = 'O';
}
void Board::apply_states(int state[][3])
{
	int i = 0;
	for (int n = 0; n < size; n++)//check rows
	{
		int j = 0;
		for (int m = 0; m < (2 * size) - 1; m = m + 2)//check cols
		{
			if (grid[n][m] == 'O')
				state[i][j] = 1;
			else if (grid[n][m] == 'X')
				state[i][j] = -1;
			else
				state[i][j] = 0;
			j++;
		}
		i++;
	}
}
