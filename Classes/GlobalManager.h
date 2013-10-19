//
//  GlobalManager.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef __HelloCpp__GlobalManager__
#define __HelloCpp__GlobalManager__

#include "cocos2d.h"

USING_NS_CC;

class GlobalManager : public Object
{
public:
    ~GlobalManager();
    
    static GlobalManager* shareInstance();
    static void purgeInstance();
    
    int getMapWidth() { return G_MapWidth; }
    int getMapHeight() { return G_MapHeight; }
    float getMapTileWidth() { return G_MapTileWidth; }
    float getMapTileHeight() { return G_MapTileHeight; }
    
private:
    bool init();
    
    GlobalManager();
    
private:
    static GlobalManager* m_instance;
    
    int G_MapWidth;
    int G_MapHeight;
    float G_MapTileWidth;
    float G_MapTileHeight;
};


#endif /* defined(__HelloCpp__GlobalManager__) */
