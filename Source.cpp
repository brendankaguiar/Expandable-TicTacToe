#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Minimax.h"
using namespace std;
vector<Player> player;
void setup(int& playerCnt, int& gridSize);
void play(int gridSize);
void single_player(int gridSize);

int main()
{
	int again = 1;
	while (again)
	{
		int playerCnt;
		int gridSize;
		setup(playerCnt, gridSize);
		if (playerCnt == 1)
			single_player(gridSize);
		else
			play(gridSize);
		cout << "\nPlay again? 1 for yes, 0 for no.\n";
		cin >> again;
		if (again)
			player.clear();
	}
	return 0;
}

void single_player(int gridSize)
{
	Board board(gridSize);
	Player p('O');
	int move[3];
	int state[3][3];
	player.push_back(p);//add AI player
	bool gameOver = false;
	while (!gameOver)
	{
		board.make_move(player[0]);//player 1 moves
		gameOver = board.check_for_winner(player[0]);
		if (!gameOver)//AI player moves
		{
			board.apply_states(state);//update state for next minimax search
			Minimax game;
			game.max_value(state, move);
			board.AI_move(move);
			gameOver = board.check_for_winner(player[1]);
		}
	}
	board.get_grid();
	if (board.get_winner() == "Tie")
		cout << "Tie! No one wins.";
	else
		cout << board.get_winner() << " is the winner!\n\n\n\n\n\n";

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
		cout << "Welome to Tic Tac Toe. How many players will be playing? Between 1 and 5 allowed.\n";
		cin >> playerCnt;
		cout << playerCnt << " players.\n";
		if (playerCnt == 1)
			gridSize = 3;
		else
		{
			cout << "What is the size of the square grid? Between 3 and 6 allowed.\n";
			cin >> gridSize;
			if (playerCnt < 6 && playerCnt > 0 && gridSize < 7 && gridSize > 2)
				grant = false;
			else
				cout << "Invalid player amount or grid size. Try again.\n\n\n\n\n\n";
		}
		grant = false;
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
