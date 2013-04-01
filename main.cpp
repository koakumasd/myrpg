#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
//#include "getch.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#include "def.h"
#include "base.h"
#include "func.h"
#include "hero.h"


    char map[globalMapX][globalMapY];
    Base *hero;
    Base *mob;
    int main()
    {
        hero=new Hero();
        srand((unsigned)time(NULL));
        createMapFromFile(map);
        CreateHero_and_randomMobs(map,hero);
        All(map,hero,mob);
        return 0;
    }