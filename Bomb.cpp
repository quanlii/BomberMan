#include "Bomb.h"
#include <iostream>
using namespace std;

const int px[4] = { 0, 0, -1, 1 };
const int py[4] = { -1, 1, 0, 0 };

Bomb::Bomb()
{
	_power = 1; _isExplosion = true;
}

Bomb::~Bomb() {}

bool Bomb::BombExplosion(Map2D& map, Portal portal, Brick& brick, Point2D player)
{
	if (_start > 0 && ((clock() - _start) / (double)CLOCKS_PER_SEC) < 2)
		return false;
	_start = 0;
	int x = _bomb.GetX(), y = _bomb.GetY(), id;
	bool isBomberManExplosion = false;

	//Hien thi power cua bom
	GoToXY(x, y); cout << '=';
	bool direct[4] = { true, true, true, true };
	for (int i = 1; i <= _power; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (!direct[j]) continue;
			else
			{
				int x1 = x + i * px[j], y1 = y + i * py[j];
				id = portal.GetIdOfPortal(x1, y1);
				if (map._map[y1][x1].GetC() == 'W' || map._map[y1][x1].GetC() == '#') { direct[j] = false; continue; }
				else
				{
					GoToXY(x1, y1), cout << '=';
					if (map._map[y1][x1].GetC() == 'B') direct[j] = false;
				}
			}
		}
	}
	Sleep(100);

	//Hien thi portal
	direct[0] = direct[1] = direct[2] = direct[3] = true;
	for (int i = 1; i <= _power; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (!direct[j]) continue;
			else
			{
				int x1 = x + i * px[j], y1 = y + i * py[j];
				id = portal.GetIdOfPortal(x1, y1);
				if (map._map[y1][x1].GetC() == 'W' || map._map[y1][x1].GetC() == '#') { direct[j] = false; continue; }
				if (x1 == player.GetX() && y1 == player.GetY()) isBomberManExplosion = true;

				if (map._map[y1][x1].GetC() == 'B' && !brick._isDestroyed[y1][x1])
				{
					map._map[y1][x1] = portal._portal[id];
					direct[j] = false;
					brick._isDestroyed[y1][x1] = true;
				}
				map._map[y1][x1].Display();
			}
		}
	}
	map._map[y][x] = Point2D(x, y, ' '); map._map[y][x].Display();
	_isExplosion = true;
	if (x == player.GetX() && y == player.GetY()) isBomberManExplosion = true;

	if (isBomberManExplosion) return true;
	else return false;
}

void Bomb::SetBomb(int x, int y, Map2D map)
{
	if (map._map[y][x].GetC() == ' ')
		_bomb = Point2D(x, y, 'O'), _bomb.Display();
	_isExplosion = false;
	_start = clock();
}

void Bomb::PowerUp()
{
	if (_power < 5) ++_power;
}

void Bomb::ResetBomb()
{
	_power = 1;
}