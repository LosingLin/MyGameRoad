//
//  GlobalDefine.h
//  HelloCpp
//
//  Created by ManYou on 13-10-19.
//
//

#ifndef HelloCpp_GlobalDefine_h
#define HelloCpp_GlobalDefine_h

#define IGDEBUG 1

//定义调试BUG
#if IGDEBUG == 1
#define IGLOG(format, ...)      cocos2d::log(format, ##__VA_ARGS__)
#else
#define IGLOG(...)
#endif


#define RESOLUTIONSIZE_WIDTH 960.0f
#define RESOLUTIONSIZE_HEIGHT 640.0f
#define WALKANIMATEDELAY 10.0f/60.0f

#endif
