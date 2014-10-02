//
//  Sheep.cpp
//  Sheep
//
//  Created by Tran Tho on 9/8/14.
//
//

#include "Sheep.h"


Sheep* Sheep::create()
{
    Sheep* _sheep = new Sheep();
    
    if(_sheep && _sheep->initWithSpriteFrameName("1.png"))
    {

        _sheep->runAction(flying());
        
        _sheep->setScale(0.5);
        
        _sheep->directionY = 1;
        
        _sheep->directionX = 1;
        
        _sheep->velocY = 0;
        
        _sheep->setDeltaA(0.3);
        
        _sheep->isActive = false;
        
        _sheep->sheepStaus = isNormal;
        
        _sheep->autorelease();
        
        return _sheep;
    }
    
    CC_SAFE_DELETE(_sheep);
    return nullptr;
}

bool Sheep::isTap(cocos2d::Vec2 pos)
{
    float _distanceX = ((Sheep*)this)->getPositionX() - tapLocation.x;
    float _distanceY = ((Sheep*)this)->getPositionY() - tapLocation.y;
    
    if(_distanceX < 0)
        _distanceX = -_distanceX;
    if(_distanceY < 0)
        _distanceY = -_distanceY;
    
    float _radianX = ((Sheep*)this)->getContentSize().width / 2.0 + 10.0;
    float _radianY = ((Sheep*)this)->getContentSize().height / 2.0 +10.0;
    
    //return (!(powf(_distanceX, 2) + powf(_distanceY, 2) > powf(_radian, 2)));
    return (!(_distanceX > _radianX) && !(_distanceY > _radianY));
}

RepeatForever* Sheep::flying()
{
    Vector<SpriteFrame*> aminFrames;
    for (int i = 0; i < 14; i++)
    {
        
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat("%d.png", i+1)->getCString());
        aminFrames.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(aminFrames, 0.06);
    
    auto animate = Animate::create(animation);
    
    return  RepeatForever::create(animate);
}

RepeatForever* Sheep::rotating()
{
    
    Vector<SpriteFrame*> aminFrames;
    for (int i = 0; i < 3; i++)
    {
        
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat("quat%d.png", i+1)->getCString());
        aminFrames.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(aminFrames, 0.06);
    
    auto animate = Animate::create(animation);
    
    return  RepeatForever::create(animate);

}



