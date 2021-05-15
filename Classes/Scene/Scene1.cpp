#include"scene1.h"
USING_NS_CC;

Scene* scene1::createScene()
{
    return scene1::create();
}

bool scene1::init()
{
    return true;
}

void scene1::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
} 