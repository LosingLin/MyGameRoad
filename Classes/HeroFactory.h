//
//  HeroFactory.h
//  HelloCpp
//
//  Created by ManYou on 13-10-18.
//
//

#ifndef __HelloCpp__HeroFactory__
#define __HelloCpp__HeroFactory__

#include "cocos2d.h"
#include "Hero.h"

USING_NS_CC;
class HeroFactory : public Object
{
public:
    ~HeroFactory();
    static HeroFactory* shareInstance();
    static void purgeInstance();
    void registerHero(const char* key, Hero* hero);
    void removeHero(const char* key);
    Hero* createHero(const char* key);
private:
    HeroFactory();
private:
    static HeroFactory* m_instance;
    Dictionary* m_dic;
};

#endif /* defined(__HelloCpp__HeroFactory__) */
