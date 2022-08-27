#include <iostream>
#include "Point2D.h"
#include "Until.h"
using namespace std;

Point2D::Point2D() {}

Point2D::~Point2D() {}

Point2D::Point2D(int x, int y, char c)
{
	_x = x, _y = y; _c = c;
}

int Point2D::GetX() { return _x; }

int Point2D::GetY() { return _y; }

char Point2D::GetC() { return _c; }

void Point2D::SetX(int x) { _x = x; }

void Point2D::SetY(int y) { _y = y; }

void Point2D::Display()
{
	GoToXY(_x, _y);
	cout << _c;
}

void Point2D::Clear()
{
	GoToXY(_x, _y);
	cout << ' ';
}

void Point2D::MoveUp() { --_y; }

void Point2D::MoveDown() { ++_y; }

void Point2D::MoveLeft() { --_x; }

void Point2D::MoveRight() { ++_x; }

