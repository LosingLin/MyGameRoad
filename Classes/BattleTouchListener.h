//
//  BattleTouchListener.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef HelloCpp_BattleTouchListener_h
#define HelloCpp_BattleTouchListener_h

class BattleTouchListener
{
public:
    virtual void BattleTouchEndHappend(float x, float y)=0;
    virtual void BattleTouchBeginHappend(float x, float y)=0;
};

#endif
