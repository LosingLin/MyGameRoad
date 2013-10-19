//
//  HeroTank.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#include "HeroTank.h"

HeroTank::HeroTank()
: Hero()
{
    
}
HeroTank::~HeroTank()
{
    
}
bool HeroTank::init(const char* fileName, float width, float height)
{
    if (!Hero::init(fileName, width, height))
    {
        return false;
    }
    
    setHp(10);
    setWalkStep(2);
    setAnimalRace(kAnimalRace_Tank);
    
    return true;
}

HeroTank* HeroTank::create(const char* fileName, float width, float height)
{
    HeroTank *tank = new HeroTank();
    if (tank && tank->init(fileName, width, height))
    {
        tank->autorelease();
        return tank;
    }
    CC_SAFE_DELETE(tank);
    return NULL;
}

Hero* HeroTank::clone()
{
    HeroTank* tank = HeroTank::create(c_fileName->getCString(), c_width, c_height);
    return tank;
}