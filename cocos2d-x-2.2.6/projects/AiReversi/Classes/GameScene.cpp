//
//  GameScene.cpp
//  Reversi
//
//  Created by 宮下修治 on 2015/05/23.
//
//
#define EXTERN
#include "Reversi.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "AppMacros.h"

//#include "title.h"
#include "HelloWorldScene.h"



using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;
//#include "HogeScene.h"
int ban[101];
int pass;
int rep=0;
int turn=0;
int untap;
int endyo;

/*int Score_w1;
int Score_l1;
int Score_draw1;
int Score_w2;
int Score_l2;
int Score_draw2;
int Score_w3;
int Score_l3;
int Score_draw3;
int Score_w4;
int Score_l4;
int Score_draw4;
int Score_w5;
int Score_l5;
int Score_draw5;
int lv;*/
CCScene* GameScene::scene()
{
    CCScene* scene= CCScene::create();
    GameScene* layer= GameScene::create();
    scene->addChild(layer);
        return scene;
}

bool GameScene::init()
{
    int put,tmp,ixp,iyp,a;
    
    if(!CCLayer::init())
    {
        return false;
    }
    /*const char *score_w1="lv1w";
    const char *score_l1="lv1l";
    const char *score_draw1="lv1draw";*/
    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic("June.mp3", true);
   endyo=0;
    //showGameevalini();
    //SimpleAudioEngine::sharedEngine()->setEffectsVolume(1);

    this->setKeypadEnabled(true);
    

   //teban=-1;
    //initi();
    //initi();
    //put=reversi();
    o=0;
    untap=0;
    srand((unsigned)time(NULL));
    if(te==1) {initig();o=reversi();putCom(o%10,o/10);SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");}
    else if(te==-1){initi();}
    for(i=0;i<=100;i++)
                              undo[i]=ban[i];
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
    showGameevalini();
    makeBackground();
    makeCells();
    makeRetryButton();
    makeRePutButton();
    //showGameevalini();
    showGameScene();
    
    CCLog("MAN:%d",turn);
    //showGameCom();
    //makePassButton();
    cells();
    //setData();
   // makeHighScoreLabel();
    for(int x=1;x<=8;x++)
                       for(int y=1;y<=8;y++){
                       	                           if(check(x+y*10,MAN,OFF)>0)putCells(x,9-y);

                       }

    //if(te==1)putCom(o%10,9-o/10);
    this->scheduleUpdate();

    return true;
}


void GameScene::makeBackground()
{
       CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    //背景を生成
    
    CCSprite* pBG=CCSprite::create("board.png");
    pBG->setPosition(ccp(winSize.width*0.5,winSize.height*0.5));
    this->addChild(pBG);

}
void GameScene::makeCells()
{
    int xp,yp;
    int co,ma;
    co=sekisacom();
    ma=sekisaman();
    makeBackground();
    makeRetryButton();
    makeRePutButton();
    //showGameevalini();
    //showGameevalini();
    
    if (eval_score>=4000 || (eval_score>54 && co+ma>=50))evalFaceMajorWin();
    else if (eval_score<=-4000 || (eval_score<-54 && co+ma>=50))evalFaceMajorLose();
    else if (eval_score>=2000 || (eval_score>20 && co+ma>=50))evalFaceWin();
    else if (eval_score<=-2000 || (eval_score<-20 && co+ma>=50))evalFaceLose();
    else if (eval_score>=500 || (eval_score>=1 && co+ma>=50))evalFaceMinorWin();
    else if (eval_score<=-500 || (eval_score<=-1 && co+ma>=50))evalFaceMinorLose();
    else if ((eval_score<500 && eval_score>-500))evalFaceNormal();
CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    for(yp=1;yp<=8;yp++)
        for(xp=1;xp<=8;xp++){
            
            CCSprite* pCells=CCSprite::create("cell.png");
            
            CCSize cellSize=pCells->getContentSize();
            pCells->setPosition(ccp(winSize.width*0.5+cellSize.width/2+winSize.width/8*(xp-5)+4,
                                   winSize.height*0.5+cellSize.height/2+winSize.width/8*(yp-5)+4));
            //reversi();
           //pCell->setTag(xp+yp*10);
            pCells->setScale(0.9f);
            this->addChild(pCells);
           num=1;
            for(int x=1;x<=8;x++)
                                   for(int y=1;y<=8;y++)
                                       if(check(x+y*10,MAN,OFF)>0){putCells2(x,9-y);putCells(x,9-y);}
            

        }
}
void GameScene::cells()
{
    
    
    int x,y;
    
    //画面サイズを取得
   //駒をおく
    


    reversi_put(ban);
    // CCRenderTexture生成
   
   
    
    /*CCRenderTexture* pRenderTexture = CCRenderTexture::create(winSize.width, winSize.height);
    pRenderTexture->setPosition(ccp(winSize.width*0.5,*/
     for(y=1;y<=8;y++)
        for(x=1;x<=8;x++){
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
            if(ban[x+(9-y)*10]==-te){
                CCSprite* pCellBlack=CCSprite::create("white.png");
            CCSize cellSize=pCellBlack->getContentSize();
            pCellBlack->setPosition(ccp(winSize.width*0.5+cellSize.width/2+winSize.width/8*(x-5)-winSize.width*0.01,
                                            winSize.height*0.5+cellSize.height/2+winSize.width/8*(y-5)-winSize.width*0.01));
            
            pCellBlack->setScale(0.8f);
            this->addChild(pCellBlack);
            

            
           

            
            
            }
           else if(ban[x+(9-y)*10]==te){
                CCSprite* pCellWhite=CCSprite::create("black.png");
                                CCSize cellSize=pCellWhite->getContentSize();
                pCellWhite->setPosition(ccp(winSize.width*0.5+cellSize.width/2+winSize.width/8*(x-5)-winSize.width*0.01,
                                          winSize.height*0.5+cellSize.height/2+winSize.width/8*(y-5)-winSize.width*0.01));
   
            pCellWhite->setScale(0.8f);
        
            this->addChild(pCellWhite);
            }
        
        }
  /*
    for(int x=1;x<=8;x++)
        for(int y=1;y<=8;y++)
            if(check(x+y*10,MAN,OFF)>0){putCells(x,y-9);}
    
*/
 /*    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
     CCSprite* pCellBlack=CCSprite::create("black.png");
     CCSize cellSizeb=pCellBlack->getContentSize();
     pCellBlack->setPosition(ccp(winSize.width*0.5+cellSizeb.width/2+winSize.width/8*(2-5)-6,
                                                 winSize.height*0.5+cellSizeb.height/2+winSize.width/8*(9-5)-6));

     pCellBlack->setScale(0.9);

     this->addChild(pCellBlack);
     CCSprite* pCellWhite=CCSprite::create("white.png");
     CCSize cellSizew=pCellWhite->getContentSize();
     pCellWhite->setPosition(ccp(winSize.width*0.5+cellSizew.width/2+winSize.width/8*(7-5)-6,
                               winSize.height*0.5+cellSizew.height/2+winSize.width/8*(9-5)-6));
     pCellWhite->setScale(0.8);
     this->addChild(pCellWhite);*/
    if(ban[o]!=0)putCom(o%10,9-o/10);
     for(int x=1;x<=8;x++)
                                                                       for(int y=1;y<=8;y++)
                                                                           if(check(x+y*10,MAN,OFF)>0){putCells2(x,9-y);putCells(x,9-y);}



}

bool GameScene::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{

   // int comt=0;
  	//					int mant=0;
  	//for (int x=1;x<9;x++)
  	//for(int y=1;y<9;y++){
  		//comt+=check(x+y*10,COM,OFF);
  		//mant+=check(x+y*10,MAN,OFF);
  //	}
  	//if((comt==0)&&(mant==0)){pass=2;winf();}
  	//if(mant==0){makePassButton();}
  	//if(comt+mant==64)winf();
    return true;
}

void GameScene::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)
{

    int n,tmp,a,put,ixp,iyp,xx,yy,kSize,x,y;
    n=1;
    untap=0;

    CCDirector* pDirector=CCDirector::sharedDirector();
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCPoint touchPoint=pDirector->convertToGL(pTouch->getLocationInView());
    CCLog("x: %f,y:%f",touchPoint.x,touchPoint.y);
    //putCom(o%10,9-o/10);
    kSize=winSize.width/8;
    xx=touchPoint.x/kSize;
    yy=((touchPoint.y-(winSize.height-winSize.width)/2))/kSize;
    printf("xx,yy : %d,%d",xx,yy);
 CCLog("x,y : %f%f",xx,yy);
    		if(yy<8&yy>=0){

    			p=check(xx+1+(8-yy)*10,MAN,OFF);
    			if(p>0)
    			for(int i=0;i<100;i++)
         	              	                	undo[i]=ban[i];
			    p=input(xx+1,8-yy);
                printf("x,y : %d,%d",xx,yy);
                int comt=0;
               	int mant=0;
                           	for (int x=1;x<9;x++)
                           	for(int y=1;y<9;y++){
                           		comt+=check(x+y*10,COM,OFF);
                           		mant+=check(x+y*10,MAN,OFF);
                           	}
                           	if((comt==0)&&(mant==0)){pass=2;winf();}
                            else if(mant==0){
                                int co;
                                co=sekisacom();
                                int ma;
                                ma=sekisaman();
                                if((ma+co)==64){pass=2;winf();return;}
                                else if((ma+co)<64){ makePassButton();}
                                
                            }
                                    

                if(p>0){
                    SimpleAudioEngine::sharedEngine()->playEffect("sound.mp3");

                p=0;
                
                tmp=reversi();
                    o=tmp;
                    ixp=tmp%10;
                    iyp=tmp/10;
                    a=check(tmp, COM, ON);
                    ban[tmp]=COM;
                    makeCells();
                    cells();
                    putCom(tmp%10,9-tmp/10);
                    SimpleAudioEngine::sharedEngine()->playEffect("sound.mp3");
                }
                comt=0;
                                  	 mant=0;
                                  	for (int x1=1;x1<9;x1++)
                                  	for(int y1=1;y1<9;y1++){
                                  		comt+=check(x1+y1*10,COM,OFF);
                                  		mant+=check(x1+y1*10,MAN,OFF);
                                  	}
                                      		if((comt==0)&&(mant==0)){pass=2;winf();return;}
                                      		if(mant==0){
                                                                int co;
              													 co=sekisacom();
                                      	                  		 int ma;
              													 ma=sekisaman();
                                      	                  		if((ma+co)==64){pass=2;winf();return;}
                                                                else if((ma+co)<64){ makePassButton();}

                                      	                  	}

                                            else if (p==0){makePassButton();}

               else if(p==-1){

                   makeCells();


                 makePassButton();
                 if (p==-1)
                    //reversi();
                     cells();
                    putCom(ixp,9-iyp);
                    for(int x=1;x<=8;x++)
                                                 for(int y=1;y<=8;y++)
                                                     if(check(x+y*10,MAN,OFF)>0){putCells2(x,9-y);putCells(x,9-y);}

                return;
               }
             
            }

    makeCells();
    if(!passf())makePassButton();
            if(!passf())makePassButton();
                if(!passf())makePassButton();
                if(!passf())makePassButton();

    
                    num=1;

   
    cells();

    //this->scheduleUpdate();
    return;
    
    

}
    


