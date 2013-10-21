//
//  BattleMapTile.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#include "BattleMapTile.h"


BattleMapTile::BattleMapTile()
: Object()
, m_x(0)
, m_y(0)
, m_content(kTileContent_Undefine)
, m_node(NULL)
{
    
}
BattleMapTile::~BattleMapTile()
{
    
}

bool BattleMapTile::init(int x, int y, BattleMapTileContent content)
{
    m_x = x;
    m_y = y;
    m_content = content;
    return true;
}
BattleMapTile* BattleMapTile::create(int x, int y, BattleMapTileContent content)
{
    BattleMapTile *tile = new BattleMapTile;
    if (tile && tile->init(x, y, content))
    {
        tile->autorelease();
        return tile;
    }
    CC_SAFE_DELETE(tile);
    return NULL;
}
