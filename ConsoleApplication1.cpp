#include <iostream>
#include <SFML/Graphics.hpp>
#include "Until.h"
#include "Map2D.h"
#include "Wall.h"
#include "Portal.h"
#include "Brick.h"
#include "BomberMan.h"
#include "Bomb.h"
#include "Monster.h"
#include <conio.h>
#include <thread>
#include <mutex>
#include <ctime>
using namespace std;

void Pause(bool& pause)
{
	_getch();
	pause = false;
}

/*void MyButtonPress(BomberMan *player, Bomb &bomb, Wall wall, Brick brick, Portal portal)
{
while(!brick.IsDestroyed() && player._liveLeft)
{
if(_kbhit())
{
char ch = _getch();
if(ch == 72) player -> TurnUp();
else if(ch == 80) player -> TurnDown();
else if(ch == 75) player -> TurnLeft();
else if(ch == 77) player -> TurnRight();
else if(ch == ' ') player -> SetBomb(bomb, wall, brick, portal);
}
Sleep(10);
}
}*/

void MonsterMove(Monster* monster, Map2D* map, Bomb* bomb, bool finish)
{
	while (1)
	{
		monster->Move(*map, *bomb);
		monster->Display();
		if (finish) break;

	}
}

void Player1(BomberMan* player, Map2D* map, Bomb* bomb, bool finish)
{
	while (1)
	{
		player->Display();
		if (finish) break;
	}
}

int main()
{
	Map2D map; Wall wall(map);  Brick brick(map);
	Portal portal(brick);
	Monster monster(map);
	Bomb bomb; BomberMan player;
	bool finish = false;

	//thread t1(Pause, true);
	map.DisplayMap(); player.Display();
	GoToXY(0, MAX_HEIGHT);  cout << "Remaining lives: " << player._liveLeft;
	//thread player1(Player1, &player, &map, &bomb, finish);
	//thread monsterMove(MonsterMove, &monster, &map, &bomb, finish);
	int count = 0;
	while (1)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 72 || ch == 80 || ch == 75 || ch == 77) player.Move(map, ch, bomb);
			else if (ch == ' ') player.SetBomb(bomb, map);
			else if (ch == 'p') _getch();
		}

		player.Display();
		player.GetPortal(map, bomb, portal);
		if (!bomb._isExplosion)
		{
			if (bomb.BombExplosion(map, portal, brick, player._bomberMan))
			{
				player.ResetBomberMan(bomb);
				GoToXY(17, MAX_HEIGHT); cout << player._liveLeft;
			}
		}

		monster.Move(map, bomb);
		monster.Display();

		if (brick.IsDestroyed() || !player._liveLeft)
		{
			finish = true;
			break;
		}
	}
	system("CLS");
	if (brick.IsDestroyed()) cout << "CHUC MUNG BAN DA CHIEN THANG";
	else if (player._liveLeft == 0) cout << "GAME OVER";

	Sleep(5000);

	return 0;
}