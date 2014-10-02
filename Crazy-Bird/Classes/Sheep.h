//
//  Sheep.h
//  Sheep
//
//  Created by Tran Tho on 9/8/14.
//
//

#ifndef __Sheep__Sheep__
#define __Sheep__Sheep__

#include "cocos2d.h"
#include "Data.h"

using namespace cocos2d;

typedef enum
{
    isNormal,
    isTap,
    isHit,
}SheepStatus;

class Sheep : public Sprite
{
public:
    
    CC_SYNTHESIZE(int, _id, _ID);
    
    CC_SYNTHESIZE(Vec2, tapLocation, TapLocation);
    
    CC_SYNTHESIZE(float, deltaA, DeltaA);
    
    static Sheep* create();
    
    SheepStatus sheepStaus;
    
    bool isTap(Vec2 pos);
    
    int directionY;
    
    float velocY;
    
    int directionX;
    
    
    bool isActive;
    
private:
    
    static RepeatForever* flying();
    
    static RepeatForever* rotating();
    
};




#endif /* defined(__Sheep__Sheep__) */
