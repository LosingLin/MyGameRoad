//
//  Hero.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-17.
//
//

#include "Hero.h"
#include "Global.h"
#include "FrameAnimate.h"



Hero::Hero()
: Node()
, m_race(kAnimalRace_Undefined)
, m_walkStep(0)
, m_hp(0)
, m_body(NULL)
, m_frameAnimate(NULL)
, c_fileName(NULL)
, c_width(0.0f)
, c_height(0.0f)
{

}
Hero::~Hero()
{
    CC_SAFE_RELEASE_NULL(m_frameAnimate);
    CC_SAFE_RELEASE_NULL(c_fileName);
}

bool Hero::init(const char* fileName, float width, float height)
{
    if (!Node::init())
    {
        return false;
    }
    c_fileName = new String(fileName);
    c_width = width;
    c_height = height;
    
    m_hp = 0;
    m_walkStep = 0;
    m_race = kAnimalRace_Undefined;
    this->setContentSize(Size(width, height));
//    auto color = LayerColor::create(Color4B(80, 80, 80, 255));
//    this->addChild(color);
    m_frameAnimate = FrameAnimate::create(fileName, width, height);
    CC_SAFE_RETAIN(m_frameAnimate);
    m_body = Sprite::createWithSpriteFrame(m_frameAnimate->getSpriteFrame(0, 0));
    m_body->setPosition(Point(width/2, height/2));
    this->addChild(m_body);
    return true;
}

Hero* Hero::create(const char* fileName, float width, float height)
{
    Hero* hero = new Hero;
    if (hero && hero->init(fileName, width, height))
    {
        hero->autorelease();
        return hero;
    }
    CC_SAFE_DELETE(hero);
    return NULL;
}

Hero* Hero::clone()
{
    Hero* hero = Hero::create(c_fileName->getCString(), c_width, c_height);
    return hero;
}

#pragma mark -
//stay
void Hero::stayLeft()
{
    m_body->stopAllActions();
    m_body->setDisplayFrame(m_frameAnimate->getSpriteFrame(0, 1));
}
void Hero::stayRight()
{
    m_body->stopAllActions();
    m_body->setDisplayFrame(m_frameAnimate->getSpriteFrame(0, 2));
}
void Hero::stayUp()
{
    m_body->stopAllActions();
    m_body->setDisplayFrame(m_frameAnimate->getSpriteFrame(0, 3));
}
void Hero::stayDown()
{
    m_body->stopAllActions();
    m_body->setDisplayFrame(m_frameAnimate->getSpriteFrame(0, 0));
}

//walk
void Hero::walkLeft()
{
    m_body->runAction(RepeatForever::create(Animate::create(m_frameAnimate->getAnimation(0, 1, 4, WALKANIMATEDELAY))));
}
void Hero::walkRight()
{
    m_body->runAction(RepeatForever::create(Animate::create(m_frameAnimate->getAnimation(0, 2, 4, WALKANIMATEDELAY))));
}
void Hero::walkUp()
{
    m_body->runAction(RepeatForever::create(Animate::create(m_frameAnimate->getAnimation(0, 3, 4, WALKANIMATEDELAY))));
}
void Hero::walkDown()
{
    m_body->runAction(RepeatForever::create(Animate::create(m_frameAnimate->getAnimation(0, 0, 4, WALKANIMATEDELAY))));
}