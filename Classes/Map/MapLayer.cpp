#include"MapLayer.h"


MapLayer* MapLayer::createMapLayer()
{
    auto temp = MapLayer::create();
    temp->retain();
    return temp;
}
bool MapLayer::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto _tileMap = TMXTiledMap::create("playmap2.tmx");              
    _tileMap->setPosition(origin.x, origin.y);
    this->addChild(_tileMap);

    return true;
}