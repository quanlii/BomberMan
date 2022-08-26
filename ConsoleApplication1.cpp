#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main()
{
	/*Map2D map; Wall wall(&map); Brick brick(&map);
	Portal portal(&brick);
	Monster monster(&map);
	Bomb bomb; BomberMan player;
	bool finish = false;

	map.DisplayMap(); player.Display();
	GoToXY(0, MAX_HEIGHT);  cout << "Remaining lives: " << player._liveLeft;

	while (1)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 72 || ch == 80 || ch == 75 || ch == 77) player.Move(&map, ch, &bomb);
			else if (ch == ' ') player.SetBomb(&bomb, &map);
			else if (ch == 'p') _getch();
		}

		player.Display();
		player.GetPortal(&map, &bomb, &portal);
		if (!bomb._isExplosion)
		{
			if (bomb.BombExplosion(&map, &portal, &brick, &player._bomberMan, &monster))
			{
				player.ResetBomberMan(&bomb);
				
			}
		}
		if (player.CollideMonster(&monster))
		{
			player.ResetBomberMan(&bomb); GoToXY(17, MAX_HEIGHT);
			cout << player._liveLeft;
		}

		monster.Move(&map);
		monster.Display();

		if (brick.IsDestroyed()|| !player._liveLeft || monster.IsDeadAll())
		{
			finish = true;
			break;
		}
	}
	system("CLS");
	if (brick.IsDestroyed() || monster.IsDeadAll()) cout << "CHUC MUNG BAN DA CHIEN THANG";
	else if (player._liveLeft == 0) cout << "GAME OVER";*/

	char turn = 'Y';

	while (turn == 'Y')
	{
		system("CLS");
		GameBomberMan* newGame = new GameBomberMan;
		int mode = 0;

		cout << "Choose player mode: " << endl;
		cout << "1. 1 player \t2. 2 players" << endl;
		cout << "Your choice: "; cin >> mode;

		while (mode != 1 && mode != 2)
		{
			cout << "Your choice: "; cin >> mode;
		}

		if (mode == 1) newGame->OnePlayerMode();
		else newGame->TwoPlayersMode();
		//Sleep(3000);

		cout << "\nDo you want to play again? y/n?" << endl;
		cin >> turn;
		turn = toupper(turn);
	}



	return 0;
}