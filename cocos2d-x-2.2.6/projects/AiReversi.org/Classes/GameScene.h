//
//  GameScene.h
//  Reversi
//
//  Created by 宮下修治 on 2015/05/23.
//
//

#ifndef __Reversi__GameScene__
#define __Reversi__GameScene__

#include "cocos2d.h"
class GameScene:public cocos2d::CCLayer
{

private:
    int Score_w;
    int Score_l;
    int Score_draw;
    // 戻るキー押された時
	void update(void);
	int sekisacom();
	int sekisaman();
	void keyBackClicked();
    void makeBackground();
    void makeCells();
    void cells();
    void BlackWin();
    void WhiteWin();
    void Draw();
    void winf();
    void Com();
    void setData();  // void getTag();
public:
    int c,xp,yp;
    int p;
    void update( float frame );
    void playDroppingSound();
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);
   int showGameevalLabel(void);
    void putCells(int,int);
    void putCells2(int,int);
    void showGameCom(void);
    void putCom(int,int);
    void makePassButton();
    void tapPassButton(CCNode *node);
    void makeRetryButton();
    void tapRetryButton(CCNode *node);
    void tapRePutButton(void);
    void makeRePutButton();
    void showGameScene();
    //void makeHighScoreLabel();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
    const char *score_w1;
    const char *score_l1;
    const char *score_draw1;
};
void Reset(void);
void allReset(int);
#endif /* defined(__Reversi__GameScene__) */
