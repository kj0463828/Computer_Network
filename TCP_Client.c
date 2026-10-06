#include <stdio.h>
#include <string.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET client;
 struct sockaddr_in server_addr;
 char message[100]; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 client = socket(AF_INET, SOCK_STREAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
 connect(client, (struct sockaddr*)&server_addr,
 sizeof(server_addr)); 
 printf("Enter message: ");
 fgets(message, sizeof(message), stdin); 
 send(client, message, strlen(message), 0); 
 printf("Message sent to Server.\n"); 
 closesocket(client);
 WSACleanup(); 
 return 0;
}
//gcc TCP_Client.c -o TCP_Client.exe -lws2_32
//TCP_Client.exe
