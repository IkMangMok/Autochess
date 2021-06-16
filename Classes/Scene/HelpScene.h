#pragma once
#include "cocos2d.h"

USING_NS_CC;



class HelpScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void helpBack(cocos2d::Ref* pSender);
    // implement the "static create()" method manually

    CREATE_FUNC(HelpScene);
    
}

