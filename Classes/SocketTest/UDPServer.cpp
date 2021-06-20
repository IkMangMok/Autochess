#pragma comment(lib, "ws2_32.lib")	// 需要包含的链接库

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>	// 2.2版本

using namespace std;
int main()
{
    WSADATA		wsaData;		// 用于初始启动信息（初始化套接字）
    SOCKET		ReceivingSocket;	// 服务端的套接字
    SOCKADDR_IN		ReceiverAddr;		// 服务端的地址
    SOCKADDR_IN		SenderAddr;		// 客户端的地址
    int			SenderAddSize = sizeof(SOCKADDR);	// 保存地址大小 
    int			Ret;			// 用于判断 
    int			Port = 5150;		// 端口号（自定义）

    SenderAddSize = sizeof(SOCKADDR);		// 赋值（地址大小）

    // 初始化套接字（版本号等），并判断是否成功
    if((Ret = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        printf("Error: WSAStartup failed with error %d\n", Ret);
        return 0;
    }
    else	// 初始化成功之后，判断是不是我们需要的 2.2 版本
    {
        // 判断低位和高位是不是都是 2
        if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
        {
            printf("Error: not winsock 2.2\n");	
            WSACleanup();	// 清空启动信息
            return 0;
        }
    }

    // 创建套接字
    if((ReceivingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
    {
        printf("Error: socket failed with error %d\n", WSAGetLastError());
        WSACleanup();
  	return 0;
    }

    // 初始化地址信息
    ReceiverAddr.sin_family = AF_INET;
    ReceiverAddr.sin_port = htons(Port);  // 转换成网络字节
    ReceiverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  // 本机的所有ip，都可以连接

    if(bind(ReceivingSocket, (SOCKADDR*)&ReceiverAddr, sizeof(ReceiverAddr)) == SOCKET_ERROR)
    {
        printf("Error: bind failed with error %d\n", WSAGetLastError());
  	closesocket(ReceivingSocket);
  	WSACleanup();
    	return 0;
    }
    
    // 开始收发数据
    while(1)
    {
        char buffer[1024] = {'\0'};	// 接受数据发送数据需要的数组
        //printf("waiting for message from others ... \n");

        // 接收数据
        if((Ret = recvfrom(ReceivingSocket, buffer, sizeof(buffer), 0,
            (SOCKADDR*)&SenderAddr, &SenderAddSize)) == SOCKET_ERROR)
        {
            printf("Error: recvfrom failed with error %d\n", WSAGetLastError());
  	    closesocket(ReceivingSocket);
  	    WSACleanup();
  	    return 0;
        }
        else	// 我们将接收到的数据，发送客户端
        {
            printf("Client: %s\n", buffer);
            
            // 发送数据
            //sendto(ReceivingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&SenderAddr, SenderAddSize);
            
        	//printf("您想对Client说什么:\n");
        	scanf("%s", buffer);		// 输入要发送的数据
        	sendto(ReceivingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&SenderAddr, SenderAddSize);
        }
        
    	Sleep(500);	// 有个缓冲的时间
    }

    closesocket(ReceivingSocket);	// 释放套接字
    WSACleanup();			// 清空启动信息

    system("pause");
}

