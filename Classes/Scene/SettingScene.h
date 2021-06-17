#pragma once

#include "cocos2d.h"

class SettingScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void settingBack(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
};

