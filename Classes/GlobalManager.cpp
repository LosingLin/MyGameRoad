//
//  GlobalManager.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#include "GlobalManager.h"


GlobalManager* GlobalManager::m_instance = NULL;

GlobalManager::GlobalManager()
: Object()
, G_MapWidth(0)
, G_MapHeight(0)
, G_MapTileWidth(0.0f)
, G_MapTileHeight(0.0f)
{
    
}
GlobalManager::~GlobalManager()
{
    
}

GlobalManager* GlobalManager::shareInstance()
{
    if (!m_instance)
    {
        m_instance = new GlobalManager;
        m_instance->init();
    }
    
    return m_instance;
}
void GlobalManager::purgeInstance()
{
    if (m_instance)
    {
        delete m_instance;
        m_instance = NULL;
    }
}

bool GlobalManager::init()
{
    G_MapWidth = 15;
    G_MapHeight = 9;
    G_MapTileWidth = 64.0f;
    G_MapTileHeight = 64.0f;
    
    return true;
}