#pragma once
#include "Brick.h"
#include "Until.h"

class Portal
{
public:
	Portal(Brick brick);
	~Portal();
	
	Point2D _portal[MAX_WALL];

	int		GetKindOfPortal(Point2D portal);
	void	SetPortal(Brick brick);
	void	DisplayPortal(Point2D portal);
private:
	
};

