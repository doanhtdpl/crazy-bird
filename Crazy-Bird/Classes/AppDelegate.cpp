#include "AppDelegate.h"
#include "GameScene.h"
#include "MenuLayer.h"
#include "config.h"
#include "Data.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
    
    glview->setDesignResolutionSize(1024, 768, ResolutionPolicy::NO_BORDER);
    
    
    auto fileUntils = FileUtils::getInstance();
	std::vector<std::string> searchPaths;
	searchPaths.push_back("Sheep");
    searchPaths.push_back("Flower");
    searchPaths.push_back("Fruit");
    searchPaths.push_back("Hourse");
    searchPaths.push_back("Animal");
    searchPaths.push_back("BackGround");
    searchPaths.push_back("Vegetables");

    
	fileUntils->setSearchPaths(searchPaths);
    
    DataImage::getInstance()->readFile("data.csv", ',');
    
    //Load resource
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("trym.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite.plist");
    
    
    
    //Load audio
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_BEE);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_CLICK);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_HIT);
    
    //DataImage::getInstance()->readFile("data.csv", ',');


    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = Menulayer::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
