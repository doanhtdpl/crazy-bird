//
//  SheepLayer.cpp
//  Sheep
//
//  Created by Tran Tho on 9/8/14.
//
//

#include "SheepLayer.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "config.h"
#include "Data.h"

bool SheepLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    
    _size = Director::getInstance()->getWinSize();
    
    count = 0;
    
    score = 0;
    
    type = 0;
    
    listSheep = new Vector<Sheep*>();
    
    addSheep();
    
    lbScore = Label::createWithTTF(std::to_string(score), "Marker Felt.ttf", 45);
    lbScore->setPosition(_size.width / 2 , _size.height * 4/5);
    lbScore->setColor(Color3B(255, 255, 0));
    this->addChild(lbScore,100);
    
    
    return true;
}

void SheepLayer::update(float dt)
{
    if(!GameScene::getInstance()->isGameOver && GameScene::getInstance()->gameStatus == play)
    {
        actionSheep();
       // updateXe(1.0);
        updateScore();
    }
    
}


void SheepLayer::onEnter()
{
    Layer::onEnter();
    this->scheduleUpdate();
}

void SheepLayer::onExit()
{
    Layer::onExit();
    this->unscheduleUpdate();
    cleanUp();
    this->removeAllChildrenWithCleanup(true);
}

void SheepLayer::addSheep()
{
    
    
    
    //tao con chim
    auto sheep = Sheep::create();
    sheep->setPosition(_size.width  * 1 / 9, _size.height * 3 / 4);
    this->addChild(sheep, 1000);
    listSheep->pushBack(sheep);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SOUND_BEE);
    
    
    
}

void SheepLayer::updateScore()
{
    lbScore->setString(std::to_string(score));
}
void SheepLayer::actionSheep()
{
    
    
    for(auto _sheep : *listSheep)
    {
        if(_sheep->sheepStaus == isHit)
            return;
        
        
        if(_sheep->getPositionY() <= GameScene::getInstance()->land->getPositionY() + _sheep->getContentSize().height *3 / 4 &&_sheep->sheepStaus == isNormal)
        {
            _sheep->sheepStaus = isHit;
            _sheep->stopAllActions();
             CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SOUND_HIT);
            GameScene::getInstance()->isGameOver = true;
         
            
        }
        
        if(_sheep->velocY <= 0)
        {
            _sheep->velocY = 0.0;
            _sheep->directionY = 1;
            _sheep->sheepStaus = isNormal;
            _sheep->runAction(RotateTo::create(0.6, 30));
        }
        

        
        _sheep->velocY += _sheep->directionY * _sheep->getDeltaA();
        
        _sheep->setPositionY(_sheep->getPositionY() - _sheep->velocY * _sheep->directionY);
        _sheep->setPositionX(_sheep->getPositionX() + 1.0 * _sheep->directionX);
    }
    
   
}

void SheepLayer::cleanUp()
{
    for (auto _sheep : *listSheep )
    {
        listSheep->eraseObject(_sheep);
    
    }
    
    delete listSheep;
    listSheep = nullptr;
    
}

void SheepLayer::getTapAction(cocos2d::Vec2 pos)
{
    
    
    for(auto _sheep : *listSheep)
    {
        
        _sheep->setTapLocation(pos);
        
        if(_sheep->isTap(_sheep->getPosition()) && _sheep->sheepStaus == isNormal)
        {
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(SOUND_CLICK);
            _sheep->sheepStaus = isTap;
            _sheep->directionY = -1;
            _sheep->velocY = 10.0;
            _sheep->runAction(RotateTo::create(0.2, -30));
            count++;
            
            if(count == 5)
            {
                addSheep();
                break;
            }

            if(count == 12)
            {
                addSheep();
                break;
            }

            if(count == 18)
            {
                addSheep();
                break;
            }
            
            if(count == 25)
            {
                addSheep();
                break;
            }

            
        }
    }
}










