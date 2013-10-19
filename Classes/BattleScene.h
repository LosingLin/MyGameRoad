//
//  BattleScene.h
//  HelloCpp
//
//  Created by ManYou on 13-10-15.
//
//

#ifndef __HelloCpp__BattleScene__
#define __HelloCpp__BattleScene__

#include "cocos2d.h"

USING_NS_CC;
class BattleTouch;
class BattleMap;
class BattleScene : public Layer
{
public:
    BattleScene();
    ~BattleScene();
    
    bool init();
    CREATE_FUNC(BattleScene);
private:
    BattleTouch* m_touch;
    BattleMap* m_map;
};


#endif /* defined(__HelloCpp__BattleScene__) */
