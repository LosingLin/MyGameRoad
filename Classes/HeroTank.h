//
//  HeroTank.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef __HelloCpp__HeroTank__
#define __HelloCpp__HeroTank__

#include "Hero.h"

USING_NS_CC;

class HeroTank : public Hero
{
public:
    HeroTank();
    ~HeroTank();
    
    virtual Hero* clone();
    
    virtual bool init(const char* fileName, float width, float height);
    static HeroTank* create(const char* fileName, float width, float height);
private:
    
};

#endif /* defined(__HelloCpp__HeroTank__) */
