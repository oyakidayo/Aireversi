
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
	CCScene* Option::scene()
	{
	    CCScene *scene = CCScene::create();
	    Option *layer = Option::create();
	    scene->addChild(layer);

	    return scene;
	}

	bool Option::init()
	{

		if ( !CCLayer::init() )
	    {
	        return false;
	    }
        makeReturn();
	    this->setKeypadEnabled(true);
        //setTouchEnabled(true);
        //setTouchMode(kCCTouchesOneByOne);
        CCSize s = CCDirector::sharedDirector()->getWinSize();
    //Onの状態
  if(music==1){

	  CCMenuItemImage* itemOn = CCMenuItemImage::create("bgm_on.png", "bgm_on2.png");


    //Offの状態
    CCMenuItemImage* itemOff = CCMenuItemImage::create("bgm_off.png", "bgm_off2.png");
    //OnとOffでトグルを作成
     CCMenuItemToggle* toggle1 = CCMenuItemToggle::createWithTarget(
          this,
          menu_selector(Option::message),
          itemOn,itemOff,NULL);
     //それをメニューに登録して
       CCMenu* menu = CCMenu::create(toggle1, NULL);
      menu->setPosition(ccp(s.width/2, s.height/8
    		  ));
       //メニューを表示させる
       addChild(menu);
  }
  else{

	  CCMenuItemImage* itemOff = CCMenuItemImage::create("bgm_on.png", "bgm_on2.png");


	     //Offの状態
	     CCMenuItemImage* itemOn = CCMenuItemImage::create("bgm_off.png", "bgm_off2.png");
	     //OnとOffでトグルを作成
	      CCMenuItemToggle* toggle1 = CCMenuItemToggle::createWithTarget(
	           this,
	           menu_selector(Option::message),
	           itemOn,itemOff,NULL);
	      //それをメニューに登録して
	        CCMenu* menu = CCMenu::create(toggle1, NULL);
	       menu->setPosition(ccp(s.width/2, s.height/8));
	        //メニューを表示させる
	        addChild(menu);



  }




    CCSize s2 = CCDirector::sharedDirector()->getWinSize();
    //Onの状態
    if (sound==1){

    	CCMenuItemImage* itemOn2 = CCMenuItemImage::create("sound_on.png", "sound_on2.png");

    //Offの状態
    CCMenuItemImage* itemOff2 = CCMenuItemImage::create("sound_off.png", "sound_off2.png");
    //Offの状態

    	    CCMenuItemToggle* toggle2 = CCMenuItemToggle::createWithTarget(
    	           this,
    	           menu_selector(Option::message2),
    	           itemOn2,itemOff2,NULL);

    	    //OnとOffでトグルを作成

    	    //それをメニューに登録して
    	    CCMenu* menu2 = CCMenu::create(toggle2, NULL);
    	    //メニューを表示させる
    	    menu2->setPosition(ccp(s.width/2, s.height/4.9));
    	   addChild(menu2);
}
    else {
        //sound=1;
    	CCMenuItemImage* itemOff2 = CCMenuItemImage::create("sound_on.png", "sound_on2.png");

    	    //Offの状態
    	    CCMenuItemImage* itemOn2 = CCMenuItemImage::create("sound_off.png", "sound_off2.png");
    	    CCMenuItemToggle* toggle2 = CCMenuItemToggle::createWithTarget(
    	           this,
    	           menu_selector(Option::message2),
    	           itemOn2,itemOff2,NULL);

    	    //OnとOffでトグルを作成

    	    //それをメニューに登録して
    	    CCMenu* menu2 = CCMenu::create(toggle2, NULL);
    	    //メニューを表示させる
    	    menu2->setPosition(ccp(s.width/2, s.height/4.9));
    	   addChild(menu2);
}


    CCSize s3 = CCDirector::sharedDirector()->getWinSize();
    //Onの状態
    if(hint==1){
    	CCMenuItemImage* itemOn3 = CCMenuItemImage::create("hint_on.png", "hint_on2.png");


    //Offの状態
    CCMenuItemImage* itemOff3 = CCMenuItemImage::create("hint_off.png", "hint_off2.png");

    //OnとOffでトグルを作成
    CCMenuItemToggle* toggle3 = CCMenuItemToggle::createWithTarget(
        this,
        menu_selector(Option::message3),
        itemOn3,itemOff3,NULL);

    //それをメニューに登録して
    CCMenu* menu3 = CCMenu::create(toggle3, NULL);
    //CCMenu* pSet = CCMenu::create(toggle1,toggle2,toggle3,NULL);
     //pSet->setPosition(ccp(s.width/2, s.height/3));


    //pSet->alignItemsVerticallyWithPadding(40);;//メニューを表示させる
    menu3->setPosition(ccp(s.width/2, s.height/3.5));
    addChild(menu3);
    }
    else{
    	    	CCMenuItemImage* itemOff3 = CCMenuItemImage::create("hint_on.png", "hint_on2.png");


    	    //Offの状態
    	    CCMenuItemImage* itemOn3 = CCMenuItemImage::create("hint_off.png", "hint_off2.png");

    	    //OnとOffでトグルを作成
    	    CCMenuItemToggle* toggle3 = CCMenuItemToggle::createWithTarget(
    	        this,
    	        menu_selector(Option::message3),
    	        itemOn3,itemOff3,NULL);

    	    //それをメニューに登録して
    	    CCMenu* menu3 = CCMenu::create(toggle3, NULL);
    	    //CCMenu* pSet = CCMenu::create(toggle1,toggle2,toggle3,NULL);
    	     //pSet->setPosition(ccp(s.width/2, s.height/3));


    	    //pSet->alignItemsVerticallyWithPadding(40);;//メニューを表示させる
    	    menu3->setPosition(ccp(s.width/2, s.height/3.5));
    	    addChild(menu3);

    }
   //Option::makeHighScoreLabel();
    return true;
}
void Option::message(CCObject* sender){
    int index = dynamic_cast<CCMenuItemToggle*>(sender)->getSelectedIndex();

    if(index ==0){
    	music=1;
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("June.mp3",true);
        SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.7);
    }else{
    	music=0;
    	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
}
void Option::message2(CCObject* sender){
    int index2 = dynamic_cast<CCMenuItemToggle*>(sender)->getSelectedIndex();

    if(index2 ==0){
    	SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    	SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");
    		sound=0;
    }
    else{
    	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.0);
    	sound=1;
}
}
void Option::message3(CCObject* sender){
    int index3 = dynamic_cast<CCMenuItemToggle*>(sender)->getSelectedIndex();

    if(index3 == 1){
        hint=1;
    }else{
    	hint=0;
    }
}
void Option::keyBackClicked() {

    CCScene* HelloScene=(CCScene*)HelloWorld::create();
    CCDirector::sharedDirector()->replaceScene(HelloScene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
   exit(0);
#endif

    //バックキー処理
}
void Option::Show()
{
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	//CCString *score = CCString::createWithFormat("Option");
	   CCLabelTTF* passLabel = CCLabelTTF::create("Option","",LEVEL_FONT_SIZE);
	   //CCLabelTTF* passLabel2=CCLabelTTF::create("Difficulty   Level    ","",LEVEL_FONT_SIZE);
	   passLabel->setColor(ccc3(10, 220, 127));
	  	   //this->addChild(passLabel2,1);

		passLabel->setPosition(CCPointMake(winSize.width/2, winSize.height/7));    //CCMenu *menu=CCMenu::create(passLabel,NULL);

	  	   this->addChild(passLabel);
}

bool Option::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    
    CCScene* HelloScene=(CCScene*)HelloWorld::create();
    CCDirector::sharedDirector()->replaceScene(HelloScene);
    
    return true;
}
void Option::makeReturn(void)
{
    
    
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF* reSet=CCLabelTTF::create("O K","Arial",LEVEL_FONT_SIZE);
    CCMenuItemLabel* reSetLabel=CCMenuItemLabel::create(reSet,this,menu_selector(Option::tapReturn));
    reSetLabel->setPosition(ccp(winSize.width*0.5f,winSize.height*0.5f));
    
    CCMenu *menu=CCMenu::create(reSetLabel,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
}

void Option::tapReturn(CCNode *node)
{
    
    CCScene* HelloScene=(CCScene*)HelloWorld::create();
    CCDirector::sharedDirector()->replaceScene(HelloScene);
    
    
}





/*void Option::makeHighScoreLabel()
{
    CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
    int Score_w = _userDef->getIntegerForKey("lv1w", 0);
    
    int Score_l = _userDef->getIntegerForKey("lv1l", 0);
    int Score_draw =_userDef->getIntegerForKey("draw1", 0);
    //以前のハイスコアを表示
    
    CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
    CCString* ScoreString_w = CCString::createWithFormat("%8d", Score_w);
    CCString* ScoreString_l = CCString::createWithFormat("%8d", Score_l);
    CCString* ScoreString_draw = CCString::createWithFormat("%8d", Score_draw);
    
    CCLabelTTF* ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", 32.0f);
    CCLabelTTF* ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", 32.0f);
    CCLabelTTF* ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", 32.0f);
    ScoreLabel_w->setPosition(ccp(bgSize.width * 0.7f, bgSize.height * 0.1f));
    ScoreLabel_l->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.1f));
    ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.9f, bgSize.height * 0.1f));
    //ScoreLabel_w->setTag(score_w1);
    this->addChild(ScoreLabel_w);
    this->addChild(ScoreLabel_l);
    this->addChild(ScoreLabel_draw);
    
    
    //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
    Score_w = _userDef->getIntegerForKey("lv2w", 0);
    
    Score_l = _userDef->getIntegerForKey("lv2l", 0);
    Score_draw =_userDef->getIntegerForKey("draw2", 0);
    //以前のハイスコアを表示
    
    //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
    ScoreString_w = CCString::createWithFormat("%8d", Score_w);
    ScoreString_l = CCString::createWithFormat("%8d", Score_l);
    ScoreString_draw = CCString::createWithFormat("%8d", Score_draw);
    
    ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", 32.0f);
    ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", 32.0f);
    ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", 32.0f);
    ScoreLabel_w->setPosition(ccp(bgSize.width * 0.7f, bgSize.height * 0.12f));
    ScoreLabel_l->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.12f));
    ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.9f, bgSize.height * 0.12f));
    //ScoreLabel_w->setTag(score_w1);
    this->addChild(ScoreLabel_w);
    this->addChild(ScoreLabel_l);
    this->addChild(ScoreLabel_draw);
    
    
    
    //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
    Score_w = _userDef->getIntegerForKey("lv3w", 0);
    
    Score_l = _userDef->getIntegerForKey("lv3l", 0);
    Score_draw =_userDef->getIntegerForKey("draw3", 0);
    //以前のハイスコアを表示
    
    //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
    ScoreString_w = CCString::createWithFormat("%8d", Score_w);
    ScoreString_l = CCString::createWithFormat("%8d", Score_l);
    ScoreString_draw = CCString::createWithFormat("%8d", Score_draw);
    
    ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", 32.0f);
    ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", 32.0f);
    ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", 32.0f);
    ScoreLabel_w->setPosition(ccp(bgSize.width * 0.7f, bgSize.height * 0.13f));
    ScoreLabel_l->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.13f));
    ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.9f, bgSize.height * 0.13f));
    //ScoreLabel_w->setTag(score_w1);
    this->addChild(ScoreLabel_w);
    this->addChild(ScoreLabel_l);
    this->addChild(ScoreLabel_draw);
    
    
    
    //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
    Score_w = _userDef->getIntegerForKey("lv4w", 0);
    
    Score_l = _userDef->getIntegerForKey("lv4l", 0);
    Score_draw =_userDef->getIntegerForKey("draw4", 0);
    //以前のハイスコアを表示
    
    //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
    ScoreString_w = CCString::createWithFormat("%8d", Score_w);
    ScoreString_l = CCString::createWithFormat("%8d", Score_l);
    ScoreString_draw = CCString::createWithFormat("%8d", Score_draw);
    
    ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", 32.0f);
    ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", 32.0f);
    ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", 32.0f);
    ScoreLabel_w->setPosition(ccp(bgSize.width * 0.7f, bgSize.height * 0.14f));
    ScoreLabel_l->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.14f));
    ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.9f, bgSize.height * 0.14f));
    //ScoreLabel_w->setTag(score_w1);
    this->addChild(ScoreLabel_w);
    this->addChild(ScoreLabel_l);
    this->addChild(ScoreLabel_draw);
    
    
    //CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
    Score_w = _userDef->getIntegerForKey("lv5w", 0);
    
    Score_l = _userDef->getIntegerForKey("lv5l", 0);
    Score_draw =_userDef->getIntegerForKey("draw5", 0);
    //以前のハイスコアを表示
    
    //CCSize bgSize = CCDirector::sharedDirector()->getWinSize();
    ScoreString_w = CCString::createWithFormat("%8d", Score_w);
    ScoreString_l = CCString::createWithFormat("%8d", Score_l);
    ScoreString_draw = CCString::createWithFormat("%8d", Score_draw);
    
    ScoreLabel_w = CCLabelTTF::create(ScoreString_w->getCString(), "", 32.0f);
    ScoreLabel_l = CCLabelTTF::create(ScoreString_l->getCString(), "", 32.0f);
    ScoreLabel_draw = CCLabelTTF::create(ScoreString_draw->getCString(), "", 32.0f);
    ScoreLabel_w->setPosition(ccp(bgSize.width * 0.7f, bgSize.height * 0.15f));
    ScoreLabel_l->setPosition(ccp(bgSize.width * 0.8f, bgSize.height * 0.15f));
    ScoreLabel_draw->setPosition(ccp(bgSize.width * 0.9f, bgSize.height * 0.15f));
    //ScoreLabel_w->setTag(score_w1);
    this->addChild(ScoreLabel_w);
    this->addChild(ScoreLabel_l);
    this->addChild(ScoreLabel_draw);
    
}*/