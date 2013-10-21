//
//  BattleTouch.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef __HelloCpp__BattleTouch__
#define __HelloCpp__BattleTouch__

#include "cocos2d.h"

USING_NS_CC;

class BattleTouchListener;
class BattleTouch : public Layer
{
public:
    BattleTouch();
    ~BattleTouch();
    
    virtual bool init();
    CREATE_FUNC(BattleTouch);
    
    virtual void onEnter();
    virtual void onExit();
    
    void setTouchListener(BattleTouchListener* listener) { m_touchListener = listener; }
    
    //touch
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchMoved(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    virtual void onTouchCancelled(Touch *touch, Event *event);
private:
    BattleTouchListener* m_touchListener; //not own
    float m_beginX;
    float m_beginY;
};

#endif /* defined(__HelloCpp__BattleTouch__) */
