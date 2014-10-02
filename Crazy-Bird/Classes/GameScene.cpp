#include "GameScene.h"
#include "GameOverLayer.h"
#include "Data.h"

USING_NS_CC;


static GameScene* instance;


GameScene* GameScene::getInstance()
{
    CC_ASSERT(instance != nullptr);
    return instance;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    instance = this;
    
    listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    
    _size = Director::getInstance()->getWinSize();
    
    
    resetGame();
    
    
    return true;
}

void GameScene::resetGame()
{
    this->removeAllChildrenWithCleanup(true);
    
    isGameOver = false;
    
    gameStatus = intro;
    
    addBackGround();
    
    addSky();
    
   
}

void GameScene::loadData()
{
    
    
    
    
   
}

void GameScene::update(float dt)
{
    
    if(gameStatus == play && isGameOver)
    {
        gameStatus = gameOver;
        this->addChild(GameOverLayer::create(),9999);
        this->unscheduleUpdate();
       
    }
    
    if(isGameOver) return;
    
    moveSky();
    

   
}

void GameScene::onExit()
{
    sheepLayer->removeFromParent();
    
    Scene::onExit();
}

void GameScene::addSky()
{
//    sky0 = Sprite::create("Sky.png");
//    sky0->setPosition(_size.width / 2, _size.height - sky0->getContentSize().height / 2);
//    this->addChild(sky0, 100);
//    
//    sky1 = Sprite::create("Sky.png");
//    sky1->setPosition(_size.width * 1.5, _size.height - sky1->getContentSize().height / 2);
//    this->addChild(sky1, 100);
    
}

void GameScene::moveSky()
{
//    float _x0 = sky0->getPositionX();
//    float _x1 = sky1->getPositionX();
//    
//    _x0 -= 0.5;
//    _x1 -= 0.5;
//    
//    if(_x0 <= -sky0->getContentSize().width / 2)
//    {
//        _x0 = _x1 + sky0->getContentSize().width;
//    }
//    
//    if(_x1 <= -sky1->getContentSize().width / 2)
//    {
//        _x1 = _x0 + sky1->getContentSize().width;
//    }
//    
//    sky0->setPositionX(_x0);
//    sky1->setPositionX(_x1);
}


void GameScene::addBackGround()
{
    auto bg = Sprite::create("bg2.png");
    bg->setPosition(_size.width / 2, _size.height / 2);
    this->addChild(bg);
    
    land = Sprite::create("Land.png");
    land->setPosition(_size.width / 2, land->getContentSize().height / 2);
    this->addChild(land, 104);
}

void GameScene::addFence(float dt)
{
    float d = (rand()%6) * 10;
    
    auto fence = Sprite::create("Fence.png");
    fence->setPosition(_size.width + fence->getContentSize().width, land->getContentSize().height + d);
    this->addChild(fence, 103);
    fence->runAction(MoveTo::create(12.0, Vec2(-fence->getContentSize().width, fence->getPositionY())));

}

void GameScene::addSheepLayer()
{
    sheepLayer = SheepLayer::create();
    this->addChild(sheepLayer,9999);
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if(!isGameOver && gameStatus == play)
    {
        sheepLayer->getTapAction(touch->getLocation());
    }
    
    return true;
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if(gameStatus == intro)
    {
        gameStatus = play;
        addSheepLayer();
        this->scheduleUpdate();
        //addSheepLayer();
        //addFence(0);
        //this->schedule(schedule_selector(GameScene::addFence), 3.5);
    }
}

