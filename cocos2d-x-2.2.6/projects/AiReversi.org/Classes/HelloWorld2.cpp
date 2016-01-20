//
//  Settei.cpp
//  Othello
//
//  Created by 宮下修治 on 2015/06/21.
//
//


#include "HelloWorld2.h"
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
//#include "title.h"
#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "Option.h"
using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;
USING_NS_CC;
int upd;


//extern int D,jo,chu,shu;
CCScene* Settei::scene()
{
    CCScene *scene = CCScene::create();
    Settei *layer = Settei::create();
    scene->addChild(layer);
    
    return scene;
}

bool Settei::init()
{

	if ( !CCLayer::init() )
    {
        return false;
    }
	level3();

	this->scheduleUpdate();


    CCSize s = CCDirector::sharedDirector()->getWinSize();

    //シーン切り替えのトリガーになる"2"のボタン
    //ボタンをクリックすると、HelloWorld2::myCallbackが発動
    CCMenuItemImage *pBtn1 = CCMenuItemImage::create("level1.png", "level1_on.png", this, menu_selector(Settei::myCallback1));
    //CCMenu* pBtns = CCMenu::create(pBtnItem, NULL);
    //pBtns->setPosition(ccp(s.width/5, s.height/6));
    
    
    CCMenuItemImage *pBtn2 = CCMenuItemImage::create("level2.png", "level2_on.png", this, menu_selector(Settei::myCallback2));
    //CCMenu* pBtns = CCMenu::create(pBtnItem,pBtnRank,NULL);
    //pBtns->setPosition(ccp(s.width/5, s.height/6));
    
    CCMenuItemImage *pBtn3 = CCMenuItemImage::create("level3.png", "level3_on.png", this, menu_selector(Settei::myCallback3));
    //CCMenu* pBtns = CCMenu::create(pBtnItem, NULL);
    //pBtns->setPosition(ccp(s.width/5, s.height/6));
    
    
    CCMenuItemImage *pBtn4 = CCMenuItemImage::create("level4.png", "level4_on.png", this, menu_selector(Settei::myCallback4));
    //CCMenu* pBtns = CCMenu::create(pBtnItem,pBtnRank,NULL);
    //pBtns->setPosition(ccp(s.width/5, s.height/6));
    
    
    CCMenuItemImage *pBtn5 = CCMenuItemImage::create("level5.png", "level5_on.png", this, menu_selector(Settei::myCallback5));
    CCMenu* pSet = CCMenu::create(pBtn1,pBtn2,pBtn3,pBtn4,pBtn5,NULL);
    pSet->setPosition(ccp(s.width/3, s.height/3));
    
    
    pSet->alignItemsHorizontallyWithPadding(10);
     pSet->setScale(0.7);
    this->addChild(pSet);
    

    this->setKeypadEnabled(true);
    CCMenuItemImage *pBtn7 = CCMenuItemImage::create("sente.png", "sente_on.png", this, menu_selector(Settei::myCallback7));
    CCMenuItemImage *pBtn8 = CCMenuItemImage::create("gote.png", "gote_on.png", this, menu_selector(Settei::myCallback8));
  //  CCMenuItemImage *pBtn9 = CCMenuItemImage::create("gote.png", "gote_on.png", this, menu_selector(Settei::myCallback8));
    CCMenu* pSet2 = CCMenu::create(pBtn7,pBtn8,NULL);
    pSet2->alignItemsHorizontallyWithPadding(40);
    pSet2->setPosition(ccp(s.width/2, s.height/4));
//CCMenuItemImage *pBtnItem = CCMenuItemImage::create("rtn.png", "rtn.png", this, menu_selector(Settei::myCallback6));
   // CCMenu* pBtn = CCMenu::create(pBtnItem, NULL);
   // pBtn->setPosition(ccp(s.width*.5, s.height*.6));
    this->addChild(pSet2);
   // this->addChild(pBtn);
    return true;
}
void Settei::myCallback1(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    level1();    //次のシーンとして、HelloWorldシーンをセット

    //CCScene* nextScene = HelloWorld::scene();
    //切り替えの時間を設定。ここでは1秒
    //float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    //CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    //if(pScene){
      //  CCDirector::sharedDirector()->replaceScene(pScene);
   // }
  
}
void Settei::myCallback2(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    level2();

    //次のシーンとして、HelloWorldシーンをセット
    //CCScene* nextScene = HelloWorld::scene();
    //切り替えの時間を設定。ここでは1秒
    //float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    //CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    //if(pScene){
     //   CCDirector::sharedDirector()->replaceScene(pScene);
   // }
}
void Settei::myCallback3(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    level3();

    //次のシーンとして、HelloWorldシーンをセット
    //CCScene* nextScene = HelloWorld::scene();
    //切り替えの時間を設定。ここでは1秒
    //float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    //CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    //if(pScene){
    //    CCDirector::sharedDirector()->replaceScene(pScene);
    //}
}
void Settei::myCallback4(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    level4();

    //次のシーンとして、HelloWorldシーンをセット
    //CCScene* nextScene = HelloWorld::scene();
    //切り替えの時間を設定。ここでは1秒
    //float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    //CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    //if(pScene){
     //   CCDirector::sharedDirector()->replaceScene(pScene);
    //}
}
void Settei::myCallback5(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    level5();

    //次のシーンとして、HelloWorldシーンをセット
    //CCScene* nextScene = HelloWorld::scene();
    //切り替えの時間を設定。ここでは1秒
    //float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    //CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    //if(pScene){
     //   CCDirector::sharedDirector()->replaceScene(pScene);
    //}
}
void Settei::keyBackClicked() {

	 CCScene* HelloScene=(CCScene*)HelloWorld::create();
	    CCDirector::sharedDirector()->replaceScene(HelloScene);

    //バックキー処理
}
void Settei::myCallback7(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    //次のシーンとして、HelloWorldシーンをセット
    got();
    CCScene* nextScene = GameScene::scene();
    //切り替えの時間を設定。ここでは1秒
    float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}
