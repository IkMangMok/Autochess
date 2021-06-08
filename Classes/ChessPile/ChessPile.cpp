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
bool ChessPile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*auto tempsprite = Sprite::create("buy.jpg");
	auto tempsprite1 = Sprite::create("buy.jpg");
	auto tempsprite2 = Sprite::create("buy.jpg");
	auto tempsprite3 = Sprite::create("buy.jpg");
	auto BuyChess = ControlSwitch::create(tempsprite, tempsprite1, tempsprite2, tempsprite3);
	this->addChild(BuyChess, 1);
	BuyChess->setPosition(visibleSize.width, 0);
	BuyChess->addTargetWithActionForControlEvents(this, cccontrol_selector(ChessPile::PlayerBuyChess), Control::EventType::VALUE_CHANGED);*/
    srand(time(NULL));
    openChessStore();
	
	return true;
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
    auto sprite1 = Sprite::create(Used[i].address);
    s_layer->addChild(sprite1);
    sprite1->setPosition(40, 430 - 120 * i);

    auto label1 = Label::createWithTTF(chessValue[Used[i].money - 1], "fonts/Marker Felt.ttf", 24);
    label1->setPosition(130, 430 - 120 * i);
    s_layer->addChild(label1);

}

void ChessPile::buy1(cocos2d::Ref* pSender)
{
   // x = x + 90;
    auto sprite = Chess::createChess(Used[0].address);
    ccArrayAppendObject(player1data.PlayerArray, sprite);  //放入GameSprite类中addChild
    player1data.HaveNewChess = 1;
    player1data.Chessnumber++;
}

void ChessPile::buy2(cocos2d::Ref* pSender)
{
  //  x = x + 90;
    auto sprite = Chess::createChess(Used[1].address);
    ccArrayAppendObject(player1data.PlayerArray, sprite);
    player1data.HaveNewChess = 1;
    player1data.Chessnumber++;
}

void ChessPile::buy3(cocos2d::Ref* pSender)
{
   // x = x + 90;
    auto sprite = Chess::createChess(Used[2].address);
    ccArrayAppendObject(player1data.PlayerArray, sprite);
    player1data.HaveNewChess = 1;
    player1data.Chessnumber++;
}

void ChessPile::buy4(cocos2d::Ref* pSender)
{
   // x = x + 90;
    auto sprite = Chess::createChess(Used[3].address);
    ccArrayAppendObject(player1data.PlayerArray, sprite);  
    player1data.HaveNewChess = 1;
    player1data.Chessnumber++;
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

    for (int i = 0; i <= 3; i++)
    {
        int deter = 0;
        deter = rand() % 8;
        Used[i].address = chess_store[deter].address;
        Used[i].money = chess_store[deter].money;
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
}