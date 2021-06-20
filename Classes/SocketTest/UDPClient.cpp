#pragma comment(lib, "ws2_32.lib")	// 需要包含的链接库

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>	// windows socket  2.2版本

using namespace std;
int main()
{
    WSADATA		wsaData;	// 用作初始化套接字
    SOCKET		SendingSocket;	// 客户端套接字
    SOCKADDR_IN		ReceiverAddr;	// 服务端地址
    int			ReceiverAddrSize = sizeof(SOCKADDR); // 服务端地址的大小
    int    		Port = 5150;	// 端口号

    
    // 初始化启动信息（初始套接字）
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    // 创建套接字
    SendingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // 初始化服务端地址
    ReceiverAddr.sin_family = AF_INET;
    ReceiverAddr.sin_port = htons(Port);
    ReceiverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // 可以用命令行参数来代替这边的初始化

    while(1)		// 开始发送数据  接收数据
    {
        char buffer[1024] = "\0";	// 用于发送 接收的数组

        //printf("您想对Server说什么:\n");
        scanf("%s", buffer);		// 输入要发送的数据

        if(strcmp(buffer, "bye") == 0)	// 结束对话判断 
            break;

        // 发送数据
        if(sendto(SendingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&ReceiverAddr, 
            sizeof(ReceiverAddr)) != SOCKET_ERROR)
        {
            // 发送成功后，将接收从服务端那边发回来的数据
            if (recvfrom(SendingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&ReceiverAddr,
                &ReceiverAddrSize) != SOCKET_ERROR)
            {
                // 成功接收数据，打印数据
            	printf("Server: %s\n", buffer);
            }
            
        }    
    }    
    
    closesocket(SendingSocket);	// 释放套接字
    WSACleanup();		// 清空启动信息
    
    system("pause");
}

