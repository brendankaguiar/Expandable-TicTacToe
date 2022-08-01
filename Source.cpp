#include <iostream>
#include "Board.h"
#include "Player.h"
#include <vector>
using namespace std;
vector<Player> player;
void setup(int& playerCnt, int& gridSize);
void play(int gridSize);
int main()
{
	int again = 1;
	while (again)
	{
		int playerCnt;
		int gridSize;
		setup(playerCnt, gridSize);
		play(gridSize);
		cout << "\nPlay again? 1 for yes, 0 for no.\n";
		cin >> again;
		if (again)
			player.clear();
	}
	return 0;
}
void play(int gridSize)
{
	Board board(gridSize);
	bool gameOver = false;
	while (!gameOver)
	{
		for (int n = 0; n < player.size(); n++)
		{
			board.make_move(player[n]);
			gameOver = board.check_for_winner(player[n]);
			if (gameOver)

				n = player.size();
		}
	}
	board.get_grid();
	if (board.get_winner() == "Tie")
		cout << "Tie! No one wins.";
	else
		cout << board.get_winner() << " is the winner!\n\n\n\n\n\n";
}

void setup(int& playerCnt, int& gridSize)
{
	bool grant = true;
	while (grant)
	{
		cout << "Welome to Tic Tac Toe. How many players will be playing? Between 2 and 5 allowed.\n";
		cin >> playerCnt;
		cout << playerCnt << " players.\n";
		cout << "What is the size of the square grid? Between 3 and 6 allowed.\n";
		cin >> gridSize;
		if (playerCnt < 6 && playerCnt > 1 && gridSize < 7 && gridSize > 2)
			grant = false;
		else
			cout << "Invalid player amount or grid size. Try again.\n\n\n\n\n\n";
	}
	cout << "Almost ready to start...\n";
	char token[5] = { 'X','O','@','$','%' };
	for (int i = 0; i < playerCnt; i++)
	{
		cout << "Player " << i + 1 << ". Your token is " << token[i] << ".\n";
		Player p(token[i]);
		player.push_back(p);
	}
}