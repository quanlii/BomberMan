#include <iostream>
#include "BomberMan.h"
using namespace std;

BomberMan::BomberMan(int x, int y, char icon)
{
	_speed = 100;
	_direction = 80;
	_bomberMan = Point2D(x, y, icon);
	_liveLeft = 3;
	_start = 0;
}

BomberMan :: ~BomberMan()
{
}

void BomberMan::Display()
{
	_bomberMan.Display();
}

void BomberMan::ResetBomberMan(Bomb* bomb)
{
	--_liveLeft; _speed = 100;
	bomb->ResetBomb();
	_bomberMan = Point2D(1, 1, 'X');
	_bomberMan.Display();
}

void BomberMan::ResetBomberManMode2(Bomb* bomb, int x, int y, char icon)
{
	if(_liveLeft > 0)
	{
		--_liveLeft; _speed = 100;
		bomb->ResetBomb();
		_bomberMan = Point2D(x, y, icon);
	}
	else _bomberMan = Point2D(0, 0, '#');
	_bomberMan.Display();
}

bool BomberMan::CheckIsDead()
{
	if (_liveLeft <= 0) return true;
	return false;
}

void BomberMan::GetPortal(Map2D* map, Bomb* bomb, Portal* portal)
{
	int x = _bomberMan.GetX(), y = _bomberMan.GetY();
	int idPortal = portal->GetIdOfPortal(x, y);
	if (map->_map[y][x].GetC() == 'S' && !portal->_isGot[idPortal])
	{
		SpeedUp();
		map->_map[y][x] = Point2D(x, y, ' ');
		portal->_isGot[idPortal] = true;
	}
	if (map->_map[y][x].GetC() == 'P' && !portal->_isGot[idPortal])
	{
		bomb->PowerUp(),
			map->_map[y][x] = Point2D(x, y, ' ');
		portal->_isGot[idPortal] = true;
	}
}

void BomberMan::SetBomb(Bomb* bomb, Map2D* map)
{
	if (bomb->_isExplosion) bomb->SetBomb(_bomberMan.GetX(), _bomberMan.GetY(), map);
}


void BomberMan::TurnUp(Map2D* map)
{
	if (CheckPosition(_bomberMan.GetX(), _bomberMan.GetY() - 1, map)) _bomberMan.MoveUp();
}

void BomberMan::TurnDown(Map2D* map)
{
	if (CheckPosition(_bomberMan.GetX(), _bomberMan.GetY() + 1, map)) _bomberMan.MoveDown();
}

void BomberMan::TurnLeft(Map2D* map)
{
	if (CheckPosition(_bomberMan.GetX() - 1, _bomberMan.GetY(), map)) _bomberMan.MoveLeft();
}

void BomberMan::TurnRight(Map2D* map)
{
	if (CheckPosition(_bomberMan.GetX() + 1, _bomberMan.GetY(), map)) _bomberMan.MoveRight();
}

void BomberMan::Move(Map2D* map, char direction, Bomb* bomb)
{
	int x = _bomberMan.GetX(), y = _bomberMan.GetY();
	if (_start > 0 && ((clock() - _start) / (double)CLOCKS_PER_SEC) < (float)_speed / 1000.0) return;
	_start = 0;
	_bomberMan.Clear();
	if (direction == 72 || direction == 'w') TurnUp(map);
	else if (direction == 80 || direction == 's') TurnDown(map);
	else if (direction == 75 || direction == 'a') TurnLeft(map);
	else if (direction == 77 || direction == 'd') TurnRight(map);
	if (!bomb->_isExplosion)
	{
		map->_map[bomb->_bomb.GetY()][bomb->_bomb.GetX()] = Point2D(bomb->_bomb.GetX(), bomb->_bomb.GetY(), 'O');
		bomb->_bomb.Display();
	}
}


void BomberMan::SpeedUp()
{
	if (_speed > 25) _speed -= 25;
}

bool BomberMan::CheckPosition(int x, int y, Map2D* map)
{
	if (map->_map[y][x].GetC() == 'S' || map->_map[y][x].GetC() == 'P' || map->_map[y][x].GetC() == ' ') return true;
	return false;
}

bool BomberMan::CollideMonster(Monster* monster)
{
	for (int i = 0; i < MAX_MONSTER; ++i)
		if (!monster->_checkDead[i] && _bomberMan.GetX() == monster->_monster[i].GetX() && _bomberMan.GetY() == monster->_monster[i].GetY())
			return true;
	return false;
}

void BomberMan::DisplayBomberManUI(sf::Sprite &spBomberMan, sf::RenderWindow &window)
{
	if ( _bomberMan.GetC() == 'X') 
	{
		spBomberMan.setPosition(_bomberMan.GetX()*SIZE_CELL, _bomberMan.GetY()*SIZE_CELL);
		window.draw(spBomberMan);
	}

}