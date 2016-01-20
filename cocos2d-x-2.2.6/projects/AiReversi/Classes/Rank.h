//
//  Rank.h
//  Othello
//
//  Created by 宮下修治 on 2015/07/25.
//
//

#ifndef __Othello__Rank__
#define __Othello__Rank__
#include <stdio.h>

#include "cocos2d.h"


class Rank: public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(Rank);
    //void update( float frame );
private:
    void makeHighScoreLabel();
    void first(void);
    void show(void);
    void keyBackClicked();
    void tapReset(CCNode *node);
    void makeReset(void);//バックキー処理
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
    //virtual void ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
};
#endif