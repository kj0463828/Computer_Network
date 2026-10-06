#include <stdio.h>
#include <string.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET server, client;
 struct sockaddr_in server_addr;
 char request[1000];
 char response[1000]; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 server = socket(AF_INET, SOCK_STREAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = INADDR_ANY; 
 bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
 listen(server, 1); 
 printf("HTTP Server is running...\n"); 
 client = accept(server, NULL, NULL); 
 recv(client, request, sizeof(request) - 1, 0); 
 strcpy(response,
 "HTTP/1.1 200 OK\r\n"
 "Content-Type: text/html\r\n\r\n"
 "<html><body>"
 "<h1>Hello from Server</h1>"
 "<p>This is a simple web page.</p>"
 "</body></html>"); 
 send(client, response, strlen(response), 0); 
 printf("Web page sent to Client.\n"); 
 closesocket(client);
 closesocket(server);
 WSACleanup(); 
 return 0;
}
//gcc HTTP_Server.c -o HTTP_Server.exe -lws2_32
//HTTP_Server.exe
