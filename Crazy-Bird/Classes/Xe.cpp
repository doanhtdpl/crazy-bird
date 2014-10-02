//
//  Xe.cpp
//  Sheep
//
//  Created by Tran Tho on 9/27/14.
//
//

#include "Xe.h"

Xe::Xe()
{
    vantoc = 0;
    xe = nullptr;
    chu = nullptr;
}

Xe::Xe(Vector<Node*> list)
{
    vantoc = 0;
    xeStatus = isInit;
    xe = (Sprite*)list.at(0);
    chu = (Label*)list.at(1);
}

bool Xe::isCollsion(cocos2d::Sprite *sprite)
{
    float w = 30;
    
    float scale = 0.5;
    
    float min_X_Pic = sprite->getPositionX() + w;
    float max_X_Pic = min_X_Pic + sprite->getContentSize().width * scale -w;
    float min_Y_Pic = sprite->getPositionY() - w;
    float max_Y_Pic = min_Y_Pic + sprite->getContentSize().height * scale -w;
    
    float min_X_Xe = xe->getPositionX() +w;
    float max_X_Xe = min_X_Xe + xe->getContentSize().width * scale * 0.5 -w;
    float min_Y_Xe = xe->getPositionY() -w;
    float max_Y_Xe = min_Y_Xe + xe->getContentSize().height * scale * 0.5 -w;
    
    return !(max_X_Pic < min_X_Xe||
             max_X_Xe < min_X_Pic||
             max_Y_Xe < min_Y_Pic||
             max_Y_Pic < min_Y_Xe);
}

RepeatForever* Xe::runing()
{
    Vector<SpriteFrame*> aminFrames;
    for (int i = 0; i < 3; i++)
    {
        
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat("xe%d.png", i+1)->getCString());
        aminFrames.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(aminFrames, 0.1);
    
    auto animate = Animate::create(animation);
    
    return  RepeatForever::create(animate);

}