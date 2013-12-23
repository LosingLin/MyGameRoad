//
//  BattleTouch.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#include "BattleTouch.h"
#include "Global.h"
#include "BattleTouchListener.h"


BattleTouch::BattleTouch()
: Layer()
, m_touchListener(NULL)
, m_beginX(0.0f)
, m_beginY(0.0f)
, m_enable(false)
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
    
    this->setMapTouchEnable(true);
    
    return true;
}

void BattleTouch::onEnter()
{
    Layer::onEnter();
}
void BattleTouch::onExit()
{
    Layer::onExit();
}

void BattleTouch::setMapTouchEnable(bool enable)
{
    if (m_enable != enable)
    {
        this->setTouchEnabled(m_enable);
        if (m_enable)
        {
            this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
            this->setSwallowsTouches(m_enable);
        }
    }
}


//touch
bool BattleTouch::onTouchBegan(Touch *touch, Event *event)
{
    IGLOG("IG_INFO: touchBegan(%f, %f).", touch->getLocation().x, touch->getLocation().y);
    
    m_beginX = touch->getLocation().x;
    m_beginY = touch->getLocation().y;
    
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
    IGLOG("IG_INFO: onTouchEnded(%f, %f).", touch->getLocation().x, touch->getLocation().y);
    
    if (touch->getLocation().x >= m_beginX - 10 && touch->getLocation().x <= m_beginX + 10 &&
        touch->getLocation().y >= m_beginY - 10 && touch->getLocation().y <= m_beginY + 10)
    {
        if (m_touchListener)
        {
            m_touchListener->BattleTouchEndHappend(touch->getLocation().x, touch->getLocation().y);
        }
    }
    else
    {
        IGLOG("IG_INFO: touch end is diff with begin!");
    }
}
void BattleTouch::onTouchCancelled(Touch *touch, Event *event)
{
    
}