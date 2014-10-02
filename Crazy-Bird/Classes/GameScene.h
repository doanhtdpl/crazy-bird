#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SheepLayer.h"

using namespace cocos2d;

typedef enum
{
    intro,
    play,
    gameOver,
}GameStatus;

class GameScene : public cocos2d::Scene
{
public:
    
    virtual bool init() override;
    
    virtual void update(float dt) override;
    
    virtual void onExit() override;
    
    static GameScene* getInstance();
    
    GameStatus gameStatus;
    
    CREATE_FUNC(GameScene);
    
    bool isGameOver;
    
     Sprite* land;
    
    
    
private:
    
    Size _size;
    
    Sprite* sky0;
    Sprite* sky1;
    
    void loadData();
   
    
    void addSky();
    
    void moveSky();
    
    void addFence(float dt);
    
    SheepLayer* sheepLayer;
    
    void addSheepLayer();
    
    void addBackGround();
    
    void resetGame();
    
    EventListenerTouchOneByOne* listener;
    
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

};

#endif // __HELLOWORLD_SCENE_H__
