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
#include "BattleMapListener.h"

USING_NS_CC;

enum BattleModel
{
    kBattleModel_Undefine,
    kBattleModel_1V1,
    kBattleModel_2V2,
    kBattleModel_Mix,
};

class BattleTouch;
class BattleMap;
class BattleScene : public Layer
, public BattleMapListener
{
public:
    BattleScene();
    ~BattleScene();
    
    bool init();
    CREATE_FUNC(BattleScene);
private:
    BattleTouch* m_touch;
    BattleMap* m_map;
    BattleModel m_model;
};


#endif /* defined(__HelloCpp__BattleScene__) */
