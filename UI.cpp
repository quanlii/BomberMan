#include "UI.h"
#include <SFML/Graphics.hpp>
#pragma comment (lib, "sfml-graphics-d.lib")
#pragma comment (lib, "sfml-audio-d.lib")
#pragma comment (lib, "sfml-network-d.lib")
#pragma comment (lib, "sfml-window-d.lib")
#pragma comment (lib, "sfml-system-d.lib")
using namespace sf;
UI::UI()
{
	window = new sf::RenderWindow(sf::VideoMode(MAX_WIDTH * SIZE_CELL + 200, MAX_HEIGHT * SIZE_CELL), "SFML example");
	window->clear();

	t1 = new sf::Texture();
	t2 = new sf::Texture();
	t3 = new sf::Texture();
	t4 = new sf::Texture();
	t5 = new sf::Texture();


	t1->loadFromFile("C:/Users/FPTShop/Desktop/Bomb/Image/01.png");
	t2->loadFromFile("C:/Users/FPTShop/Desktop/Bomb/Image/02.png");
	t3->loadFromFile("D:/iimei/Brick.png");
	t4->loadFromFile("D:/iimei/Bomberman.png");
	t5->loadFromFile("D:/iimei/monster.png");


	spriteBackground = new Sprite(*t1);
	spriteWall = new Sprite(*t2);
	spriteBrick = new Sprite(*t3);
	spriteBomberMan = new Sprite(*t4);
	spriteMonster = new Sprite(*t5);
}
UI ::~UI() {}
