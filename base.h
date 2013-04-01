
class Base
{
protected:

public:
    virtual suint getHealPoint()=0;    // :O
    virtual void SetHealPoint(suint)=0;
    virtual suint getAttackVal()=0;
    virtual void setAttackVal(suint)=0;
    virtual suint getDefence()=0;
    virtual void setDefence(suint)=0;

    virtual void SetCoords(suint, suint)=0;

    virtual suint whatIsIt()=0;

    virtual suint getXcord()=0;
    virtual suint getYcord()=0;
    virtual suint getCriticalDamage()=0;
    virtual suint getCriticalDamageChance()=0;
    virtual void setCriticalDamage(suint)=0;
    virtual void setCriticalDamageChance(suint)=0;
    virtual suint getDodgeChance()=0;
    virtual void setDodgeChance(suint)=0;
    virtual suint Fight(Base*)=0;

    virtual suint getStrenght()=0;
    virtual void setStrenght(suint)=0;
    virtual suint getAgility()=0;
    virtual void setAgility(suint)=0;
    virtual suint getStamina()=0;
    virtual void setStamina(suint)=0;
    virtual suint getEnergy()=0;
    virtual void setEnergy(suint)=0;
    virtual suint getLevel()=0;
    virtual void setLevel(suint)=0;
    virtual suint getExperience()=0;
    virtual void setExperience(suint)=0;
    virtual suint getMaxExperience()=0;
    virtual void setMaxExperience(suint)=0;
    virtual suint getPoints()=0;
    virtual void setPoints(suint)=0;
    virtual suint getMaxHealPoint()=0;
    virtual void setMaxHealPoint(suint)=0;
    virtual void getItemName()=0;
    virtual suint  getInventoryItem(suint)=0;
    virtual void levelUp()=0;
    virtual void changeStats()=0;
};
