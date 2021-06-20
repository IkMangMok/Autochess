#pragma comment(lib, "ws2_32.lib")	// ��Ҫ���������ӿ�

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>	// 2.2�汾

using namespace std;
int main()
{
    WSADATA		wsaData;		// ���ڳ�ʼ������Ϣ����ʼ���׽��֣�
    SOCKET		ReceivingSocket;	// ����˵��׽���
    SOCKADDR_IN		ReceiverAddr;		// ����˵ĵ�ַ
    SOCKADDR_IN		SenderAddr;		// �ͻ��˵ĵ�ַ
    int			SenderAddSize = sizeof(SOCKADDR);	// �����ַ��С 
    int			Ret;			// �����ж� 
    int			Port = 5150;		// �˿ںţ��Զ��壩

    SenderAddSize = sizeof(SOCKADDR);		// ��ֵ����ַ��С��

    // ��ʼ���׽��֣��汾�ŵȣ������ж��Ƿ�ɹ�
    if((Ret = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        printf("Error: WSAStartup failed with error %d\n", Ret);
        return 0;
    }
    else	// ��ʼ���ɹ�֮���ж��ǲ���������Ҫ�� 2.2 �汾
    {
        // �жϵ�λ�͸�λ�ǲ��Ƕ��� 2
        if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
        {
            printf("Error: not winsock 2.2\n");	
            WSACleanup();	// ���������Ϣ
            return 0;
        }
    }

    // �����׽���
    if((ReceivingSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
    {
        printf("Error: socket failed with error %d\n", WSAGetLastError());
        WSACleanup();
  	return 0;
    }

    // ��ʼ����ַ��Ϣ
    ReceiverAddr.sin_family = AF_INET;
    ReceiverAddr.sin_port = htons(Port);  // ת���������ֽ�
    ReceiverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  // ����������ip������������

    if(bind(ReceivingSocket, (SOCKADDR*)&ReceiverAddr, sizeof(ReceiverAddr)) == SOCKET_ERROR)
    {
        printf("Error: bind failed with error %d\n", WSAGetLastError());
  	closesocket(ReceivingSocket);
  	WSACleanup();
    	return 0;
    }
    
    // ��ʼ�շ�����
    while(1)
    {
        char buffer[1024] = {'\0'};	// �������ݷ���������Ҫ������
        //printf("waiting for message from others ... \n");

        // ��������
        if((Ret = recvfrom(ReceivingSocket, buffer, sizeof(buffer), 0,
            (SOCKADDR*)&SenderAddr, &SenderAddSize)) == SOCKET_ERROR)
        {
            printf("Error: recvfrom failed with error %d\n", WSAGetLastError());
  	    closesocket(ReceivingSocket);
  	    WSACleanup();
  	    return 0;
        }
        else	// ���ǽ����յ������ݣ����Ϳͻ���
        {
            printf("Client: %s\n", buffer);
            
            // ��������
            //sendto(ReceivingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&SenderAddr, SenderAddSize);
            
        	//printf("�����Client˵ʲô:\n");
        	scanf("%s", buffer);		// ����Ҫ���͵�����
        	sendto(ReceivingSocket, buffer, sizeof(buffer), 0, (SOCKADDR*)&SenderAddr, SenderAddSize);
        }
        
    	Sleep(500);	// �и������ʱ��
    }

    closesocket(ReceivingSocket);	// �ͷ��׽���
    WSACleanup();			// ���������Ϣ

    system("pause");
}

