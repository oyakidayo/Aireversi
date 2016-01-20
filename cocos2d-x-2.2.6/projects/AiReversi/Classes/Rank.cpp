//
//  Rank.cpp
//  Othello
//
//  Created by 宮下修治 on 2015/07/25.
//
//

#include "HelloWorld2.h"
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
//#include "title.h"
#include "HelloWorldScene.h"
#include "Option.h"
#include "Rank.h"
#include "AppMacros.h"
using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;
USING_NS_CC;

//extern int D,jo,chu,shu;
CCScene* Rank::scene()
{
    CCScene *scene = CCScene::create();
    Rank *layer = Rank::create();
    scene->addChild(layer);
    
    return scene;
}

bool Rank::init()
{
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    //level3();
    //this->setKeypadEnabled(true);
   // CCSize s = CCDirector::sharedDirector()->getWinSize();
    //Onの状態
    this->setKeypadEnabled(true);
    //画面サイズの取得
    //CCSize winsize = CCDirector::sharedDirector()->getWinSize();
    
    //スプライトの作成
    //CCSprite *newSprite = CCSprite::create("Default-568h@2x.png");
    
    //画像の座標の決定
    //newSprite->setPosition(ccp(winsize.width / 2, winsize.height / 2));
    
    //画像をレイヤに追加
    //this->addChild(newSprite);
   first();
   
    show();
    makeHighScoreLabel();
    //setTouchEnabled(true);
    //setTouchMode(kCCTouchesOneByOne);
   makeReset();
    return true;
}
void Rank::first(void)
    {
        
        CCSize winSize=CCDirector::sharedDirector()->getWinSize();
        
        CCString *score = CCString::createWithFormat("RANKING");
        CCLabelTTF* passLabel = CCLabelTTF::create(score->getCString(), "", LEVEL_FONT_SIZE);
        //CCLabelTTF* passLabel2=CCLabelTTF::create("Difficulty   Level    ","",LEVEL_FONT_SIZE);
        //CCMenuItemImage* passItem=CCMenuItemImage::create("pass.png",
        //                                                "pass_pressed.png",
        //                                              this,menu_selector(GameScene::tapPassButton));
        
        passLabel->setPosition(CCPointMake(winSize.width/2, winSize.height*0.7));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
        //menu->setPosition(CCPointZero);
        passLabel->setColor(ccc3(255, 0, 127));
        //this->addChild(passLabel2,1);
        
        this->addChild(passLabel);
        
    }

void Rank::makeReset(void)
{
    

CCSize winSize=CCDirector::sharedDirector()->getWinSize();
CCLabelTTF* reSet=CCLabelTTF::create("O K","Arial",LEVEL_FONT_SIZE);
CCMenuItemLabel* reSetLabel=CCMenuItemLabel::create(reSet,this,menu_selector(Rank::tapReset));
reSetLabel->setPosition(ccp(winSize.width*0.5f,winSize.height*0.8f));

CCMenu *menu=CCMenu::create(reSetLabel,NULL);
menu->setPosition(CCPointZero);
this->addChild(menu);
}

void Rank::tapReset(CCNode *node)
    {
        
        CCScene* HelloScene=(CCScene*)HelloWorld::create();
        CCDirector::sharedDirector()->replaceScene(HelloScene);
    }


void Rank::show()
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
   
   
	   CCLabelTTF* passLabel = CCLabelTTF::create("  WIN","",LEVEL_FONT_SIZE);
	   
	   passLabel->setColor(ccc3(10, 220, 127));
    
    passLabel->setPosition(CCPointMake(winSize.width*0.4f, winSize.height*0.6));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
    
    this->addChild(passLabel);
    CCLabelTTF* passLabel2 = CCLabelTTF::create("LOSE","",LEVEL_FONT_SIZE);
	   
	   passLabel2->setColor(ccc3(10, 220, 127));
    
    passLabel2->setPosition(CCPointMake(winSize.width*0.6f, winSize.height*0.6));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
    
    this->addChild(passLabel2);
    CCLabelTTF* passLabel3 = CCLabelTTF::create("DRAW","",LEVEL_FONT_SIZE);
	   
	   passLabel3->setColor(ccc3(10, 220, 127));
   
    passLabel3->setPosition(CCPointMake(winSize.width*0.8f, winSize.height*0.6));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
    
    this->addChild(passLabel3);
}

