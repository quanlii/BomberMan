#pragma once
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Until.h"
#pragma comment (lib, "sfml-graphics-d.lib")
#pragma comment (lib, "sfml-audio-d.lib")
#pragma comment (lib, "sfml-network-d.lib")
#pragma comment (lib, "sfml-window-d.lib")
#pragma comment (lib, "sfml-system-d.lib")

using namespace std;
using namespace sf;

class UI
{
public:
	UI();
	~UI();

	sf::RenderWindow* window;
	Texture* t1, * t2, * t3, * t4, * t5;
	Sprite* spriteBackground;
	Sprite* spriteBomberMan;
	Sprite* spriteWall;
	Sprite* spriteBrick;
	Sprite* spriteMonster;

	char    StartUI();
private:

};
