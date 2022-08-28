#pragma once
#include "Point2D.h"
#include "Wall.h"
#include "Brick.h"
#include "Portal.h"
#include "Bomb.h"
#include "Monster.h"
#include "UI.h"

class BomberMan
{
public:
	BomberMan(int x, int y, char icon);
	~BomberMan();

	Point2D	_bomberMan;
	int		_speed;
	int		_liveLeft;
	char	_direction;
	int		_start;

	void	Move(Map2D* map, char direction, Bomb* bomb);
	void	TurnUp(Map2D* map);
	void	TurnDown(Map2D* map);
	void	TurnLeft(Map2D* map);
	void	TurnRight(Map2D* map);
	void	Display();
	void	DisplayBomberManUI(sf::Sprite& spBomberMan, sf::RenderWindow& window);

	void	ResetBomberMan(Bomb* bomb);
	void	ResetBomberManMode2(Bomb* bomb, int x, int y, char icon);

	void	SetBomb(Bomb* bomb, Map2D* map);
	void	GetPortal(Map2D* map, Bomb* bomb, Portal* portal);
	void	SpeedUp();
	bool	CollideMonster(Monster* monster);
	bool	CheckIsDead();
	bool	CheckPosition(int x, int y, Map2D* map);
private:

};