//
//  Settei2.cpp
//  
//
//  Created by 宮下修治 on 2015/07/06.
//
//

#include "Settei2.h"

#include "HelloWorld2.h"
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "title.h"
#include "HelloWorldScene.h"
using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;
USING_NS_CC;
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
}
void GameScene::makeRePutButton()
    {
        CCSize winSize=CCDirector::sharedDirector()->getWinSize();
        //CCLabelTTF* retryLabel=CCLabelTTF::create("Undo","Arial",28.0);
        CCMenuItemImage* rePutItem=CCMenuItemImage::create("undo.png",
                                                           "undo_pressed.png",
                                                           this,menu_selector(GameScene::tapRePutButton));
        rePutItem->setPosition(ccp((winSize.width-rePutItem->getContentSize().width*0.5)*0.6f,rePutItem->getContentSize().height*0.5));
        
        CCMenu *menu=CCMenu::create(rePutItem,NULL);
        menu->setPosition(CCPointZero);
        this->addChild(menu);
    }
