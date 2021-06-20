//
// Created by Zhengyi on 2021/5/5.
//

#include "SocketService.h"

#include <utility>
USING_NS_CC;

SocketService* SocketService::socket = nullptr;

SocketService* SocketService::getInstance() {
    if (!socket) {
        socket = new SocketService();
    }
    return socket;
}

void SocketService::deleteInstance() {
    delete socket;
    socket = nullptr;
}

SocketService::~SocketService() {
    if (client) client->close();
}

void SocketService::initSocket() {
    auto s = FileUtils::getInstance()->getStringFromFile("utils.json");
    rapidjson::Document doc;
    doc.Parse<0>(s.c_str());
    auto ip = doc["ip"].GetString();
    auto port = doc["port"].GetInt();
    string str = string("ws://") + ip + ":" + to_string(port);
    client = new WebSocket();
    client->init(*this, str);

    receiveMessage = "";
    ifReceviceMessage = false;
}

void SocketService::sendMessage(string str) {
    CCLOG("\t%s\n", str.c_str());
    client->send(str);
}

string SocketService::getMessage() {
    return receiveMessage;
}

void SocketService::setMessage(string s) {
    receiveMessage = std::move(s);
}

void SocketService::onOpen(WebSocket* ws) {
    log("\tsuccessful\n");
}

void SocketService::onMessage(WebSocket* ws, const WebSocket::Data& data) {
    log("\t%s\n", data.bytes);
    receiveMessage = data.bytes;
    ifReceviceMessage = true;
}

void SocketService::onClose(WebSocket* ws) {
    log("\tStopped\n");
}

void SocketService::onError(WebSocket* ws, const WebSocket::ErrorCode& error) {
    //
}

SocketService::SocketService() {
    initSocket();
}

