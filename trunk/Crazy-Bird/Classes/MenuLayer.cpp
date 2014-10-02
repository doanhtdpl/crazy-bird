//
//  MenuScene.cpp
//  CrazyGost
//
//  Created by Tran Tho on 8/23/14.
//
//

#include "MenuLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"
//#include "ChartboostX.h"
//#include <GKHWrapperCpp.h>




using namespace CocosDenshion;
using namespace cocostudio;


Scene* Menulayer::scene()
{
    auto scene = Scene::create();
    
    auto layer = Menulayer::create();
    
    scene->addChild(layer);
    
    return scene;
}


bool Menulayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    _size = Director::getInstance()->getWinSize();
    
    this->scheduleUpdate();
    
    addSky();
    
    return true;
}

void Menulayer::update(float dt)
{
    moveSky();
    
}

void Menulayer::onEnter()
{
    Layer::onEnter();
    
    
    Layout* layout = static_cast<Layout*>(cocostudio::timeline::NodeReader::getInstance()->createNode("Menu.json"));
    this->addChild(layout);
    
    Button* button;
        
    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Play"));
    button->addTouchEventListener(CC_CALLBACK_2(Menulayer::touchButtonPlayEvent,  this));
//    
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Rate"));
//    button->addTouchEventListener(CC_CALLBACK_2(Menulayer::touchButtonRateEvent,  this));
//    
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Score"));
//    button->addTouchEventListener(CC_CALLBACK_2(Menulayer::touchButtonScoreEvent,  this));
}


void Menulayer::touchButtonPlayEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
        //SimpleAudioEngine::getInstance()->playEffect(CLICK);
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        Director::getInstance()->replaceScene(GameScene::create());
        
        
    }
}

void Menulayer::touchButtonScoreEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
//        SimpleAudioEngine::getInstance()->playEffect(CLICK);
//        GKHWrapperCpp gkh;
//        gkh.showLeaderBoard();
    }

}

void Menulayer::touchButtonRateEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{if(type == ui::Widget::TouchEventType::ENDED)
    
//    {
//        SimpleAudioEngine::getInstance()->playEffect(CLICK);
//       IOSShare::rate();
//    }
    
    CCLOG("rate");
}

void Menulayer::addSky()
{
    sky0 = Sprite::create("Sky.png");
    sky0->setPosition(_size.width / 2, _size.height - sky0->getContentSize().height / 2);
    this->addChild(sky0, 100);
    
    sky1 = Sprite::create("Sky.png");
    sky1->setPosition(_size.width * 1.5, _size.height - sky1->getContentSize().height / 2);
    this->addChild(sky1, 100);
    
}

void Menulayer::moveSky()
{
    float _x0 = sky0->getPositionX();
    float _x1 = sky1->getPositionX();
    
    _x0 -= 0.5;
    _x1 -= 0.5;
    
    if(_x0 <= -sky0->getContentSize().width / 2)
    {
        _x0 = _x1 + sky0->getContentSize().width;
    }
    
    if(_x1 <= -sky1->getContentSize().width / 2)
    {
        _x1 = _x0 + sky1->getContentSize().width;
    }
    
    sky0->setPositionX(_x0);
    sky1->setPositionX(_x1);
}

void Menulayer::onExit()
{
    _eventDispatcher->removeEventListenersForTarget(this);
    this->unscheduleUpdate();
    Layer::onExit();
    
}