void Rank::makeHighScoreLabel()
 {
 CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
 int Score_w1 = _userDef->getIntegerForKey("lv1w", 0);
 
 int Score_l1 = _userDef->getIntegerForKey("lv1l", 0);
 int Score_draw1 =_userDef->getIntegerForKey("draw1", 0);
 //以前のハイスコアを表示
 
 CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
 CCString* ScoreString_w = CCString::createWithFormat("%8d", Score_w1);
 CCString* ScoreString_l = CCString::createWithFormat("%8d", Score_l1);
 CCString* ScoreString_draw = CCString::createWithFormat("%8d", Score_draw1);
 CCLabelTTF* ScoreLabel_1 = CCLabelTTF::create("Level 1", "", LEVEL_FONT_SIZE);
 CCLabelTTF* ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", LEVEL_FONT_SIZE);
 CCLabelTTF* ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", LEVEL_FONT_SIZE);
 CCLabelTTF* ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_1->setPosition(ccp(bgSize.width * 0.2f, bgSize.height * 0.1f));
     ScoreLabel_w->setPosition(ccp(bgSize.width * 0.4f, bgSize.height * 0.1f));
 ScoreLabel_l->setPosition(ccp(bgSize.width * 0.6f, bgSize.height * 0.1f));
 ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.1f));
 //ScoreLabel_w->setTag(score_w1);
