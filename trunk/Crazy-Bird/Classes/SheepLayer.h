//
//  SheepLayer.h
//  Sheep
//
//  Created by Tran Tho on 9/8/14.
//
//

#ifndef __Sheep__SheepLayer__
#define __Sheep__SheepLayer__

#include "cocos2d.h"
#include "Sheep.h"
#include "Xe.h"

using namespace cocos2d;

class SheepLayer : public Layer
{
public:
    
    virtual bool init() override;
    
    virtual void update(float dt) override;
    
    virtual void onEnter() override;
    
    virtual void onExit() override;
    
    Vector<Sheep*>* listSheep;
    
    

    
    CREATE_FUNC(SheepLayer);
    
    void getTapAction(Vec2 pos);
    
private:
    
    Label* lbScore;
    
    int score;
    
    void updateScore();
    
    int type;
    
    int count;
    
    void addSheep();
    
        
    void actionSheep();
    
    void cleanUp();
    
    Size _size;
};




#endif /* defined(__Sheep__SheepLayer__) */
