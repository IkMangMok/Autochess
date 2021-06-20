#include"ChessPile.h"

ChessPile::ChessPile()
{
    chessStore();

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
            break;
        case pealauncher:
            return PeaShooter::createChess();     
            break;
        case mushroom:
            return MushRoom::createChess();
            break;
        case sunflower:
            return SunFlower::createChess();
            break;
        case chomper:
            return Chomper::createChess();
            break;
        case cherrybomb:
            return CherryBomb::createChess();
            break;
        case ga_peashooter:
            return Ga_PeaShooter::createChess();
            break;
        case tomatoboom:
            return TomatoBoom::createChess();
            break;
        default:
            return nullptr;
    }
}

bool ChessPile::init()
{
    srand(time(NULL));	
	return true;
}
bool ChessPile::ifCanBuy(int m, PlayerData& playerdata)
{
    int sum = 0;
    if (playerdata.Used[m].money > player1data.Gold)
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
    auto open = MenuItemImage::create("Back_test.png", "Back_test.png", CC_CALLBACK_1(ChessPile::openLayer, this));
    auto Open = Menu::create(open, nullptr);
    Open->setPosition(1530, 850);
    this->addChild(Open, 1);
}

void ChessPile::closeChessStore()
{
    auto close = MenuItemImage::create("Back_test.png", "Back_test.png", CC_CALLBACK_1(ChessPile::closeLayer, this));
    auto Close = Menu::create(close, nullptr);
    Close->setPosition(110, 650);
    s_layer->addChild(Close, 1);
}

void ChessPile::closeLayer(cocos2d::Ref* pSender)
{
    s_layer->setPosition(10000, 10000);
    openChessStore();
}
void ChessPile::openLayer(cocos2d::Ref* pSender)
{
    s_layer->setPosition(1420, 200);
    //closeChessStore();
}
 void ChessPile::storeChess(int i)
{
    auto sprite1 = Sprite::create(player1data.Used[i].picture_name);
    s_layer->addChild(sprite1);
    sprite1->setPosition(40, 430 - 120 * i);

    auto label1 = Label::createWithTTF(chessValue[player1data.Used[i].money - 1], "fonts/Marker Felt.ttf", 24);
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
    
    if (player1data.Used[0].buy == false && ifCanBuy(0, player1data))
    {
        auto sprite = ChessCreate(player1data.Used[0].address);

        player1data.Used[0].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        ccArrayAppendObject(player1data.PlayerArray, sprite);  //放入GameSprite类中addChild
        player1data.HaveNewChess = 1;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(40, 430);
    }
}

void ChessPile::buy2(cocos2d::Ref* pSender)
{
  //  x = x + 90;
    if (player1data.Used[1].buy == false && ifCanBuy(1, player1data))
    {
        auto sprite = ChessCreate(player1data.Used[1].address);
        player1data.Used[1].buy = true;
        ccArrayAppendObject(player1data.PlayerArray, sprite);
        player1data.HaveNewChess = 1;
        cover(40, 310);
    }
}

void ChessPile::buy3(cocos2d::Ref* pSender)
{
   // x = x + 90;
    if (player1data.Used[2].buy == false && ifCanBuy(2, player1data))
    {
        auto sprite = ChessCreate(player1data.Used[2].address);
        player1data.Used[2].buy = true;
        ccArrayAppendObject(player1data.PlayerArray, sprite);
        player1data.HaveNewChess = 1;
        cover(40, 190);
    }
}

void ChessPile::buy4(cocos2d::Ref* pSender)
{
   // x = x + 90;
    if (player1data.Used[3].buy == false && ifCanBuy(3, player1data))
    {
        auto sprite = ChessCreate(player1data.Used[3].address);
        player1data.Used[3].buy = true;
        ccArrayAppendObject(player1data.PlayerArray, sprite);
        player1data.HaveNewChess = 1;
        cover(40, 70);
    }
}


void ChessPile::chessStore()
{
    static int x, y, width, height;
    x = 1420;
    y = 200;
    width = 180;
    height = 500;
    s_layer = Layer::create();
    s_layer->setPosition(x, y);
    s_layer->setContentSize(Size(height,width));
    this->addChild(s_layer, 2);

    /*-------------------set background----------------------*/
    auto sprite = Sprite::create("store_bg.png");
    sprite->setPosition(80, 250);
    s_layer->addChild(sprite);

    /*-------------------set label-------------------------*/
    auto label = Label::createWithTTF("STORE", "fonts/Marker Felt.ttf", 24);
    label->setPosition(80, 490);
    s_layer->addChild(label);
    /*------------------refresh----------------------------*/
    auto Refresh = MenuItemImage::create("refresh.png", "refresh.png", CC_CALLBACK_1(ChessPile::refresh1, this));
    auto reFresh = Menu::create(Refresh, nullptr);
    reFresh->setPosition(110, 570);
    s_layer->addChild(reFresh, 1);
    refresh(player1data);
    if (player2data.Gold > 2)
    {
        player2data.Gold -= 2;
        refresh(player2data);
    }
    
    /*--------------------set chess---------------------------*/
    storeChess(0);
    auto buy1 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy1, this));
    auto Buy1 = Menu::create(buy1, nullptr);
    s_layer->addChild(Buy1, 1);
    Buy1->setPosition(125, 460 - 120 * 0);

    storeChess(1);
    auto buy2 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy2, this));
    auto Buy2 = Menu::create(buy2, NULL);
    s_layer->addChild(Buy2, 1);
    Buy2->setPosition(125, 460 - 120 * 1);

    storeChess(2);
    auto buy3 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy3, this));
    auto Buy3 = Menu::create(buy3, NULL);
    s_layer->addChild(Buy3, 1);
    Buy3->setPosition(125, 460 - 120 * 2);

    storeChess(3);
    auto buy4 = MenuItemImage::create("buy_store.jpg", "buy_store.jpg", CC_CALLBACK_1(ChessPile::buy4, this));
    auto Buy4 = Menu::create(buy4, NULL);
    s_layer->addChild(Buy4, 1);
    Buy4->setPosition(125, 460 - 120 * 3);
 
    /*----------------------close store-----------------*/
    closeChessStore();
   
    /*-----------------------reset buy status-----------*/
    for (int i = 0; i < 4; i++)
    {
        player1data.Used[i].buy = false;
    }

}
void ChessPile::refresh1(cocos2d::Ref* pSender)
{
    if (player1data.Gold >= 2)
    {
       
        player1data.Gold -= 2;
        s_layer->removeAllChildren();
        chessStore();
    }
    else
    {
        auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return ;
    }
}
void ChessPile::refresh(PlayerData& playerdata)
{
    for (int i = 0; i < 4; i++)
    {
        int deter = 0;
        deter = rand() % 100 + 1;
        for (int j = 0; j < 5; j++)
        {
            if (deter > PB[min(9, playerdata.Grade) - 1][j])    
                deter -= PB[min(9, playerdata.Grade) - 1][j];
            else
            {
                int temp = 0;
                while (1)
                {
                    temp = rand() % OriginalChess;
                    if (chess_store[temp].money == j + 1)
                        break;
                }
                playerdata.Used[i].address = chess_store[temp].address;
                playerdata.Used[i].money = chess_store[temp].money;
                playerdata.Used[i].picture_name = chess_store[temp].picture_name;
                playerdata.Used[i].buy = false;
                break;
            }
        }
    }
}
