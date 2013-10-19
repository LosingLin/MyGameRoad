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
    
    //setter&&getter
    void setHp(int hp) { m_hp = hp; }
    int getHp(int hp) { return m_hp; }
    
    void setWalkStep(int step) { m_walkStep = step; }
    int getWalkStep() { return m_walkStep; }
    
    void setAnimalRace(AnimalRace race) { m_race = race; }
    AnimalRace getAnimalRace() { return m_race; }
protected:
    //clone
    String* c_fileName;
    float c_width;
    float c_height;
    
private:
    int m_hp;           //生命值
    int m_walkStep;     //步长
    AnimalRace m_race;  //种族
    Sprite* m_body;     //身体
    FrameAnimate* m_frameAnimate; //帧动画
    
};

#endif /* defined(__HelloCpp__Hero__) */