void GameScene::makeRetryButton()
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    //CCLabelTTF* retryLabel=CCLabelTTF::create("Retry","Arial",28.0);
    CCMenuItemImage* retryItem=CCMenuItemImage::create("retry.png",
                                                         "retry_pressed.png",
                                                       this,menu_selector(GameScene::tapRetryButton));
    retryItem->setPosition(ccp(winSize.width-retryItem->getContentSize().width*0.5,retryItem->getContentSize().height*0.5));
    
    CCMenu *menu=CCMenu::create(retryItem,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
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
void GameScene::tapRetryButton(CCNode *node)
{


	    //SimpleAudioEngine::sharedEngine()->playEffect("osero.mp3");

    CCScene* gameScene=((CCScene*)HelloWorld::create());
    CCDirector::sharedDirector()->replaceScene(gameScene);
}
void GameScene::makePassButton()
{
    int co,ma;
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    //CCLabelTTF* passLabel=CCLabelTTF::create("Pass","Arial",28.0);
    CCMenuItemImage* passItem=CCMenuItemImage::create("pass.png",
                                                        "pass_pressed.png",
                                                       this,menu_selector(GameScene::tapPassButton));
    passItem->setPosition(ccp((winSize.width-passItem->getContentSize().width*0.5)*0.2f,passItem->getContentSize().height*0.5));
    
    CCMenu *menu=CCMenu::create(passItem,NULL);
    menu->setPosition(CCPointZero);
    
    this->addChild(menu);
   }
void GameScene::tapPassButton(CCNode *node)
{
    int comt=0;
    int mant=0;
    int co,ma;
    for (int x=1;x<9;x++)
        for(int y=1;y<9;y++){
            comt+=check(x+y*10,COM,OFF);
            mant+=check(x+y*10,MAN,OFF);
        }
    if(mant!=0)return;
    o=reversi();




   SimpleAudioEngine::sharedEngine()->playEffect("sound.mp3");
    makeBackground();
    makeRePutButton();
    makeRetryButton();
    cells();
    co=sekisacom();
    ma=sekisaman();
    if (eval_score>=4000 || (eval_score>54 && co+ma>=50))evalFaceMajorWin();
    else if (eval_score<=-4000 || (eval_score<-54 && co+ma>=50))evalFaceMajorLose();
    else if (eval_score>=2000 || (eval_score>20 && co+ma>=50))evalFaceWin();
    else if (eval_score<=-2000 || (eval_score<-20 && co+ma>=50))evalFaceLose();
    else if (eval_score>=500 || (eval_score>=1 && co+ma>=50))evalFaceMinorWin();
    else if (eval_score<=-500 || (eval_score<=-1 && co+ma>=50))evalFaceMinorLose();
    else if ((eval_score<500 && eval_score>-500))evalFaceNormal();
    
    comt=0;
    mant=0;
                  	for (int x=1;x<9;x++)
                  	for(int y=1;y<9;y++){
                  		comt+=check(x+y*10,COM,OFF);
                  		mant+=check(x+y*10,MAN,OFF);
                  	}
                  	if(mant==0)makePassButton();
                    
                      co=sekisacom();
                      ma=sekisaman();
    if(co+ma==64){pass=2;winf();}
    
    return;
}

void GameScene::putCells(int xp,int yp)
{

   CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite* pCell=CCSprite::create("ten.png");
    CCSize cellSize=pCell->getContentSize();
    pCell->setPosition(ccp(winSize.width*0.5+cellSize.width/2+winSize.width/8*(xp-5)+winSize.width*0.004,
                           winSize.height*0.5+cellSize.height/2+winSize.width/8*(yp-5)+winSize.width*0.004));
    
    
   
    pCell->setScale(0.8);
    if(hint==0)return;
    this->addChild(pCell);


    
    
    
}
void GameScene::putCells2(int xp,int yp)
{
   
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite* pCell2=CCSprite::create("ten.png");
    
    pCell2->setPosition(ccp(winSize.width*0.5+winSize.width/8*(xp-5),
                           winSize.height*0.5+winSize.width/8*(yp-5)));
    
    
    pCell2->setTag(num);
    printf("%d¥n",num);
    point[num++]=xp+(9-yp)*10;
   
    CCSize cellSize=pCell2->getContentSize();
    
    pCell2->setOpacity(0);
    
    /*this->addChild(pCell2,2);*/
    
    
    
}
void GameScene::putCom(int xp,int yp)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite* pCellBlack=CCSprite::create("put.png");
    CCSize cellSize=pCellBlack->getContentSize();
    pCellBlack->setPosition(ccp(winSize.width*0.5+cellSize.width/2+winSize.width/8*(xp-5)+winSize.width*0.004
                                ,
                                winSize.height*0.5+cellSize.height/2+winSize.width/8*(yp-5)+winSize.width*0.004));

    if(untap==3){rep=0;return;}
    pCellBlack->setScale(0.8);
    this->addChild(pCellBlack,0);
}
void GameScene::tapRePutButton(void)
{

for (int i=11;i<89;i++)
	ban[i]=undo[i];
    makeBackground();
    makeRetryButton();
    makeRePutButton();
    makeCells();
    //untap=3;
    cells();
    //untap=0;
    /*for(int x=1;x<=8;x++)
        for(int y=1;y<=8;y++)
            if(check(x+y*10,MAN,OFF)>0){putCells2(x,9-y);}
    */

    return;
   }
