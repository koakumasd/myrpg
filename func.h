#include "mob.h"
//#include "hero.h"
    void out(char arr[globalMapX][globalMapY],Base *hero)
    {
        system("clear");

        int x=0;
        x=hero->getXcord();
        int y=0;
        y=hero->getYcord();
        if(x<=9&&y<=9)
             for(int i=0; i<19; i++) {
                     for(int j=0; j<19; j++)
                             cout << arr[i][j] << " ";
                         cout<<endl;}

        else if(x>=191&&y>=191)
             for(int i=181; i<globalMapX; i++) {
                     for(int j=181; j<200; j++)
                             cout << arr[i][j] << " ";
                         cout<<endl;}
        else if(x>=191&&y<=9)
             for(int i=181; i<globalMapX;i++) {
                     for(int j=0; j<19; j++)
                             cout << arr[i][j] << " ";
                         cout<<endl;}
        else if(x<=9&&y>=191)
             for(int i=0; i<19; i++) {
                     for(int j=181; j<200; j++)
                             cout << arr[i][j] << " ";
                         cout<<endl;}
        else if(x-9<0)
             for(int i=0; i<19; i++) {
                     for(int j=y-9; j<y+9; j++)
                             cout << arr[i][j] << " ";
                         cout<<endl;}
        else if (y-9<0)
            for(int i=x-9; i<x+9; i++) {
                for(int j=0; j<19; j++)
             cout << arr[i][j] << " ";
        cout<<endl;}
        else if(y+9>199)
                     for(int i=x-9; i<x+9; i++) {
                            for(int j=181; j<200; j++)
                                     cout << arr[i][j] << " ";
                            cout<<endl;}
        else if(x+9>199)
            for(int i=181; i<200; i++) {
             for(int j=y-9; j<y+9; j++)
             cout << arr[i][j] << " ";
        cout<<endl;}

         else for(int i=x-9; i<x+9; i++) {
                     for(int j=y-9; j<y+9; j++)
                             cout << arr[i][j] << " ";
                         cout<<endl;}
    }
    void displayStats(Base *hero)
    {

        cout<<"lol";
    }
    void CreateHero_and_randomMobs(char arr[globalMapX][globalMapY],Base *hero) {

            
            int a=getch();
            cout<<"Choose class:"<<endl;
            cout<<"Hints: 1-war, 2-arch, 3-mage"<<endl;
            if(a==ONE)
            {
                hero->setStrenght(10);
                hero->setAgility(5);
                hero->setStamina(10);
                hero->setEnergy(5);
                hero->setLevel(1);
            }
            if(a==TWO)
            {
                hero->setStrenght(5);
                hero->setAgility(10);
                hero->setStamina(10);
                hero->setEnergy(5);
            }
            if(a==THREE)
            {
                hero->setStrenght(5);
                hero->setAgility(5);
                hero->setStamina(10);
                hero->setEnergy(10);
            }
            hero->SetCoords(3, 3);
            for (int i=0; i<countMob; i++) {
                    int x, y;
                    x=(rand()%199);
                    y=(rand()%199);
                    if(arr[x][y]=='#')
                    {;}
                    else
                    {
                    if(x==0)
                        x++;
                    if(y==0)
                        y++;
                    arr[x][y]='7';
                    }

            }

            for (int i=0; i<countMob; i++) {
                    int x, y;
                    x=(rand()%199);
                    y=(rand()%199);
                    if(arr[x][y]=='#')
                    {;}
                    else
                    {
                    if(x==0)
                        x++;
                    if(y==0)
                        y++;
                    arr[x][y]='8';
                    } 
            }
    }


    Stepcheck STEPCHECK(char T,Base *mob) {
            if (T=='#') return DONTWALK;
            if (T=='.') return WALK;
            if (T=='7') { mob->SetHealPoint(100);mob->setDefence(8); mob->setAttackVal(25);mob->setExperience(50); return FIGHT;}
            if (T=='8') { mob->SetHealPoint(120);mob->setDefence(9); mob->setAttackVal(30);mob->setExperience(100); return FIGHT;}
    }

            
    void createMapFromFile(char arr[globalMapX][globalMapY]) {
      ifstream *rmapfile=new ifstream("MAP.wtf");
      for (int i=0; i<globalMapX; i++) {
        for (int j=0; j<globalMapY; j++) {
          *rmapfile >> arr[i][j]; } 
        }
    }


    

    void All(char arr[globalMapX][globalMapY], Base *hero, Base *mob) {
            //Print(arr);
            int input=0;
            int x=0;
            int y=0;
            int n=0;
            while(input!=ESC && hero->getHealPoint()>0) {
                   x=hero->getXcord();
                   y=hero->getYcord();
                   if(hero->getMaxHealPoint() > hero->getHealPoint())
                       hero->SetHealPoint(hero->getHealPoint()+1);
                    input=getch();
                    //cout<<getch();
                    mob=new Mob();
                    if (input==UP) {
                            switch (STEPCHECK(arr[x-1][y],mob)) {
                                    case DONTWALK: break;
                                    case WALK: hero->SetCoords(x-1, y);
                                                    arr[x-1][y]='1';
                                                    arr[x][y]='.';  break;
                                    case FIGHT:
                                                if(hero->Fight(mob)==1)
                                                {
                                                    hero->setExperience(hero->getExperience()+mob->getExperience());
                                                    hero->SetCoords(x-1, y);
                                                    arr[x-1][y]='1';
                                                    arr[x][y]='.';
                                                    if(hero->getExperience()>=hero->getMaxExperience())
                                                        {hero->levelUp();hero->setLevel(hero->getLevel()+1);hero->setExperience(0); hero->setMaxExperience(hero->getMaxExperience()+200);}
                                                    mob->setExperience(0);
                            
                                                }
                                                else if(hero->Fight(mob)==0)
                                                {
                                                    hero->SetHealPoint(0);
                                                    arr[x][y]='.';
                                                }
                                               // delete mob;
                                                break; } }

                    if (input==DOWN) {
                            switch (STEPCHECK(arr[x+1][y],mob)) {
                                    case DONTWALK: break;
                                    case WALK: hero->SetCoords(x+1, y);
                                                    arr[x+1][y]='1';
                                                    arr[x][y]='.';  break;
                                    case FIGHT: 
                                                if(hero->Fight(mob)==1){
                                                    
                                                    hero->setExperience(hero->getExperience()+mob->getExperience());
                                                    
                                    
                                                    hero->SetCoords(x+1, y);
                                                    arr[x+1][y]='1';
                                                    arr[x][y]='.';
                                                    if(hero->getExperience()>=hero->getMaxExperience())
                                                        {hero->levelUp();hero->setLevel(hero->getLevel()+1);hero->setExperience(0); hero->setMaxExperience(hero->getMaxExperience()+200);}
                                                    mob->setExperience(0);
                                                    
                                                }
                                                else if(hero->Fight(mob)==0)
                                                {
                                                    hero->SetHealPoint(0);
                                                    arr[x][y]='.';
                                                }
                                               // delete mob;
                                                break; } }

                    if (input==LEFT) {
                            switch (STEPCHECK(arr[x][y-1],mob)) {
                                    case DONTWALK: break;
                                    case WALK: hero->SetCoords(x, y-1);
                                                    arr[x][y-1]='1';
                                                    arr[x][y]='.';  break;
                                    case FIGHT: if(hero->Fight(mob)==1){
                                                    hero->setExperience(hero->getExperience()+mob->getExperience());
                                                    hero->SetCoords(x, y-1);
                                                    arr[x][y-1]='1';
                                                    arr[x][y]='.';
                                                    if(hero->getExperience()>=hero->getMaxExperience())
                                                        {hero->levelUp();hero->setLevel(hero->getLevel()+1);hero->setExperience(0); hero->setMaxExperience(hero->getMaxExperience()+200);}
                                                    mob->setExperience(0);
                                                    
                                                }
                                                else if(hero->Fight(mob)==0)
                                                {
                                                    hero->SetHealPoint(0);
                                                    arr[x][y]='.';
                                                }
                                                //delete mob;
                                                break; }  }

                    if (input==RIGHT) {
                            switch (STEPCHECK(arr[x][y+1],mob)) {
                                    case DONTWALK: break;
                                    case WALK: hero->SetCoords(x, y+1);
                                                    arr[x][y+1]='1';
                                                    arr[x][y]='.';  break;
                                    case FIGHT: if(hero->Fight(mob)==1){
                                                    hero->setExperience(hero->getExperience()+mob->getExperience());
                                                    hero->SetCoords(x, y+1);
                                                    arr[x][y+1]='1';
                                                    arr[x][y]='.';
                                                    if(hero->getExperience()>=hero->getMaxExperience())
                                                        {hero->levelUp();hero->setLevel(hero->getLevel()+1);hero->setExperience(0); hero->setMaxExperience(hero->getMaxExperience()+200);}
                                                    mob->setExperience(0);
                                                    
                                                }
                                                else if(hero->Fight(mob)==0)
                                                {
                                                    hero->SetHealPoint(0);
                                                    arr[x][y]='.';
                                                }
                                                //delete mob;
                                                break; }  }

                    out(arr,hero);
                    delete mob;
            }
    }