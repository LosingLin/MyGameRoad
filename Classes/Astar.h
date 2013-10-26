//
//  Astar.h
//  HelloCpp
//
//  Created by ManYou on 13-10-23.
//
//

#ifndef __HelloCpp__Astar__
#define __HelloCpp__Astar__

#include "cocos2d.h"
#include "AstarDelegate.h"

USING_NS_CC;

class AstarNode : public Object
{
public:
    AstarNode();
    ~AstarNode();
    
    bool init();
    CREATE_FUNC(AstarNode);
    
    int getX() { return m_x; }
    void setX(int x) { m_x = x; }
    
    int getY() { return m_y; }
    void setY(int y) { m_y = y; }
    
    int getF() { return m_f; }
    void setF(int f) { m_f = f; }
    
    int getG() { return m_g; }
    void setG(int g) { m_g = g; }
    
    int getH() { return m_h; }
    void setH(int h) { m_h = h; }
    
    AstarNode* getFather() { return m_father; }
    void setFather(AstarNode* father) { m_father = father; }
    
private:
    int m_x;
    int m_y;
    int m_f;
    int m_g;
    int m_h;
    AstarNode* m_father; //not own
};

class Astar : public Object
{
public:
    Astar();
    ~Astar();
    
    bool init();
    CREATE_FUNC(Astar);
    
    void setDelegate(AstarDelegate* delegate) { m_delegate = delegate; }
    
    Array* astar();
private:
    bool isReachEndNode(AstarNode* node);
    bool isInCloseArray(AstarNode* node);
    bool insertNextNodeToOpenArray(int x, int y, AstarNode* fatherNode);
    bool insertNextNodesToOpenArray(AstarNode* fatherNode);
    AstarNode* createNode(int x, int y, AstarNode* fatherNode);
    AstarNode* findMinExpendInOpenArray();
private:
    AstarDelegate* m_delegate;
    
    Array* m_closeArr;
    Array* m_openArr;
};

#endif /* defined(__HelloCpp__Astar__) */
