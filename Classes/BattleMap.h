//
//  BattleMap.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef __HelloCpp__BattleMap__
#define __HelloCpp__BattleMap__

#include "cocos2d.h"
#include "BattleTouchListener.h"
#include "Astar.h"
#include "BattleMapTile.h"
#include "BattleMapStatus.h"

USING_NS_CC;

class Hero;
class BattleMapListener;
class BattleMap : public Layer
, public BattleTouchListener
, public AstarDelegate
{
public:
    BattleMap();
    ~BattleMap();
    
    virtual bool init();
    CREATE_FUNC(BattleMap);
    
    //# BattleTouchListener
    virtual void BattleTouchEndHappend(float x, float y);
    virtual void BattleTouchBeginHappend(float x, float y);
    
    //# Astar Delegate
    virtual void AstarInitCloseList(Array* arr);
    virtual AstarNode* AstarStartNode();
    virtual AstarNode* AstarEndNode();
    virtual int AstarExpendGInNode(int x, int y);
    virtual int AstarExpendHInNode(int x, int y);
    virtual bool AstarIsOutOfMap(int x, int y);
    
    void setListener(BattleMapListener* listener) { m_listener=listener; }
    
private:
    void initMapInfo();
    
    BattleMapTile* getMapTile(int x, int y);
    void setMapTileContent(int x, int y, BattleMapTileContent content, Node* node=NULL);
    
    Point convertToMapPosition(const Point& pos);
    Point convertToWorldPosition(const Point& pos);
    
    bool IsPointInsideOfMap(const Point& pos);
    
    void HeroMove(Array* path);
    void HeroMoveDone();
    void HeroMoveBefore(Object* start);
    void HeroMoveAfter(Object* end);
    
    
    void setStatus(BattleMapStatus status);
private:
    //map info
    int m_mapXSize;
    int m_mapYSize;
    float m_tileWidth;
    float m_tileHeight;
    Array* m_content;
    
    BattleMapStatus m_status;
    
    //Astar
    Point m_AstarStart;
    Point m_AstarEnd;
    
    Hero* m_currentHero;
    BattleMapListener *m_listener;
};

#endif /* defined(__HelloCpp__BattleMap__) */
