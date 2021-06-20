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

IntMap MapIntReturn(Point point)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //遍历地图，判断是否在格子内
                + (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
                return IntMap(i, j);    //返回离散型坐标
        }
    }
    return IntMap(-1, -1);
}
int a[65];

void MapLayer::update(float dt)
{
   
}
Point mapPosition[8][10];
bool ChessExist[8][10] = {};