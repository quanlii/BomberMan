#pragma once
#include <iostream>
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

class GameBomberMan
{
public:
	GameBomberMan();
	~GameBomberMan();

	Map2D		*map; 
	Wall		*wall; 
	Brick		*brick;
	Portal		*portal;
	Monster		*monster;
	Bomb		*bomb1, *bomb2; 
	BomberMan	*player1, *player2;

	void		OnePlayerMode();
	void		TwoPlayersMode();

private:

};
