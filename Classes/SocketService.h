//
// Created by Zhengyi on 2021/5/5.
//

#ifndef NETWORKSMALLGAME_SOCKETSERVICE_H
#define NETWORKSMALLGAME_SOCKETSERVICE_H

#include "cocos2d.h"
#include "network/WebSocket.h"
#include "json/document.h"
#include <string>

USING_NS_CC;
using namespace network;
using namespace std;

class SocketService : public WebSocket::Delegate {
    static SocketService* socket;

public:
    static SocketService* getInstance();

    static void deleteInstance();

    ~SocketService() override;

    void initSocket();

    void sendMessage(string str);

    string getMessage();

    void setMessage(string s);

    void onOpen(WebSocket* ws) override;

    void onMessage(WebSocket* ws, const WebSocket::Data& data) override;

    void onClose(WebSocket* ws) override;

    void onError(WebSocket* ws, const WebSocket::ErrorCode& error) override;


private:
    SocketService();

    WebSocket* client{};

    string receiveMessage;

    bool ifReceviceMessage{};
};


#endif //NETWORKSMALLGAME_SOCKETSERVICE_H