int GameScene::showGameevalini(void)
{
   
    
    //showGameScene();
    CCLOG("%d eval",eval_score);
    //CCString *score = CCString::createWithFormat("EVAL SCORE" ,"arial",48);

CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    
 CCLabelTTF* Label = CCLabelTTF::create("EVAL", "arial", LEVEL_FONT_SIZE);
    

    Label->setPosition(ccp(winSize.width*0.35,winSize.height*0.14));
    Label->setTag(1);
    this->addChild(Label,1);
 
}
int GameScene::showGameevalLabel(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF* evalLabel=(CCLabelTTF*)this->getChildByTag(1);
    
    CCString *score=CCString::createWithFormat("%8d",eval_score);
   evalLabel->setString(score->getCString());
   evalLabel->setPosition(ccp(winSize.width*0.7,winSize.height*0.14));
}
void GameScene::keyBackClicked() {
    
   CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    //バックキー処理
}
void GameScene::showGameScene(void)
{
    

    
    return;
}
int passf(void)
{
    int put;
    int a=0;
    for (int i=1;i<9;i++)
        for(int j=1;j<9;j++){
            put=i+j*10;
            a+=check(put,MAN,OFF);
        }
            return a;
}
void GameScene::update(float frame)
{

    int ev,co,ma;
	char *pman,*pcom;
    char sc[]="COM",sm[]="YOU";

    if(te==1){co=sekisacom();pman=sm;pcom=sc;}
    else{co=sekisaman();pcom=sm;pman=sc;}
    {showGameScene();}

const int tagGametimeLabel=101;
	 //CCString *scoreCom = CCString::createWithFormat("%s",pcom);
	
    CCString *score = CCString::createWithFormat("%i",co);
	 CCLabelTTF* passLabel = (CCLabelTTF*)this->getChildByTag(tagGametimeLabel);
	   
	// passLabel->setString(score->getCString());
	if(passLabel)
	   {
		   passLabel->setString(score->getCString());
	   }
    else
    {
	  
          if(te==COM){
              
          CCSize winSize=CCDirector::sharedDirector()->getWinSize();
		   //CCLabelTTF* passLabelCom=CCLabelTTF::create(scoreCom->getCString(),"Arial",26.0);
		   //passLabelCom->setPosition(CCPointMake(winSize.width*0.192, winSize.height/2+winSize.width/8*5-40));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
          CCSprite* pCell=CCSprite::create("black_com.png");
         // CCSprite* pCelly=CCSprite::create("black_you.png");
          passLabel=CCLabelTTF::create(score->getCString(),"Arial",LEVEL_FONT_SIZE);
		   passLabel->setPosition(CCPointMake(winSize.width*0.3, winSize.height/2+winSize.width/8*(4.5)));
	   //menu->setPosition(CCPointZero);
          CCSize cellSizeb=pCell->getContentSize();
          pCell->setPosition(ccp(winSize.width*0.5+cellSizeb.width/2+winSize.width/8*(2-5),
                                      winSize.height*0.5+cellSizeb.height/2+winSize.width/8*(9-5)));
          
         // pCell->setScale(0.9);
          
          
	   //this->addChild(passLabel2,1);
	   passLabel->setTag(tagGametimeLabel);
	   this->addChild(passLabel,1);
	   this->addChild(pCell,1);
        //else if(te==COM)this->addChild(pCelly,1);
	  }
          else if(te==MAN){
              
              CCSize winSize=CCDirector::sharedDirector()->getWinSize();
              //CCLabelTTF* passLabelCom=CCLabelTTF::create(scoreCom->getCString(),"Arial",26.0);
              //passLabelCom->setPosition(CCPointMake(winSize.width*0.192, winSize.height/2+winSize.width/8*5-40));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
              CCSprite* pCell=CCSprite::create("black_you.png");
              // CCSprite* pCelly=CCSprite::create("black_you.png");
              passLabel=CCLabelTTF::create(score->getCString(),"Arial",LEVEL_FONT_SIZE);
              passLabel->setPosition(CCPointMake(winSize.width*0.3, winSize.height/2+winSize.width/8*(4.5)));              //menu->setPosition(CCPointZero);
              CCSize cellSizeb=pCell->getContentSize();
              pCell->setPosition(ccp(winSize.width*0.5+cellSizeb.width/2+winSize.width/8*(2-5),
                                     winSize.height*0.5+cellSizeb.height/2+winSize.width/8*(9-5)));
              
              //
              
              
              //this->addChild(passLabel2,1);
              passLabel->setTag(tagGametimeLabel);
              this->addChild(passLabel,1);
              this->addChild(pCell,1);
    
          }
    }
	  if(te==1){ma=sekisaman();}
	  else{ma=sekisacom();}
	   const int tagGametimeLabelman=102;
	   	 CCString *scorem= CCString::createWithFormat("%i",ma);
	   	CCString *scoremMan= CCString::createWithFormat("%s",pman);
	   	CCLabelTTF* passLabelm = (CCLabelTTF*)this->getChildByTag(tagGametimeLabelman);
	   	 
	   	   if(passLabelm)
	   	   {
	   		   passLabelm->setString(scorem->getCString());
	   	   }
	   	   else
	   	  {
              if(te==COM){
                  
              
	   		   CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	   		    CCSprite* pCell=CCSprite::create("white_you.png");
                  passLabelm=CCLabelTTF::create(scorem->getCString(),"Arial",LEVEL_FONT_SIZE);
	   		   passLabelm->setPosition(CCPointMake(winSize.width*0.7, winSize.height/2+winSize.width/8*(4.5)));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
                  CCSize cellSizeb=pCell->getContentSize();
                  pCell->setPosition(ccp(winSize.width*0.5+cellSizeb.width/2+winSize.width/8*(7-5),
                                         winSize.height*0.5+cellSizeb.height/2+winSize.width/8*(9-5)));
                  
	   	   //menu->setPosition(CCPointZero);

	   	   //this->addChild(passLabel2,1);
	   	   passLabelm->setTag(tagGametimeLabelman);
	   	   //passLabelmMan->setColor(ccc3(0,0,0));
	   	   this->addChild(passLabelm,1);
	   	   this->addChild(pCell,1);
	   	  }
              else if(te==MAN){
                  CCSize winSize=CCDirector::sharedDirector()->getWinSize();
                  CCSprite* pCell=CCSprite::create("white_com.png");
                  passLabelm=CCLabelTTF::create(scorem->getCString(),"Arial",LEVEL_FONT_SIZE);
                  passLabelm->setPosition(CCPointMake(winSize.width*0.7, winSize.height/2+winSize.width/8*(4.5)));    //CCMenu *menu=CCMenu::create(passLabel,NULL);
                  CCSize cellSizeb=pCell->getContentSize();
                  pCell->setPosition(ccp(winSize.width*0.5+cellSizeb.width/2+winSize.width/8*(7-5),
                                         winSize.height*0.5+cellSizeb.height/2+winSize.width/8*(9-5)));
                  

                  //menu->setPosition(CCPointZero);
                  
                  //this->addChild(passLabel2,1);
                  passLabelm->setTag(tagGametimeLabelman);
                  //passLabelmMan->setColor(ccc3(0,0,0));
                  this->addChild(passLabelm,1);
                  this->addChild(pCell,1);
                  
              }
          }
}


