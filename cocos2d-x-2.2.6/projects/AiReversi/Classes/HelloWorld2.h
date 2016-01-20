//
//  Settei.h
//  Othello
//
//  Created by 宮下修治 on 2015/06/21.
//
//

#ifndef __Othello__Settei__
#define __Othello__Settei__


#include "cocos2d.h"





class Settei : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(Settei);
    void update( float frame );
private:

	void first(void);
    void level(void);
    void keyBackClicked(void);

	void myCallback1(CCObject* pSender);
    void myCallback2(CCObject* pSender);
    void myCallback3(CCObject* pSender);
    void myCallback4(CCObject* pSender);
    void myCallback5(CCObject* pSender);
    //void myCallback6(CCObject* pSender);
    void myCallback7(CCObject* pSender);
    void myCallback8(CCObject* pSender);
};

#endif /* defined(__Othello__Settei__) */
