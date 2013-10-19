//
//  Animal.h
//  HelloCpp
//
//  Created by ManYou on 13-10-17.
//
//

#ifndef __HelloCpp__Animal__
#define __HelloCpp__Animal__

#include "cocos2d.h"

USING_NS_CC;

enum AnimalRace
{
    kAnimalRace_Undefined,
    kAnimalRace_Tank,
    kAnimalRace_Mage,
    kAnimalRace_Archer,
};

class Animal
{
public:
    //stay
    virtual void stayLeft()=0;
    virtual void stayRight()=0;
    virtual void stayUp()=0;
    virtual void stayDown()=0;
    
    //walk
    virtual void walkLeft()=0;
    virtual void walkRight()=0;
    virtual void walkUp()=0;
    virtual void walkDown()=0;
};


#endif /* defined(__HelloCpp__Animal__) */