int GameScene::sekisacom()
{

        int co=0,x,y;
    for(y=1;y<=8;y++)
        for(x=1;x<=8;x++){

   /* if(y==22 || y==72 || y==27 || y==77)continue;*/
            if(ban[x+y*10]==COM){
            co++;
            }
        }
                return (co);
}
int GameScene::sekisaman()
{
        int ma=0,x,y;

    for(y=1;y<=8;y++)
        for(x=1;x<=8;x++){

   /* if(y==22 || y==72 || y==27 || y==77)continue;*/
         if(ban[x+y*10]==MAN){
            ma++;
        }
        }
                return (ma);
}
void GameScene::BlackWin()
{
	 CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	    CCSprite* pCellBlack=CCSprite::create("blackw.png");

	    pCellBlack->setPosition(ccp(winSize.width*0.5,winSize.height*0.5));



	      this->addChild(pCellBlack,1);

}
void GameScene::WhiteWin()
{
	 CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	    CCSprite* pCellWhite=CCSprite::create("whitew.png");

	    pCellWhite->setPosition(ccp(winSize.width*0.5,winSize.height*0.5));



	      this->addChild(pCellWhite,1);

}
void GameScene::Draw()
{
	 CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	    CCSprite* pCellWhite=CCSprite::create("draw.png");

	    pCellWhite->setPosition(ccp(winSize.width*0.5,winSize.height*0.5));



	      this->addChild(pCellWhite,1);

}
void GameScene::winf()
{
	int x,y;

    com=0;man=0;
    if(endyo==1)return;
	                for(x=1;x<9;x++)
	                	for(y=1;y<9;y++){
	                		if (ban[x+y*10]==COM)com++;
	                		if (ban[x+y*10]==MAN)man++;
	                	}
	                if(te==COM)
	                {
                        if (com==0){WhiteWin();Score_w=1;}
                       else if (man==0){BlackWin();Score_l=1;}
                    
                        else if
                        
                    (((pass==2)||(man+com==64))&&(man>com)){WhiteWin();Score_w=1;}
                    else if (((pass==2)||(man+com==64))&&(man<com)){BlackWin();Score_l=1;}
                    }
    
	                else if(te==MAN){
                        if (com==0){BlackWin();Score_w=1;}
                         else if (man==0){WhiteWin();Score_l=1;}
                    
                    else if (((pass==2)||(man+com==64))&&(man<com)){WhiteWin();Score_l=1;}
                    
                    else if (((pass==2)||(man+com==64))&&(man>com)){BlackWin();Score_w=1;}
                    }

                    if(((pass==2)||(man+com==64))&&(man==com)){Draw();Score_draw=1;}
	               if((com+man==64)||(com==0)||(man==0)){
	            	  for(int i=0;i<100;i++)
	                	undo[i]=ban[i];
	               }
	               if(pass==2){
	              	            	   for(int i=0;i<100;i++)
	              	                	undo[i]=ban[i];
	               }

	              endyo=1;

//void GameScene::ScoreWrite(int Score_w,int Score_l,int Score_draw){

    if (lv==1){Score_w1+=Score_w;Score_l1+=Score_l;Score_draw1+=Score_draw;}
    else if (lv==2){Score_w2+=Score_w;Score_l2+=Score_l;Score_draw2+=Score_draw;}
    else if (lv==3){Score_w3+=Score_w;Score_l3+=Score_l;Score_draw3+=Score_draw;}
    else if (lv==4){Score_w4+=Score_w;Score_l4+=Score_l;Score_draw4+=Score_draw;}
    else if (lv==5){Score_w5+=Score_w;Score_l5+=Score_l;Score_draw5+=Score_draw;}
    CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();

    if (lv==1)
    {
       _userDef->setIntegerForKey("lv1w",Score_w1);
       _userDef->flush();
        _userDef->setIntegerForKey("lv1l",Score_l1);
      _userDef->flush();
        _userDef->setIntegerForKey("draw1",Score_draw1);
       _userDef->flush();//保存
    }
    else if (lv==2)
    {
        _userDef->setIntegerForKey("lv2w",Score_w2);
        _userDef->flush();
        _userDef->setIntegerForKey("lv2l",Score_l2);
        _userDef->flush();
        _userDef->setIntegerForKey("draw2",Score_draw2);
        _userDef->flush();//保存
    }
    else if (lv==3)
    {
        _userDef->setIntegerForKey("lv3w",Score_w3);
        _userDef->flush();
        _userDef->setIntegerForKey("lv3l",Score_l3);
        _userDef->flush();
        _userDef->setIntegerForKey("draw3",Score_draw3);
        _userDef->flush();//保存
    }
    else if (lv==4)
    {
        _userDef->setIntegerForKey("lv4w",Score_w4);
        _userDef->flush();
        _userDef->setIntegerForKey("lv4l",Score_l4);
        _userDef->flush();
        _userDef->setIntegerForKey("draw4",Score_draw4);
        _userDef->flush();//保存
    }
    else if (lv==5)
    {
        _userDef->setIntegerForKey("lv5w",Score_w5);
        _userDef->flush();
        _userDef->setIntegerForKey("lv5l",Score_l5);
        _userDef->flush();
        _userDef->setIntegerForKey("draw5",Score_draw5);
        _userDef->flush();//保存
    }

}
void allReset(int lv)
{
    CCUserDefault *_userDef = CCUserDefault::sharedUserDefault();
    if (lv==1 )
    {
        _userDef->setIntegerForKey("lv1w",0);
       // _userDef->flush();
        _userDef->setIntegerForKey("lv1l",0);
        //_userDef->flush();
        _userDef->setIntegerForKey("draw1",0);
        _userDef->flush();//保存
    }
    if (lv==2)
    {
        _userDef->setIntegerForKey("lv2w",0);
        _userDef->flush();
        _userDef->setIntegerForKey("lv2l",0);
        _userDef->flush();
        _userDef->setIntegerForKey("draw2",0);
        _userDef->flush();//保存
    }
    if (lv==3)
    {
        _userDef->setIntegerForKey("lv3w",0);
        _userDef->flush();
        _userDef->setIntegerForKey("lv3l",0);
        _userDef->flush();
        _userDef->setIntegerForKey("draw3",0);
        _userDef->flush();//保存
    }
    if (lv==4)
    {
        _userDef->setIntegerForKey("lv4w",0);
        _userDef->flush();
        _userDef->setIntegerForKey("lv4l",0);
        _userDef->flush();
        _userDef->setIntegerForKey("draw4",0);
        _userDef->flush();//保存
    }
    if (lv==5)
    {
        _userDef->setIntegerForKey("lv5w",0);
        _userDef->flush();
        _userDef->setIntegerForKey("lv5l",0);
        _userDef->flush();
        _userDef->setIntegerForKey("draw5",0);
        _userDef->flush();//保存
    }
    
}
void GameScene::evalFaceNormal(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food=CCSprite::create("mark_face_jito.png",CCRectMake(0, 0, 500,500));
    food->setScale(0.2f);
    food->setPosition(ccp(winSize.width*0.7,winSize.height*0.126));
    this->addChild(food);
}

