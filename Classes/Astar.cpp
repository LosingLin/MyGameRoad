//
//  Astar.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-23.
//
//

#include "Astar.h"
#include "Global.h"

#pragma mark - AstarNode

AstarNode::AstarNode()
: Object()
, m_x(0)
, m_y(0)
, m_f(0)
, m_g(0)
, m_h(0)
, m_father(NULL)
{
    
}

AstarNode::~AstarNode()
{
    
}

bool AstarNode::init()
{
    return true;
}


#pragma mark - Astar

Astar::Astar()
: Object()
, m_delegate(NULL)
, m_closeArr(NULL)
, m_openArr(NULL)
{
    
}

Astar::~Astar()
{
    CC_SAFE_RELEASE_NULL(m_closeArr);
    CC_SAFE_RELEASE_NULL(m_openArr);
}


bool Astar::init()
{
    
    m_closeArr = Array::create();
    m_closeArr->retain();
    
    m_openArr = Array::create();
    m_openArr->retain();
    
    return true;
}

Array* Astar::astar()
{
    Array* paths = Array::create();
    
    //delegate init close array
    m_delegate->AstarInitCloseList(m_closeArr);
    
    //delegate get start node
    auto startNode = m_delegate->AstarStartNode();
    //delegate get end node
    auto endNode = m_delegate->AstarEndNode();
    
    //set the start node in path node
    AstarNode* pathNode = startNode;
    paths->addObject(pathNode);
    while (!isReachEndNode(pathNode))
    {
        m_closeArr->addObject(pathNode);
        
        insertNextNodesToOpenArray(pathNode);
        
        pathNode = findMinExpendInOpenArray();
        paths->addObject(pathNode);
        
        m_openArr->removeAllObjects();
    }
    
    return paths;
}

#pragma mark - 

bool Astar::isReachEndNode(AstarNode* node)
{
    auto endNode = m_delegate->AstarEndNode();
    if (node->getX() == endNode->getX() && node->getY() == endNode->getY())
    {
        return true;
    }
    return false;
}

bool Astar::isInCloseArray(AstarNode* node)
{
    for (int i = 0; i < m_closeArr->count(); ++ i)
    {
        AstarNode* closeNode = dynamic_cast<AstarNode*>(m_closeArr->getObjectAtIndex(i));
        //IGLOG("*****(%d, %d)VS(%d, %d)", closeNode->getX(), closeNode->getY(), node->getX(), node->getY());
        if (closeNode->getX() == node->getX() && closeNode->getY() == node->getY())
        {
            return true;
        }
    }
    return false;
}

AstarNode* Astar::createNode(int x, int y, AstarNode* fatherNode)
{
    auto node = AstarNode::create();
    node->setX(x);
    node->setY(y);
    node->setG(fatherNode->getG() + m_delegate->AstarExpendGInNode(x, y));
    node->setH(m_delegate->AstarExpendHInNode(x, y));
    node->setFather(fatherNode);
    node->setF(node->getG() + node->getH());
    return node;
}

bool Astar::insertNextNodeToOpenArray(int x, int y, AstarNode* fatherNode)
{
    bool flag = false;
    bool isOutMap = m_delegate->AstarIsOutOfMap(x, y);
    if (!isOutMap)
    {
        AstarNode* node = createNode(x, y, fatherNode);
        bool isClosed = isInCloseArray(node);
        if (!isClosed)
        {
            flag = true;
            m_openArr->addObject(node);
        }
        //IGLOG("(%d, %d)->%d: f:%d", x, y, flag, node->getF());
    }
    return flag;
}

bool Astar::insertNextNodesToOpenArray(AstarNode* fatherNode)
{
    bool flag = false;
    int x = fatherNode->getX();
    int y = fatherNode->getY();
    //x+1
    flag = insertNextNodeToOpenArray(x+1, y, fatherNode);
    //x-1
    flag = insertNextNodeToOpenArray(x-1, y, fatherNode);
    //y+1
    flag = insertNextNodeToOpenArray(x, y+1, fatherNode);
    //y-1
    flag = insertNextNodeToOpenArray(x, y-1, fatherNode);
    
    return flag;
}

AstarNode* Astar::findMinExpendInOpenArray()
{
    AstarNode* minENode = NULL;
    auto endNode = m_delegate->AstarEndNode();
    
    for (int i=0; i < m_openArr->count(); ++ i)
    {
        AstarNode* node = dynamic_cast<AstarNode*>(m_openArr->getObjectAtIndex(i));
        //node is not in closeArray
        if (isInCloseArray(node))
        {
            continue;
        }
        if (minENode)
        {
            if (minENode->getF() > node->getF())
            {
                minENode = node;
            }
            //if the node is endnode
            if (node->getX() == endNode->getX() && node->getY() == endNode->getY())
            {
                minENode = node;
            }
        }
        else
        {
            minENode = node;
        }
    }
    return minENode;
}