void Settei::myCallback8(CCObject* pSender)
{
    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    //次のシーンとして、HelloWorldシーンをセット
   sen();
    CCScene* nextScene = GameScene::scene();
    //切り替えの時間を設定。ここでは1秒
    float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    CCScene* pScene = CCTransitionFade::create(duration, nextScene);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}

/*void Settei::lv(int l)
{
    CCUserDefault* userDefault=CCUserDefault::sharedUserDefault();
    const char* levelkey="level";
    int lv=userDefault->getIntegerForKey(levelkey,2);
    level=l;
    userDefault->setIntegerForKey(levelkey,lv);
    userDefault->flush();
}
*/

void Settei::first(void)
{

		CCSize winSize=CCDirector::sharedDirector()->getWinSize();

   CCString *score = CCString::createWithFormat("Difficulty   Level %i",lv);
   CCLabelTTF* passLabel = CCLabelTTF::create(score->getCString(), "", LEVEL_FONT_SIZE);
   //CCLabelTTF* passLabel2=CCLabelTTF::create("Difficulty   Level    ","",LEVEL_FONT_SIZE);
   //CCMenuItemImage* passItem=CCMenuItemImage::create("pass.png",
     //                                                "pass_pressed.png",
       //                                              this,menu_selector(GameScene::tapPassButton));

   passLabel->setPosition(CCPointMake(winSize.width/2, winSize.height/2));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
   //menu->setPosition(CCPointZero);
   passLabel->setColor(ccc3(255, 0, 127));
   //this->addChild(passLabel2,1);

   this->addChild(passLabel);

}
void Settei::update(float frame)
{
	 const int tagGametimeLabel=100;
	 CCString *score = CCString::createWithFormat("DIFFCULTY   Level %i",lv);
	   CCLabelTTF* passLabel = (CCLabelTTF*)this->getChildByTag(tagGametimeLabel);
	   //CCLabelTTF* passLabel2=CCLabelTTF::create("Difficulty   Level    ","",LEVEL_FONT_SIZE);
	   //CCMenuItemImage* passItem=CCMenuItemImage::create("pass.png",
	     //                                                "pass_pressed.png",
	       //                                              this,menu_selector(GameScene::tapPassButton));
	   if(passLabel)
	   {
		   passLabel->setString(score->getCString());
	   }
	   else
	  {
		   CCSize winSize=CCDirector::sharedDirector()->getWinSize();
		   passLabel=CCLabelTTF::create(score->getCString(),"Arial",LEVEL_FONT_SIZE);
		   passLabel->setPosition(CCPointMake(winSize.width/2, winSize.height/1.4));    //CCMenu *menu=CCMenu::create(passLabel,NULL);

	   //menu->setPosition(CCPointZero);
	  passLabel->setColor(ccc3(10, 220, 127));
	   //this->addChild(passLabel2,1);
	   passLabel->setTag(tagGametimeLabel);
	   this->addChild(passLabel);
	  }
}
