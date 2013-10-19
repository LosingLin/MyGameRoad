//
//  BattleTouch.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#include "BattleTouch.h"
#include "BattleTouchListener.h"


BattleTouch::BattleTouch()
: Layer()
, m_touchListener(NULL)
{

}
BattleTouch::~BattleTouch()
{
    
}

bool BattleTouch::init()
{
    if (!Layer::init())
    {
        return false;
    }
//    auto color = LayerColor::create(Color4B(100, 100, 100, 255));
//    this->addChild(color);
    this->setTouchEnabled(true);
    this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    this->setSwallowsTouches(true);
    
    return true;
}

void BattleTouch::onEnter()
{
    Layer::onEnter();
    log("onEnter");
    
}
void BattleTouch::onExit()
{
    Layer::onExit();
}


//touch
bool BattleTouch::onTouchBegan(Touch *touch, Event *event)
{
    log("IG_INFO: touchBegan(%f, %f).", touch->getLocation().x, touch->getLocation().y);
    
    if (m_touchListener)
    {
        m_touchListener->BattleTouchBeginHappend(touch->getLocation().x, touch->getLocation().y);
    }
    
    return true;
}
void BattleTouch::onTouchMoved(Touch *touch, Event *event)
{

}
void BattleTouch::onTouchEnded(Touch *touch, Event *event)
{
    log("IG_INFO: onTouchEnded(%f, %f).", touch->getLocation().x, touch->getLocation().y);
    
    if (m_touchListener)
    {
        m_touchListener->BattleTouchEndHappend(touch->getLocation().x, touch->getLocation().y);
    }
}
void BattleTouch::onTouchCancelled(Touch *touch, Event *event)
{
    
}