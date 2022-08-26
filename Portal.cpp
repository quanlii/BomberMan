#include "Portal.h"

void Portal::SetPortal(Brick brick)
{
	int x, y, kind;
	_numberOfPortal = brick.GetNumberOfBrick();
	for (int i = 0; i < _numberOfPortal; ++i)
	{
		x = brick._brick[i].GetX();
		y = brick._brick[i].GetY();

		kind = GetRandomNumber(10000);
		if (kind % 3 == 0) _portal[i] = Point2D(x, y, ' ');
		else if (kind % 3 == 1) _portal[i] = Point2D(x, y, 'S'); //Item speed up
		else if (kind % 3 == 2) _portal[i] = Point2D(x, y, 'P'); //Item power of bomb up
	}

}

Portal::Portal(Brick brick)
{
	SetPortal(brick);
}

Portal::~Portal() {}

int Portal::GetKindOfPortal(Point2D portal)
{
	if (portal.GetC() == ' ') return 0;
	else if (portal.GetC() == 'S') return 1;
	else if (portal.GetC() == 'P') return 2;
}

int	Portal::GetIdOfPortal(int x, int y)
{
	for (int i = 0; i < _numberOfPortal; ++i)
		if (x == _portal[i].GetX() && y == _portal[i].GetY()) return i;
}

void Portal::DisplayPortal(Point2D portal)
{
	portal.Display();
}

int Portal::GetNumberOfPortal() { return _numberOfPortal; }
