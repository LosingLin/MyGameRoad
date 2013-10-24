//
//  BattleMap.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#include "BattleMap.h"
#include "Global.h"
#include "HeroFactory.h"


BattleMap::BattleMap()
: Layer()
, m_mapXSize(0)
, m_mapYSize(0)
, m_tileWidth(0.0f)
, m_tileHeight(0.0f)
, m_content(NULL)
, m_status(kBattleStatus_Undefine)
{

}
BattleMap::~BattleMap()
{
    if (m_content)
    {
        delete m_content;
        m_content = NULL;
    }
    
    CC_SAFE_RELEASE_NULL(m_content);
}

bool BattleMap::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();
    
    auto map = TMXTiledMap::create("defaultLand.tmx");
    map->setPosition(Point((winSize.width-960)/2, 0));
    this->addChild(map, -1);
    
    initMapInfo();
    
    return true;
}

void BattleMap::initMapInfo()
{
    m_mapXSize = 15;
    m_mapYSize = 9;
    m_tileWidth = 64.0f;
    m_tileHeight = 64.0f;
    
    m_content = Array::create();
    m_content->retain();
    for (int i = 0; i < m_mapXSize; ++ i)
    {
        for (int j = 0; j < m_mapYSize; ++ j)
        {
            auto tile = BattleMapTile::create(i, j, kTileContent_Land);
            m_content->addObject(tile);
        }
    }
}

#pragma mark - BattleTouchListener

void BattleMap::BattleTouchEndHappend(float x, float y)
{
    Point mapPos = convertToMapPosition(Point(x, y));
    IGLOG("mapPos (%f, %f)", mapPos.x, mapPos.y);
    if (!IsPointInsideOfMap(mapPos))
    {
        IGLOG("IG_INFO: touch outof map!");
        return;
    }
    Point worldPos = convertToWorldPosition(mapPos);

    BattleMapTile* tile = getMapTile(mapPos.x, mapPos.y);
    if (tile->getContent() == kTileContent_Hero)
    {
        IGLOG("IG_INFO: hero is standing the place");
        auto hero = dynamic_cast<Hero*>(tile->getNode());
        IGLOG("IG_INFO: hero's hp is %d", hero->getHp());
        
        m_status = kBattleStatus_HeroSelect;
        
        return;
    }
    
    if (!m_status == kBattleStatus_HeroSelect)
    {
        auto hero = HeroFactory::shareInstance()->createHero("Tank");
        hero->setAnchorPoint(Point(0.5f, 0.0f));
        hero->setPosition(Point(worldPos.x + m_tileWidth / 2, worldPos.y + 10));
        hero->setZOrder(m_mapYSize-mapPos.y);
        this->addChild(hero);
        hero->walkDown();
        tile->setContent(kTileContent_Hero);
        tile->setNode(hero);
        
        m_status = kBattleStatus_HeroReady;
    }
    else
    {
        //处理行走的
        m_status = kBattleStatus_HeroWalking;
        
    }
    
}

void BattleMap::BattleTouchBeginHappend(float x, float y)
{
    
}

#pragma mark - Astar Delegate

void BattleMap::AstarInitCloseList(Array* arr)
{
    
}

#pragma mark - util
Point BattleMap::convertToMapPosition(const Point& pos)
{
    Size winSize = Director::getInstance()->getWinSize();
    float xSpace = (winSize.width - RESOLUTIONSIZE_WIDTH) / 2;
    int x = (int)((pos.x - xSpace)/m_tileWidth);
    int y = (int)(pos.y/m_tileHeight);
    return Point(x, y);
}
Point BattleMap::convertToWorldPosition(const Point& pos)
{
    Size winSize = Director::getInstance()->getWinSize();
    float xSpace = (winSize.width - RESOLUTIONSIZE_WIDTH) / 2;
    float x = pos.x * m_tileWidth + xSpace;
    float y = pos.y * m_tileHeight;
    return Point(x, y);
}
bool BattleMap::IsPointInsideOfMap(const Point& pos)
{
    if (pos.x>=0 && pos.x<m_mapXSize && pos.y>=0 && pos.y<m_mapYSize)
    {
        return true;
    }
    return false;
}

BattleMapTile* BattleMap::getMapTile(int x, int y)
{
    int index = x * m_mapYSize + y;
    BattleMapTile* tile = dynamic_cast<BattleMapTile*>(m_content->getObjectAtIndex(index));
    CCASSERT(tile, "tile can't be null");
    CCASSERT(tile->getX() == x && tile->getY() == y, "get error tile");
    return tile;
//    for (int i = 0; i < m_content->count(); ++ i)
//    {
//        BattleMapTile* tile = dynamic_cast<BattleMapTile*>(m_content->getObjectAtIndex(i));
//        if (tile->getX() == x && tile->getY() == y)
//        {
//            return tile;
//        }
//    }
//    
//    return NULL;
}