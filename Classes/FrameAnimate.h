//
//  FrameAnimate.h
//  HelloCpp
//
//  Created by ManYou on 13-10-16.
//
//

#ifndef __HelloCpp__FrameAnimate__
#define __HelloCpp__FrameAnimate__

#include "cocos2d.h"

USING_NS_CC;

class FrameAnimate : public Object
{
public:
    FrameAnimate();
    ~FrameAnimate();
    
    bool init(const char* fileName);
    static FrameAnimate* create(const char* fileName);
    bool init(const char* fileName, float xSpace, float ySpace);
    static FrameAnimate* create(const char* fileName, float xSpace, float ySpace);
    
    SpriteFrame* getSpriteFrame(int x, int y);
    Animation* getAnimation(int x, int y, int count, float delay);
private:
    SpriteBatchNode* m_batchNode;
    float m_xSpace;
    float m_ySpace;
};


#endif /* defined(__HelloCpp__FrameAnimate__) */
