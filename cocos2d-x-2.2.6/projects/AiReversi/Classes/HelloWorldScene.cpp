
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
//#include "title.h"
#include "HelloWorldScene.h"
#include "HelloWorld2.h"
#include "cocos2d.h"
#include "Option.h"
#include "Rank.h"
using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;
USING_NS_CC;
int music=0;
extern int sound;
//#include "HelloWorldScene2.h"

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    sound = CCUserDefault::sharedUserDefault()->getIntegerForKey("sound",1);
    if(music==1){SimpleAudioEngine::sharedEngine()->playBackgroundMusic("June.mp3",true);
                SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);}
    //SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.0);
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("Default-568h@2x.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(s.width/2 , s.height/2 ));
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    //シーン切り替えのトリガーになる"1"のボタン
    //ボタンをクリックすると、HelloWorld::myCallbackが発動
    CCMenuItemImage *pBtnItem = CCMenuItemImage::create("newgame.png", "newgame.png", this, menu_selector(HelloWorld::myCallback));
    //CCMenu* pBtns = CCMenu::create(pBtnItem, NULL);
    //pBtns->setPosition(ccp(s.width/5, s.height/6));
    
    
    CCMenuItemImage *pBtnOpt = CCMenuItemImage::create("option.png", "option.png", this, menu_selector(HelloWorld::myCallback2));
    //CCMenu* pBtns = CCMenu::create(pBtnItem,pBtnRank,NULL);
    //pBtns->setPosition(ccp(s.width/5, s.height/6));
    
    
    CCMenuItemImage *pBtnSet = CCMenuItemImage::create("rank.png", "rank.png", this, menu_selector(HelloWorld::myCallback3));
    CCMenu* pSet = CCMenu::create(pBtnItem,pBtnOpt,pBtnSet ,NULL);
    pSet->setPosition(ccp(s.width/2, s.height/6));
    
    
    pSet->alignItemsVerticallyWithPadding(40);

    this->addChild(pSet);


return true;
}



void HelloWorld::myCallback(CCObject* pSender)
{
    //次のシーンとして、HelloWorld2シーンをセット
    CCScene* nextScene = Settei::scene();
    //切り替えの時間を設定。ここでは1秒
    float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}
void HelloWorld::myCallback2(CCObject* pSender)
{
    CCScene* nextScene2= Option::scene();
    float duration = 1.0f;
    CCScene *pScene2= CCTransitionFade::create(duration, nextScene2);
    if(pScene2){
        CCDirector::sharedDirector()->replaceScene(pScene2);
    }
}
void HelloWorld::myCallback3(CCObject* pSender)
{
    CCScene* nextScene3=Rank::scene();
    float duration = 1.0f;
   CCScene *pScene3= CCTransitionFade::create(duration, nextScene3);
    if(pScene3){
        CCDirector::sharedDirector()->replaceScene(pScene3);
	}

   // CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
   // exit(0);
#endif

}
