//
//  Settei.cpp
//  Othello
//
//  Created by 宮下修治 on 2015/06/21.
//
//

#include "Settei.h"
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "title.h"
#include "HelloWorldScene.h"
using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;
USING_NS_CC;

CCScene* HelloWorld2::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    //シーン切り替えのトリガーになる"2"のボタン
    //ボタンをクリックすると、HelloWorld2::myCallbackが発動
    CCMenuItemImage *pBtnItem = CCMenuItemImage::create("rtn.png", "rtn.png", this, menu_selector(HelloWorld::myCallback));
    CCMenu* pBtn = CCMenu::create(pBtnItem, NULL);
    pBtn->setPosition(ccp(s.width*.5, s.height*.5));
    this->addChild(pBtn);
    
    return true;
}