void GameScene::evalFaceLose(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food2=CCSprite::create("mark_face_cry.png",CCRectMake(0, 0, 500,500));
    food2->setScale(0.2f);
    food2->setPosition(ccp(winSize.width*0.7,winSize.height*0.126));
    this->addChild(food2);
}
void GameScene::evalFaceWin(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food3=CCSprite::create("mark_face_laugh.png",CCRectMake(0, 0, 500,500));
    food3->setScale(0.2f);
    food3->setPosition(ccp(winSize.width*0.7,winSize.height*0.126));
    this->addChild(food3);
}
void GameScene::evalFaceMinorWin(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food4=CCSprite::create("mark_face_smile.png",CCRectMake(0, 0,500,500));
    food4->setScale(0.2f);
    food4->setPosition(ccp(winSize.width*0.7,winSize.height*0.126));
    this->addChild(food4);
}
void GameScene::evalFaceMinorLose(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food5=CCSprite::create("mark_face_ase.png",CCRectMake(0, 0,500,500));
    food5->setScale(0.2f);
    food5->setPosition(ccp(winSize.width*0.7,winSize.height*0.1266));
    this->addChild(food5);
}
void GameScene::evalFaceMajorWin(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food6=CCSprite::create("mark_face_hehe.png",CCRectMake(0, 0, 500,500));
    food6->setScale(0.2f);
    food6->setPosition(ccp(winSize.width*0.7,winSize.height*0.126));
    this->addChild(food6);
}
void GameScene::evalFaceMajorLose(void)
{
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *food7=CCSprite::create("mark_face_angry.png",CCRectMake(0, 0,500,500));
    food7->setScale(0.2f);
    food7->setPosition(ccp(winSize.width*0.7,winSize.height*0.126));
    this->addChild(food7);
}
