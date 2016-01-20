//
//  title.cpp
//  Othello
//
//  Created by 宮下修治 on 2015/06/17.
//
//
#include "title.h"
#include "GameScene.h"
//#inclede "Animation.h"
USING_NS_CC;
CCScene* TitleScene::scene()
{
    CCScene* scene= CCScene::create();
    TitleScene* layer=TitleScene::create();
    scene->addChild(layer);
    return scene;
}
bool TitleScene::init()
{
    if(!CCLayer::init())
        return false;
    CCSize size= CCDirector::sharedDirector()->getWinSize();
    CCSprite* pBG=CCSprite::create("bg.png");
    pBG->setPosition(ccp(size.width*0.5,size.height*0.5));
    this->addChild(pBG);
}

/*void TitleScene::menuStartCallback(CCObject* pSender)
{
    CCScene* scene=GameScene();
    CCtranstionJumpZoom* tran=CCCtransitionJumpZoom::create(1,scene);
    CCDirector::sharedDirector()->replaceScene(tran);
    
}*/