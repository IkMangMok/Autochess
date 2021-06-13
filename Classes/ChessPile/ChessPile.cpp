#include"ChessPile.h"

ChessPile::ChessPile()
{
	
}
ChessPile* ChessPile::createChessPile()
{
	auto temp = ChessPile::create();
    
	temp->retain();
	return temp;
}



Chess* ChessPile::ChessCreate(int i)   //生成不同的棋子
{
    switch (i)
    {
        case walnut:
            return WalNut::createChess();
            player1data.chessnumber[walnut]++;
            break;
        case pealauncher:
            return PeaShooter::createChess();
            player1data.chessnumber[walnut]++;
            break;
        case mushroom:
            return MushRoom::createChess();
            break;
        case sunflower:
            return SunFlower::createChess();
            break;
        case cactus:
            return Cactus::createChess();
            break;
        case cherrybomb:
            return CherryBomb::createChess();
            break;
        case cornshooter:
            return CornShooter::createChess();
            break;
        case cabbagepult:
            return CabbagePult::createChess();
            break;
    }
}

bool ChessPile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

    srand(time(NULL));
    openChessStore();
	
	return true;
}
bool ChessPile::ifCanBuy(int m)
{
    int sum = 0;
    if (Used[m].money > player1data.Gold)
    {
        auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        sum += ChessExist[i][0];
    }
    if (sum == 8)
    {
        auto label = Label::createWithTTF("Prepare Zone is Full!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return 0;
    }
    else
        return 1;
}
void ChessPile::openChessStore()
{
    auto open = MenuItemImage::create("Back_test.png", "Back_test.png", CC_CALLBACK_1(ChessPile::chessStore, this));
    auto Open = Menu::create(open, NULL);
    Open->setPosition(1530, 850);
    this->addChild(Open, 1);
}

void ChessPile::closeChessStore()
{
    auto close = MenuItemImage::create("close_store.png", "close_store.png", CC_CALLBACK_1(ChessPile::closeLayer, this));
    auto Close = Menu::create(close, NULL);
    s_layer->addChild(Close, 1);
    Close->setPosition(155, 490);
}

void ChessPile::closeLayer(cocos2d::Ref* pSender)
{
    s_layer->setPosition(10000, 10000);
}

 void ChessPile::storeChess(int i)
{
    auto sprite1 = Sprite::create(Used[i].picture_name);
    s_layer->addChild(sprite1);
    sprite1->setPosition(40, 430 - 120 * i);

    auto label1 = Label::createWithTTF(chessValue[Used[i].money - 1], "fonts/Marker Felt.ttf", 24);
    label1->setPosition(130, 430 - 120 * i);
    s_layer->addChild(label1);

}
 void ChessPile::cover(float x, float y)
 {
     auto cover = Sprite::create("cover_bg.png");   
     s_layer->addChild(cover);
     cover->setPosition(x, y);
 }

void ChessPile::buy1(cocos2d::Ref* pSender)         //金币问题在此layer中解决
{
   // x = x + 90;
    
    if (Used[0].buy == false && ifCanBuy(0))
    {
        auto sprite = ChessCreate(Used[0].address);

        Used[0].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        ccArrayAppendObject(player1data.PlayerArray, sprite);  //放入GameSprite类中addChild
        player1data.HaveNewChess = 1;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(40, 430);
    }
}

void ChessPile::buy2(cocos2d::Ref* pSender)
{
  //  x = x + 90;
    if (Used[1].buy == false && ifCanBuy(1))
    {
        auto sprite = ChessCreate(Used[1].address);
        Used[1].buy = true;
        ccArrayAppendObject(player1data.PlayerArray, sprite);
        player1data.HaveNewChess = 1;
        cover(40, 310);
    }
}

void ChessPile::buy3(cocos2d::Ref* pSender)
{
   // x = x + 90;
    if (Used[2].buy == false && ifCanBuy(2))
    {
        auto sprite = ChessCreate(Used[2].address);
        Used[2].buy = true;
        ccArrayAppendObject(player1data.PlayerArray, sprite);
        player1data.HaveNewChess = 1;
        cover(40, 190);
    }
}

void ChessPile::buy4(cocos2d::Ref* pSender)
{
   // x = x + 90;
    if (Used[3].buy == false && ifCanBuy(3))
    {
        auto sprite = ChessCreate(Used[3].address);
        Used[3].buy = true;
        ccArrayAppendObject(player1data.PlayerArray, sprite);
        player1data.HaveNewChess = 1;
        cover(40, 70);
    }
}


void ChessPile::chessStore(cocos2d::Ref* pSender)
{
    static int x, y, width, height;
    x = 1420;
    y = 200;
    width = 180;
    height = 500;
    s_layer = LayerColor::create(Color4B::WHITE);
    s_layer->setPosition(x, y);
    s_layer->changeHeight(height);
    s_layer->changeWidth(width);
    this->addChild(s_layer, 1);

    /*-------------------set background----------------------*/
    auto sprite = Sprite::create("store_bg.png");
    sprite->setPosition(80, 250);
    s_layer->addChild(sprite);

    /*-------------------set label-------------------------*/
    auto label = Label::createWithTTF("STORE", "fonts/Marker Felt.ttf", 24);
    label->setPosition(80, 490);
    s_layer->addChild(label);

    for (int i = 0; i < 5; i++)
    {
        int deter = 0;
        deter = rand() % 100 + 1;
        for (int j = 0; j < 5; j++)
        {
            if (deter > PB[5][j])          //暂时按照6级的概率
                deter -= PB[5][j];
            else
            {
                int temp = 0;
                while (1)
                {
                    temp = rand() % OriginalChess;
                    if (chess_store[temp].money == j + 1)
                        break;
                }
                Used[i].address = chess_store[temp].address;
                Used[i].money = chess_store[temp].money;
                Used[i].picture_name = chess_store[temp].picture_name;
                break;
            }
        }
    }

    /*--------------------set chess---------------------------*/
    storeChess(i1);
    auto buy1 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy1, this));
    auto Buy1 = Menu::create(buy1, NULL);
    s_layer->addChild(Buy1, 1);
    Buy1->setPosition(125, 460 - 120 * i1);

    storeChess(i2);
    auto buy2 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy2, this));
    auto Buy2 = Menu::create(buy2, NULL);
    s_layer->addChild(Buy2, 1);
    Buy2->setPosition(125, 460 - 120 * i2);

    storeChess(i3);
    auto buy3 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy3, this));
    auto Buy3 = Menu::create(buy3, NULL);
    s_layer->addChild(Buy3, 1);
    Buy3->setPosition(125, 460 - 120 * i3);

    storeChess(i4);
    auto buy4 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy4, this));
    auto Buy4 = Menu::create(buy4, NULL);
    s_layer->addChild(Buy4, 1);
    Buy4->setPosition(125, 460 - 120 * i4);

 

    /*----------------------close store-----------------*/
    closeChessStore();

    /*-----------------------reset buy status-----------*/
    for (int i = 0; i <= 4; i++)
    {
        Used[i].buy = false;
    }
}