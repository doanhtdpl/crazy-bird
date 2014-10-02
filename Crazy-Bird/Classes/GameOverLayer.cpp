//
//  GameOverLayer.cpp
//  CrazyGost
//
//  Created by Tran Tho on 8/26/14.
//
//

#include "GameOverLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include  "Menulayer.h"
#include "GameScene.h"
//#include "IOSShare.h"
//#include <GKHWrapperCpp.h>


bool bChoosenAdsOne = true;

bool GameOverLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    
   
    return true;
}

void GameOverLayer::onEnter()
{
   
    
    Layout* layout  = static_cast<Layout*>(cocostudio::timeline::NodeReader::getInstance()->createNode("GameOver.json"));
    this->addChild(layout);
    
    Button* button;
    
    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Play"));
    button->addTouchEventListener(CC_CALLBACK_2(GameOverLayer::touchPlayButtonEvent,  this));
    
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Rate"));
//    button->addTouchEventListener(CC_CALLBACK_2(GameOverLayer::touchRateButtonEvent,  this));
//    
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Score"));
//    button->addTouchEventListener(CC_CALLBACK_2(GameOverLayer::touchScoreButtonEvent,  this));
//    
//    button = static_cast<Button*>(Helper::seekWidgetByName(layout, "Button_Share"));
//    button->addTouchEventListener(CC_CALLBACK_2(GameOverLayer::touchShareButtonEvent,  this));

//    static_cast<Text*>(Helper::seekWidgetByName(layout, "Label_Score"))
//    ->setString(std::to_string(GameScene::getInstance()->score));
//    
//    static_cast<Text*>(Helper::seekWidgetByName(layout, "Label_Best"))
//    ->setString(std::to_string(UserDefault::getInstance()->getIntegerForKey("HIGHT_SCORE")));
    
    Layer::onEnter();

}


void GameOverLayer::onExit()
{
    _eventDispatcher->removeEventListenersForTarget(this);
    
    
    Layer::onExit();
}

void GameOverLayer::touchPlayButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
//        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(CLICK);
        this->removeFromParentAndCleanup(true);
        Director::getInstance()->replaceScene(GameScene::create());
        
    }

}

void GameOverLayer::touchRateButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
       // CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(CLICK);
      
        
    }
    
}

void GameOverLayer::touchScoreButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
//        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(CLICK);
//        GKHWrapperCpp gkh;
//        gkh.showLeaderBoard();

        //IOSShare::share(0, 0, UserDefault::getInstance()->getIntegerForKey("HIGHT_SCORE"));
        CCLOG("Play");
    }
    
}

void GameOverLayer::touchShareButtonEvent(cocos2d::Ref *pSender, ui::Widget::TouchEventType type)
{
    if(type == ui::Widget::TouchEventType::ENDED)
    {
//        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(CLICK);
//        
//        IOSShare::share(0, 0, GameScene::getInstance()->hightScore);
        CCLOG("Play");
    }
    
}