//ScoreLabel_w->setColor(ccc3(10, 220, 127));
     this->addChild(ScoreLabel_1);
     this->addChild(ScoreLabel_w);
 this->addChild(ScoreLabel_l);
 this->addChild(ScoreLabel_draw);
 
 
 //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
 Score_w2= _userDef->getIntegerForKey("lv2w", 0);
 
 Score_l2 = _userDef->getIntegerForKey("lv2l", 0);
 Score_draw2 =_userDef->getIntegerForKey("draw2", 0);
 //以前のハイスコアを表示
 
 //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
 ScoreString_w = CCString::createWithFormat("%8d", Score_w2);
 ScoreString_l = CCString::createWithFormat("%8d", Score_l2);
 ScoreString_draw = CCString::createWithFormat("%8d", Score_draw2);
     CCLabelTTF* ScoreLabel_2 = CCLabelTTF::create("Level 2", "", LEVEL_FONT_SIZE);
 ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_2->setPosition(ccp(bgSize.width * 0.2f, bgSize.height * 0.2f));
     ScoreLabel_w->setPosition(ccp(bgSize.width * 0.4f, bgSize.height * 0.2f));
 ScoreLabel_l->setPosition(ccp(bgSize.width * 0.6f, bgSize.height * 0.2f));
 ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.2f));
 //ScoreLabel_w->setTag(score_w1);
     this->addChild(ScoreLabel_2);
     this->addChild(ScoreLabel_w);
 this->addChild(ScoreLabel_l);
 this->addChild(ScoreLabel_draw);
 
 
 
 //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
 Score_w3 = _userDef->getIntegerForKey("lv3w", 0);
 
 Score_l3 = _userDef->getIntegerForKey("lv3l", 0);
 Score_draw3 =_userDef->getIntegerForKey("draw3", 0);
 //以前のハイスコアを表示
 
 //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
 ScoreString_w = CCString::createWithFormat("%8d", Score_w3);
 ScoreString_l = CCString::createWithFormat("%8d", Score_l3);
 ScoreString_draw = CCString::createWithFormat("%8d", Score_draw3);
     CCLabelTTF* ScoreLabel_3 = CCLabelTTF::create("Level 3", "", LEVEL_FONT_SIZE);
 ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_3->setPosition(ccp(bgSize.width * 0.2f, bgSize.height * 0.3f));
     ScoreLabel_w->setPosition(ccp(bgSize.width * 0.4f, bgSize.height * 0.3f));
 ScoreLabel_l->setPosition(ccp(bgSize.width * 0.6f, bgSize.height * 0.3f));
 ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.3f));
 //ScoreLabel_w->setTag(score_w1);
 this->addChild(ScoreLabel_3);
     this->addChild(ScoreLabel_w);
 this->addChild(ScoreLabel_l);
 this->addChild(ScoreLabel_draw);
 
 
 
 //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
 Score_w4 = _userDef->getIntegerForKey("lv4w", 0);
 
 Score_l4 = _userDef->getIntegerForKey("lv4l", 0);
 Score_draw4 =_userDef->getIntegerForKey("draw4", 0);
 //以前のハイスコアを表示
 
 //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
 ScoreString_w = CCString::createWithFormat("%8d", Score_w4);
 ScoreString_l = CCString::createWithFormat("%8d", Score_l4);
 ScoreString_draw = CCString::createWithFormat("%8d", Score_draw4);
     CCLabelTTF* ScoreLabel_4 = CCLabelTTF::create("Level 4", "", LEVEL_FONT_SIZE);
 ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_4->setPosition(ccp(bgSize.width * 0.2f, bgSize.height * 0.4f));
     ScoreLabel_w->setPosition(ccp(bgSize.width * 0.4f, bgSize.height * 0.4f));
 ScoreLabel_l->setPosition(ccp(bgSize.width * 0.6f, bgSize.height * 0.4f));
 ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.4f));
 //ScoreLabel_w->setTag(score_w1);
 this->addChild(ScoreLabel_4);
     this->addChild(ScoreLabel_w);
 this->addChild(ScoreLabel_l);
 this->addChild(ScoreLabel_draw);
 
 
 //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
 Score_w5 = _userDef->getIntegerForKey("lv5w", 0);
 
 Score_l5 = _userDef->getIntegerForKey("lv5l", 0);
 Score_draw5 =_userDef->getIntegerForKey("draw5", 0);
 //以前のハイスコアを表示
 
 //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
 ScoreString_w = CCString::createWithFormat("%8d", Score_w5);
 ScoreString_l = CCString::createWithFormat("%8d", Score_l5);
 ScoreString_draw = CCString::createWithFormat("%8d", Score_draw5);
     CCLabelTTF* ScoreLabel_5 = CCLabelTTF::create("Level 5", "", LEVEL_FONT_SIZE);
 ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", LEVEL_FONT_SIZE);
 ScoreLabel_5->setPosition(ccp(bgSize.width * 0.2f, bgSize.height * 0.5f));
     ScoreLabel_w->setPosition(ccp(bgSize.width * 0.4f, bgSize.height * 0.5f));
 ScoreLabel_l->setPosition(ccp(bgSize.width * 0.6f, bgSize.height * 0.5f));
 ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.5f));
 //ScoreLabel_w->setTag(score_w1);
     this->addChild(ScoreLabel_5);
     this->addChild(ScoreLabel_w);
 this->addChild(ScoreLabel_l);
 this->addChild(ScoreLabel_draw);
     
     keyBackClicked();
 
 }
void Rank::keyBackClicked() {
    
    CCScene* HelloScene=(CCScene*)HelloWorld::create();
    CCDirector::sharedDirector()->replaceScene(HelloScene);
    
/*#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif*/
    
    //バックキー処理
}
bool Rank::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    
    CCScene* HelloScene=(CCScene*)HelloWorld::create();
    CCDirector::sharedDirector()->replaceScene(HelloScene);
    
    return true;
};
