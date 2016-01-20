#ifndef __Othello__Option__
#define __Othello__Option__


#include "cocos2d.h"
class Option : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(Option);
    //void update( float frame );
private:
     void makeHighScoreLabel();
    void keyBackClicked(void);
    void Show();
    void makeReturn(void);
    void tapReturn(CCNode *node);
	//void first(void);
    //void level(void);
   // void keyBackClicked(void);
    void message(CCObject* pSender);
    void message2(CCObject* pSender);
    void message3(CCObject* pSender);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
};
#endif
