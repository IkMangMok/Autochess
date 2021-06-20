#pragma once
#include "cocos2d.h"
#include "extensions\cocos-ext.h"
#include "ui/UIEditBox/UIEditBox.h"
#include "ui/UIEditBox/UIEditBoxImpl.h"
#include "ui/UIHelper.h"


USING_NS_CC_EXT;
USING_NS_CC;
using namespace ui;



class LoginScene :public Scene, public EditBoxDelegate
{
public:
    static Scene* createScene();

    virtual bool init();
    void LoginBack(cocos2d::Ref* pSender);
    void menuGameStart(cocos2d::Ref* pSender);
    
    virtual void editBoxEditingDidBegin(EditBox* editBox);
    virtual void editBoxEditingDidEnd(EditBox* editBox);
    virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(EditBox* editBox);

    void modeAI(cocos2d::Ref* pSender);
    void modeServer(cocos2d::Ref* pSender);
    void modeClient(cocos2d::Ref* pSender);

    CREATE_FUNC(LoginScene);

};