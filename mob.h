typedef unsigned short int suint;

class Mob: public Base
{
protected:        suint healPoints, attack, defence, x, y,strength,agility,energy,stamina,experience;
                double critval,critChance,dodge;
public:
        Mob(){healPoints=100;defence=10;attack=20;critval=0.2;critChance=20;dodge=30;experience=0;}
        suint getHealPoint() { return healPoints;}
        void SetHealPoint(suint _healPoints) { healPoints=_healPoints;}
        suint getAttackVal() { return attack;}
        void setAttackVal(suint _attack) { attack=_attack;}
        suint getDefence() { return defence;}
        void setDefence(suint _defence) { defence=_defence;}

        void SetCoords(suint _x, suint _y) { x=_x; y=_y;}

        suint whatIsIt() { return 2;}

        suint getXcord() { return x;}
        suint getYcord() { return y;}
        suint getCriticalDamage() {return critval;}
        suint getCriticalDamageChance() {return critChance;}
        void setCriticalDamage(suint _critval){critval=_critval;}
        void setCriticalDamageChance(suint _critChance){critChance=_critChance;}
        suint getDodgeChance() {return dodge;}
        void setDodgeChance(suint _dodge){dodge=_dodge;}
        suint Fight(Base*) { return 1;}

        suint getStrenght() {;}
        void setStrenght(suint) {;}
        void setStamina(suint) {;}
        void setAgility(suint) {;}
        void setEnergy(suint) {;}
        suint getStamina() {;}
        suint getEnergy() {;}
        suint getAgility() {;}
        suint getLevel() {;}
        void setLevel(suint) {;}
        suint getExperience() {return experience;}
        void setExperience(suint _exp) {experience=_exp;}
        suint getMaxExperience() {;}
        void setMaxExperience(suint) {;}
        suint getPoints(){;}
        void setPoints(suint){;}
        suint getMaxHealPoint(){;}
        void setMaxHealPoint(suint) {;}
        void getItemName(){;}
        suint getInventoryItem(suint){;}
        void levelUp(){;}
        void changeStats(){;}

};
