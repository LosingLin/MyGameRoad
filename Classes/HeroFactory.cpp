//
//  HeroFactory.cpp
//  HelloCpp
//
//  Created by ManYou on 13-10-18.
//
//

#include "HeroFactory.h"
#include "Global.h"
#include "HeroTank.h"


HeroFactory* HeroFactory::m_instance = NULL;

HeroFactory::HeroFactory()
: Object()
, m_dic(NULL)
{
    
}
HeroFactory::~HeroFactory()
{
    CC_SAFE_RELEASE_NULL(m_dic);
}

HeroFactory* HeroFactory::shareInstance()
{
    if (!m_instance)
    {
        m_instance = new HeroFactory;
        
        m_instance->registerHero("Tank", HeroTank::create("xpchar2.png", 64.0f, 96.0f));
    }
    
    return m_instance;
}
void HeroFactory::purgeInstance()
{
    if (m_instance)
    {
        delete m_instance;
        m_instance = NULL;
    }
}


void HeroFactory::registerHero(const char* key, Hero* hero)
{
    if (!m_dic)
    {
        m_dic = Dictionary::create();
        m_dic->retain();
    }
    
    if (!m_dic->objectForKey(key))
    {
        m_dic->setObject(hero, key);
    }
    else
    {
        IGLOG("IG_INFO: key is existed!");
    }
}
void HeroFactory::removeHero(const char* key)
{
    if (m_dic->objectForKey(key))
    {
        m_dic->removeObjectForKey(key);
    }
    else
    {
        IGLOG("IG_INFO: key is not exist!");
    }
}

Hero* HeroFactory::createHero(const char* key)
{
    CCASSERT(m_dic->objectForKey(key), "IG_ERROR: key is not exist!");
    
    //addchild may add the same hero, so need clone the other hero
    Hero* hero = dynamic_cast<Hero*>(m_dic->objectForKey(key))->clone();
    
    return hero;
}