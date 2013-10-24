//
//  AstarDelegate.h
//  HelloCpp
//
//  Created by ManYou on 13-10-23.
//
//

#ifndef __HelloCpp__AstarDelegate__
#define __HelloCpp__AstarDelegate__

#include "cocos2d.h"

USING_NS_CC;

//support left/right/up/down four direction
//if want to support eight direction, should add...
class AstarNode;
class AstarDelegate
{
public:
    virtual void AstarInitCloseList(Array* arr) = 0;
    virtual AstarNode* AstarStartNode() = 0;
    virtual AstarNode* AstarEndNode() = 0;
    virtual int AstarExpendInNode(AstarNode* node) = 0;
};

#endif /* defined(__HelloCpp__AstarDelegate__) */
