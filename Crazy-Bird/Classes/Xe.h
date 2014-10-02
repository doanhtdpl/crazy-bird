//
//  Xe.h
//  Sheep
//
//  Created by Tran Tho on 9/27/14.
//
//

#ifndef __Sheep__Xe__
#define __Sheep__Xe__

#include "cocos2d.h"

typedef enum
{
    isInit,
    isMove,
    isGoHome,
}XeStatus;

using namespace cocos2d;

class Xe : public Sprite
{
public:
    
    XeStatus xeStatus;
    
    Xe();
    
    CC_SYNTHESIZE(int, _id, _ID);
    
    CC_SYNTHESIZE(float, vantoc, VANTOC);
    
    Xe(Vector<Node*> list);
    
    Sprite* xe;
    Label* chu;
    
    
    bool isCollsion(Sprite* sprite);
    
    static RepeatForever* runing();
    
};

#endif /* defined(__Sheep__Xe__) */
