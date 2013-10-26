//
//  Hero.h
//  HelloCpp
//
//  Created by ManYou on 13-10-17.
//
//

#ifndef __HelloCpp__Hero__
#define __HelloCpp__Hero__

#include "cocos2d.h"
#include "Animal.h"

USING_NS_CC;

enum HeroStatus
{
    kHeroStatus_Undefine,
    kHeroStatus_StayLeft,
    kHeroStatus_StayRight,
    kHeroStatus_StayUp,
    kHeroStatus_StayDown,
    kHeroStatus_WalkLeft,
    kHeroStatus_WalkRight,
    kHeroStatus_WalkUp,
    kHeroStatus_WalkDown,
};

class FrameAnimate;
class Hero : public Node,
public Animal
{
public:
    Hero();
    ~Hero();
    
    virtual bool init(const char* fileName, float width, float height);
    static Hero* create(const char* fileName, float width, float height);
    
    virtual Hero* clone();
    
    //stay
    virtual void stayLeft();
    virtual void stayRight();
    virtual void stayUp();
    virtual void stayDown();
    
    //walk
    virtual void walkLeft();
    virtual void walkRight();
    virtual void walkUp();
    virtual void walkDown();
    
    void walkDone();
    
    //setter&&getter
    void setHp(int hp) { m_hp = hp; }
    int getHp() { return m_hp; }
    
    void setWalkStep(int step) { m_walkStep = step; }
    int getWalkStep() { return m_walkStep; }
    
    void setWalkSpeed(int speed) { m_walkSpeed = speed; }
    int getWalkSpeed() { return m_walkSpeed; }
    
    void setAnimalRace(AnimalRace race) { m_race = race; }
    AnimalRace getAnimalRace() { return m_race; }
    
    HeroStatus getStatus() { return m_status; }
    
protected:
    //clone
    String* c_fileName;
    float c_width;
    float c_height;
    
private:
    int m_hp;           //生命值
    int m_walkStep;     //步长
    int m_walkSpeed;    //移动速度
    AnimalRace m_race;  //种族
    Sprite* m_body;     //身体
    FrameAnimate* m_frameAnimate; //帧动画
    HeroStatus m_status;
};

#endif /* defined(__HelloCpp__Hero__) */
