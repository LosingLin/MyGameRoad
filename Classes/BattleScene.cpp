//
//  BattleScene.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-15.
//
//

#include "BattleScene.h"
#include "BattleTouch.h"
#include "BattleMap.h"
#include "FrameAnimate.h"
#include "HeroFactory.h"

BattleScene::BattleScene()
: Layer()
, m_touch(NULL)
, m_map(NULL)
{
    
}
BattleScene::~BattleScene()
{

}

bool BattleScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    m_map = BattleMap::create();
    m_map->setListener(this);
    this->addChild(m_map);
    
    m_touch = BattleTouch::create();
    m_touch->setTouchListener(m_map);
    this->addChild(m_touch);
    
//    auto frameAnimate = FrameAnimate::create("xpchar2.png", 64.0f, 96.0f);
//    auto sp = Sprite::createWithSpriteFrame(frameAnimate->getSpriteFrame(0, 1));
//    sp->setPosition(Point(winSize.width / 2, winSize.height / 2));
//    this->addChild(sp);
//    sp->runAction(RepeatForever::create(Animate::create(frameAnimate->getAnimation(0, 0, 4, 12.0f/60.0f))));
//    
//    auto leftSp = Sprite::create();
//    leftSp->setPosition(Point(winSize.width / 2 - 64.0f, winSize.height / 2));
//    this->addChild(leftSp);
//    leftSp->runAction(RepeatForever::create(Animate::create(frameAnimate->getAnimation(0, 1, 4, 12.0f/60.0f))));
//    
//    auto rightSp = Sprite::create();
//    rightSp->setPosition(Point(winSize.width / 2 + 64.0f, winSize.height / 2));
//    this->addChild(rightSp);
//    rightSp->runAction(RepeatForever::create(Animate::create(frameAnimate->getAnimation(0, 2, 4, 12.0f/60.0f))));
//    
//    auto upSp = Sprite::create();
//    upSp->setPosition(Point(winSize.width / 2, winSize.height / 2 + 96.0f));
//    this->addChild(upSp);
//    upSp->runAction(RepeatForever::create(Animate::create(frameAnimate->getAnimation(0, 3, 4, 12.0f/60.0f))));
//    
//    auto hero = HeroFactory::shareInstance()->createHero("Tank");
//    hero->setPosition(winSize.width / 2, winSize.height / 2 - 96.0f);
//    this->addChild(hero);
//    hero->walkLeft();
    return true;
}