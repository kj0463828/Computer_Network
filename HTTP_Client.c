#include <stdio.h>
#include <string.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET client;
 struct sockaddr_in server_addr;
 char request[] = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
 char response[2000];
 int n; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 client = socket(AF_INET, SOCK_STREAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
 connect(client, (struct sockaddr*)&server_addr,
 sizeof(server_addr)); 
 send(client, request, strlen(request), 0); 
 n = recv(client, response, sizeof(response) - 1, 0); 
 response[n] = '\0'; 
 printf("Web Page Received:\n");
 printf("%s\n", response); 
 closesocket(client);
 WSACleanup(); 
 return 0;
}
//gcc HTTP_Client.c -o HTTP_Client.exe -lws2_32
//HTTP_Client.exe
