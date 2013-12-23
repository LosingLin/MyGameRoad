//
//  Player.h
//  HelloCpp
//
//  Created by ManYou on 13-11-3.
//
//

#ifndef __HelloCpp__Player__
#define __HelloCpp__Player__

#include "cocos2d.h"

USING_NS_CC;

class Hero;
class Player : public Object
{
public:
    Player();
    ~Player();
    
    bool init();
    CREATE_FUNC(Player);
    
    void addHero(Hero* hero);
    void removeHero(Hero* hero);
    
private:
    int m_moveCount;
    int m_atkCount;
    int m_magicCount;
    int m_defenceCount;
    Array* m_heros;
};

#endif /* defined(__HelloCpp__Player__) */
