#include <iostream>
#include <SFML/Graphics.hpp>
#include "Until.h"
#include "Map2D.h"
#include "Wall.h"
#include "Portal.h"
#include "Brick.h"
#include <conio.h>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    Map2D map; Wall wall;
    map.DisplayMap(); wall.DisplayWall();
    Brick brick(wall); brick.DisplayBrick();
    Portal portal(brick); 
    int i = 0;
    while (1)
    {
        if (_kbhit())
        {
            char c = _getch();
            portal.DisplayPortal(portal._portal[i++]);
            Sleep(1000);
        }
    }
        

      return 0;
}