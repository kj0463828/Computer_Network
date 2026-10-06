#include <stdio.h>
#include <string.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET server, client;
 struct sockaddr_in server_addr;
 char message[100];
 int len; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 server = socket(AF_INET, SOCK_STREAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = INADDR_ANY; 
 bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
 listen(server, 1); 
 printf("TCP Server is waiting...\n"); 
 len = sizeof(server_addr); 
 client = accept(server, (struct sockaddr*)&server_addr, &len); 
 recv(client, message, sizeof(message) - 1, 0); 
 message[99] = '\0'; 
 printf("Message from Client: %s\n", message); 
 closesocket(client);
 closesocket(server);
 WSACleanup(); 
 return 0;
}
//gcc TCP_Server.c -o TCP_Server.exe -lws2_32
//TCP_Server.exe
