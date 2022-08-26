#pragma once

class Point2D
{
public:
	Point2D();
	Point2D(int x, int y, char c);
	~Point2D();

	int		GetX();
	int		GetY();
	char	GetC();
	void	SetX(int x);
	void	SetY(int y);

	void	Display();
	void	Clear();

	void	MoveUp();
	void	MoveDown();
	void	MoveLeft();
	void	MoveRight();

private:
	int _x, _y;
	char _c;
};

