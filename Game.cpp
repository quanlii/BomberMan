#include "Game.h"


GameBomberMan::GameBomberMan()
{
	map = new Map2D;
	wall = new Wall(map);
	brick = new Brick(map);
	portal = new Portal(brick);
	monster = new Monster(map);
}

GameBomberMan::~GameBomberMan()
{
	delete map;
	delete wall;
	delete brick;
	delete portal;
	delete monster;
}

void GameBomberMan::OnePlayerMode()
{
	system("CLS");
	bomb1 = new Bomb;
	player1 = new BomberMan(1, 1, 'X');

	bool finish = false;

	map->DisplayMap(); player1->Display();
	GoToXY(0, MAX_HEIGHT);  cout << "Remaining lives: " << player1->_liveLeft;
	while (1)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 72 || ch == 80 || ch == 75 || ch == 77) player1->Move(map, ch, bomb1);
			else if (ch == ' ') player1->SetBomb(bomb1, map);
			else if (ch == 'p') _getch();
		}

		player1->Display();
		player1->GetPortal(map, bomb1, portal);
		if (!bomb1->_isExplosion)
		{
			if (bomb1->BombExplosion(map, portal, brick, &player1->_bomberMan, monster))
				player1->ResetBomberMan(bomb1);
		}
		if (player1->CollideMonster(monster))
		{
			player1->ResetBomberMan(bomb1); GoToXY(17, MAX_HEIGHT);
			cout << player1->_liveLeft;
		}

		monster->Move(map);
		monster->Display();

		if (brick->IsDestroyed() || !player1->_liveLeft || monster->IsDeadAll())
		{
			finish = true;
			break;
		}
	}
	system("CLS");
	if (brick->IsDestroyed() || monster->IsDeadAll()) cout << "CHUC MUNG BAN DA CHIEN THANG";
	else if (player1->_liveLeft == 0) cout << "GAME OVER";
}

void GameBomberMan::TwoPlayersMode()
{
	system("CLS");
	bomb1 = new Bomb; bomb2 = new Bomb;
	player1 = new BomberMan(1, 1, 'X');
	player2 = new BomberMan(15, 15, 'Y');

	bool finish = false;

	map->DisplayMap(); player1->Display(); player2->Display();
	GoToXY(0, MAX_HEIGHT);  cout << "Remaining lives of player 1: " << player1->_liveLeft;
	GoToXY(0, MAX_HEIGHT + 1);  cout << "Remaining lives of player 2: " << player2->_liveLeft;
}