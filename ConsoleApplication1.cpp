#include <iostream>
#include <SFML/Graphics.hpp>
#include "Until.h"
#include "Map2D.h"
#include "Wall.h"
#include "Portal.h"
#include "Brick.h"
#include "BomberMan.h"
#include "Bomb.h"
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
/*
void MyButtonPress(BomberMan *player, Bomb &bomb, Wall wall, Brick brick, Portal portal)
{
	while(1)
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



int main()
{
	time_t now = time(0);
	Map2D map; Wall wall(map);  Brick brick(map);
	Portal portal(brick);
	Bomb bomb; BomberMan player;
	player.Display();

	//thread buttonPress(MyButtonPress, &player, ref(bomb), wall, brick, portal);
	//thread t1(Pause, true);
	map.DisplayMap();
	GoToXY(0, MAX_HEIGHT);  cout << "Remaining lives: " << player._liveLeft;
	while (!brick.IsDestroyed() && player._liveLeft)
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
			if (bomb.BombExplosion(map, portal, brick, player._bomberMan))
			{
				player.ResetBomberMan(bomb);
				GoToXY(17, MAX_HEIGHT); cout << player._liveLeft;
			}
	}

	system("CLS");
	if (brick.IsDestroyed()) cout << "CHUC MUNG BAN DA CHIEN THANG";
	else if (player._liveLeft == 0) cout << "GAME OVER";

	return 0;
}