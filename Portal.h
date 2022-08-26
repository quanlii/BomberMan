#pragma once
#include "Brick.h"
#include "Until.h"

class Portal
{
public:
	Portal(Brick brick);
	~Portal();

	Point2D _portal[MAX_BRICK];
	//bool	_isGot[MAX_BRICK];
	int		_numberOfPortal;

	int		GetKindOfPortal(Point2D portal);
	int		GetNumberOfPortal();
	int		GetIdOfPortal(int x, int y);
	void	SetPortal(Brick brick);
	void	DisplayPortal(Point2D portal);
private:

};
