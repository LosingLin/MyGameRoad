//
//  FrameAnimate.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-16.
//
//

#include "FrameAnimate.h"


FrameAnimate::FrameAnimate()
: Object()
, m_batchNode(NULL)
, m_xSpace(0.0f)
, m_ySpace(0.0f)
{
}
FrameAnimate::~FrameAnimate()
{
    CC_SAFE_RELEASE_NULL(m_batchNode);
}

bool FrameAnimate::init(const char* fileName)
{
    m_batchNode = SpriteBatchNode::create(fileName);
    m_batchNode->retain();
    
    return true;
}

FrameAnimate* FrameAnimate::create(const char* fileName)
{
    FrameAnimate* animate = new FrameAnimate;
    if (animate && animate->init(fileName))
    {
        animate->autorelease();
        return animate;
    }
    CC_SAFE_DELETE(animate);
    return NULL;
}

bool FrameAnimate::init(const char* fileName, float xSpace, float ySpace)
{
    if (!this->init(fileName))
    {
        return false;
    }
    m_xSpace = xSpace;
    m_ySpace = ySpace;
    
    return true;
}
FrameAnimate* FrameAnimate::create(const char* fileName, float xSpace, float ySpace)
{
    FrameAnimate* animate = new FrameAnimate;
    if (animate && animate->init(fileName, xSpace, ySpace))
    {
        animate->autorelease();
        return animate;
    }
    CC_SAFE_DELETE(animate);
    return NULL;
}

SpriteFrame* FrameAnimate::getSpriteFrame(int x, int y)
{
    Texture2D* allTexture = m_batchNode->getTexture();
    auto *frame = SpriteFrame::createWithTexture(allTexture, Rect(x * m_xSpace, y * m_ySpace, m_xSpace, m_ySpace));
    return frame;
}

Animation* FrameAnimate::getAnimation(int x, int y, int count, float delay)
{
    auto array = Array::create();
    for (int i=0; i < count; i++)
    {
        array->addObject(getSpriteFrame(x+i, y));
    }
    auto animation = Animation::createWithSpriteFrames(array, delay);
    return animation;
}