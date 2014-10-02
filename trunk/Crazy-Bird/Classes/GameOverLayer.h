//
//  GameOverLayer.h
//  CrazyGost
//
//  Created by Tran Tho on 8/26/14.
//
//

#ifndef __CrazyGost__GameOverLayer__
#define __CrazyGost__GameOverLayer__

#include "cocos2d.h"
#include "CocosGUI.h"
//#include "ChartboostX.h"

USING_NS_CC;

using namespace cocos2d;
using namespace ui;

class GameOverLayer : public Layer
{
public:
    
    CREATE_FUNC(GameOverLayer);
    
    virtual bool init() override;
	virtual void onEnter() override;
	virtual void onExit() override;
    
    
    
private:
    
    
    void touchPlayButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchScoreButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchRateButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    void touchShareButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
    
    
    
};

#endif /* defined(__CrazyGost__GameOverLayer__) */
