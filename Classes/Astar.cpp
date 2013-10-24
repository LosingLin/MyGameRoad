//
//  Astar.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-23.
//
//

#include "Astar.h"

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

void Astar::astar()
{
    //delegate init close array
    m_delegate->AstarInitCloseList(m_closeArr);
    
    //delegate get start node
    auto startNode = m_delegate->AstarStartNode();
    //delegate get end node
    auto endNode = m_delegate->AstarEndNode();
    
    //set the start node in path node
    AstarNode* pathNode = startNode;
    while (!isReachEndNode(pathNode))
    {
        m_closeArr->addObject(pathNode);
        
        
    }
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
        if (closeNode->getX() == node->getX() && closeNode->getY() == node->getY())
        {
            return true;
        }
    }
    return false;
}

