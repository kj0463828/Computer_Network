#include <stdio.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET client;
 struct sockaddr_in server_addr;
 int a, b, result; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 client = socket(AF_INET, SOCK_STREAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
 connect(client, (struct sockaddr*)&server_addr,
 sizeof(server_addr)); 
 printf("Enter first number: ");
 scanf("%d", &a); 
 printf("Enter second number: ");
 scanf("%d", &b); 
 send(client, (char*)&a, sizeof(a), 0);
 send(client, (char*)&b, sizeof(b), 0); 
 recv(client, (char*)&result, sizeof(result), 0); 
 printf("Result = %d\n", result); 
 closesocket(client);
 WSACleanup(); 
 return 0;
}
//gcc RPC_Client.c -o RPC_Client.exe -lws2_32
//RPC_Client.exe
