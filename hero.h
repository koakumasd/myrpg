class Hero: public Base
{
protected:        
            suint healPoints, maxHealPoints, attack, defence, x, y,heals,strength,agility,energy,stamina,experience,maxExperience,level,points,inventory[maximalItems], objectCount;
            double criticalDamage,criticalChance,dodge;

public: 
        Hero(){  strength=10,agility=10,energy=10,stamina=10,experience=0,maxExperience=50,level=1,points=0; 
                 maxHealPoints=50;healPoints=maxHealPoints;attack=strength; defence=strength*2; x=3; y=3;heals=5;criticalDamage=strength*1.5;
                 criticalChance=agility*0.01;dodge=agility*0.02;
              }


        suint getHealPoint() { return healPoints;}
        void SetHealPoint(suint _healPoints) { healPoints=_healPoints;}
        suint getMaxHealPoint() { return maxHealPoints;}
        void setMaxHealPoint(suint _maxHealPoints) { maxHealPoints=_maxHealPoints;}
        suint getAttackVal() { return attack;}
        void setAttackVal(suint _attack) { attack=_attack;}
        suint getDefence() { return defence;}
        void setDefence(suint _defence) { defence=_defence;}

        void SetCoords(suint _x, suint _y) { x=_x; y=_y;} 

        suint whatIsIt() { return 1;}

        suint getXcord() { return x;}
        suint getYcord() { return y;}
        suint getCriticalDamage() {return criticalDamage;}
        suint getCriticalDamageChance() {return criticalChance;}
        void setCriticalDamage(suint _criticalDamage ){criticalDamage=_criticalDamage;}
        void setCriticalDamageChance(suint _criticalChance){criticalChance=_criticalChance;}
        suint getDodgeChance() {return dodge;}
        void setDodgeChance(suint _dodge){dodge=_dodge;}

        suint getStrenght(){return strength;}
        void setStrenght(suint _strength){strength=_strength;}
        suint getAgility(){return agility;}
        void setAgility(suint _agility){agility=_agility;}
        suint getStamina(){return stamina;}
        void setStamina(suint _stamina){stamina=_stamina;}
        suint getEnergy(){return energy;}
        void setEnergy(suint _energy){energy=_energy;}
        suint getLevel(){return level;}
        void setLevel(suint _level){level=level;}
        suint getExperience(){return experience;}
        void setExperience(suint _experience){experience=_experience;}
        suint getMaxExperience(){return maxExperience;}
        void setMaxExperience(suint _maxExeprience){maxExperience=_maxExeprience;}
        suint getPoints(){return points;}
        void setPoints(suint _points){points=_points;}
        suint getInventoryItem(suint id) {return inventory[id];}
        
        void changeStats()
        {

            int a=0;
            while(this->getPoints()!=0)
            {
                a=getch();
                displayStats(this);
                if(a==ONE) {this->setStrenght(this->getStrenght()+1); this->setPoints(this->getPoints()-1);}
                if(a==TWO) {this->setAgility(this->getAgility()+1); this->setPoints(this->getPoints()-1);}
                if(a==THREE) {this->setStamina(this->getStamina()+1); this->setPoints(this->getPoints()-1);}
                if(a==FOUR) {this->setEnergy(this->getEnergy()+1); this->setPoints(this->getPoints()-1);}
                if(a==ESC) break;
            }
        }
        void levelUp()
        {   
        this->setPoints(5);  
        this->changeStats();  
        this->setMaxHealPoint(this->getStamina()*2);this->setDefence(this->getStrenght()*2); this->setAttackVal(this->getStrenght());this->setCriticalDamageChance(this->getAgility()*0.01);this->setCriticalDamage(this->getStrenght());this->setDodgeChance(this->getAgility()*0.02);
        }
        void addInvenoryItem(suint objectID) { 
            for(int i = 0; i < maximalItems; i++) {
                if(inventory[i] == 0)
                    inventory[i] = objectID;
            }
        }
        void delInvItem(suint objectID) { 
            for(int i = 0; i < maximalItems; i++) {
                if(inventory[i] == objectID)
                    inventory[i] = 0;
            }
        }
        void getItemName() {
            for(int i = 0; i < maximalItems; i++) {
                switch(inventory[i]) {
                    case 0: cout<<"\t-----\n"; break;
                    case 1: cout<<"\tHealth (Restore health)\n"; break;
                    default: cout<<"\t-----\n";
                }
            }
        }

    
        suint Fight(Base *mob)
    {
        int input=0;
        system("clear");
        cout<<"\n"<<"Hero:"<<" LVL:"<<this->getLevel()<<" healPoints:"<<this->getHealPoint()<<"/"<<this->getMaxHealPoint()<<" attack:"<< this->getAttackVal()<<" DEF:"<< this->getDefence()<<" EXP:"<<this->getExperience()<<"/"<<this->getMaxExperience()<<" Heals: "<<this->heals<<endl;
        cout<<"MOB:"<<"healPoints:"<<mob->getHealPoint()<<" attack:"<<mob->getAttackVal()<<" DEF:"<<mob->getDefence()<<endl;
        cout<<"Press 1 to Hit."; cout<<endl;
        cout<<"Press 2 to Heal."; cout<<endl;
        cout<<"Press 3 to Escape.";
            
        input=getch();
        if(input==ONE)//1 - удар
        {
            if(mob->getHealPoint()<=0 || healPoints==0) return 1;
               else if (mob->getHealPoint()<=(this->getAttackVal()- mob->getDefence()))
               {
//                    cout<<"Hero win";
                      mob->SetHealPoint(0);
                      return 1;
               }
               else if (this->getHealPoint()<=(mob->getAttackVal()-this->getDefence()))
               {
//                   cout<<"Mob win";
                     this->SetHealPoint(0);
                     return 0;
               }
               else if(mob->getHealPoint() || healPoints)
               {
                       if((rand()%100)<=mob->getDodgeChance())
                            cout<<"Mob dodge ";
                      else 
                          {if(this->getAttackVal()<mob->getDefence()-mob->getCriticalDamage()){ this->SetHealPoint(0);return 0;}
                                if(mob->getAttackVal()<this->getDefence()){ mob->SetHealPoint(0);return 1;}
                                    mob->SetHealPoint(mob->getHealPoint() - (this->getAttackVal() - mob->getDefence()));

                                if(mob->getHealPoint()>=this->getAttackVal()||mob->getHealPoint()>=this->getAttackVal()+this->getCriticalDamage())//условие, чтобы хп моба не ушло в обратную сторону
                                {
                                    if((rand()%100)<=this->getCriticalDamage())//расчет двойного урона от героя
                                        {cout<<"Hero crit";
                                        mob->SetHealPoint(mob->getHealPoint() - ((this->getAttackVal()+this->getCriticalDamage()) - mob->getDefence()));}
                                }}
                        if((rand()%100)<=this->getDodgeChance())
                            cout<<"Hero dodge ";
                        else 
                          {if(mob->getAttackVal()<this->getDefence()-this->getCriticalDamage()){ this->SetHealPoint(0);return 0;}
                        if(mob->getAttackVal()<this->getDefence()){ mob->SetHealPoint(0);return 1;}
                            this->SetHealPoint(this->getHealPoint() - (mob->getAttackVal() - this->getDefence()));


                            if(mob->getHealPoint()>=this->getAttackVal())//условие, чтобы хп моба не ушло в обратную сторону
                            {
                            if((rand()%100)<=mob->getCriticalDamage())
                                {cout<<"Mob crit ";
                                 this->SetHealPoint(this->getHealPoint() - (mob->getAttackVal()*mob->getCriticalDamage()+mob->getAttackVal() - this->getDefence()));}
                            }}
               }
               
        }
        if(input==TWO)//2 - хил
        {
               if (this->getHealPoint()>=this->getMaxHealPoint()-24) {
                    if(heals>0){
                        this->SetHealPoint(this->getMaxHealPoint()); heals--;}}//услови, чтобы хп не повышалось выше 100
                else
                {   if(heals>0)
                   { this->SetHealPoint(this->getHealPoint()+25);
                                       heals--;}
                }
        }
        if(input==THREE) return 2;
        this->Fight(mob);
    }
    
};