//
//  Player.cpp
//  HelloCpp
//
//  Created by ManYou on 13-11-3.
//
//

#include "Player.h"
#include "Hero.h"

Player::Player()
: Object()
, m_moveCount(0)
, m_atkCount(0)
, m_magicCount(0)
, m_defenceCount(0)
, m_heros(NULL)
{
    
}
Player::~Player()
{
    CC_SAFE_RELEASE_NULL(m_heros);
}

bool Player::init()
{
    
    m_heros = Array::create();
    m_heros->retain();
    
    return true;
}

void Player::addHero(Hero* hero)
{
    m_heros->addObject(hero);
}
void Player::removeHero(Hero* hero)
{
    m_heros->removeObject(hero);
}