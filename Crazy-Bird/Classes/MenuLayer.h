//
//  MenuScene.h
//  CrazyGost
//
//  Created by Tran Tho on 8/23/14.
//
//

#ifndef __CrazyGost__MenuScene__
#define __CrazyGost__MenuScene__

#include "cocos2d.h"
#include "CocosGUI.h"
//#include "IOSShare.h"
//#include "ChartboostX.h"

USING_NS_CC;

using namespace cocos2d;
using namespace ui;


class Menulayer : public Layer
{
public:
    
    static Scene* scene();
    
    CREATE_FUNC(Menulayer);
    
    virtual bool init() override;
    virtual void update(float dt) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
private :
    Size _size;
    
    Sprite* sky0;
    Sprite* sky1;
    
    void addSky();
    
    void moveSky();
   
    
    void touchButtonPlayEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchButtonScoreEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchButtonRateEvent(Ref* pSender, ui::Widget::TouchEventType type);
    
};

#endif /* defined(__CrazyGost__MenuScene__) */
