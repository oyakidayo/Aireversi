//
//  title.h
//  Othello
//
//  Created by 宮下修治 on 2015/06/17.
//
//

#ifndef __Othello__title__
#define __Othello__title__

#include "cocos2d.h"
class TitleScene :public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(TitleScene);
    
};

#endif /* defined(__Othello__title__) */
