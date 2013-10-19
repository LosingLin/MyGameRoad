//
//  BattleMapTile.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef __HelloCpp__BattleMapTile__
#define __HelloCpp__BattleMapTile__

#include "cocos2d.h"

USING_NS_CC;
enum BattleMapTileContent
{
    kTileContent_Undefine,
    kTileContent_Land,
    kTileContent_Grass,
    kTileContent_Tree,
    kTileContent_Hero,
    kTileContent_Stone,
};

class BattleMapTile : public Object
{
public:
    BattleMapTile();
    ~BattleMapTile();
    
    bool init(int x, int y, BattleMapTileContent content);
    static BattleMapTile* create(int x, int y, BattleMapTileContent content);
    
    int getX() { return m_x; }
    int getY() { return m_y; }
    BattleMapTileContent getContent() { return m_content; }
    void setContent(BattleMapTileContent content) { m_content = content; }
private:
    int m_x;
    int m_y;
    BattleMapTileContent m_content;
};

#endif /* defined(__HelloCpp__BattleMapTile__) */
