#include <stdio.h>
#include <string.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET server;
 struct sockaddr_in server_addr, client_addr;
 int len;
 char message[100]; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 server = socket(AF_INET, SOCK_DGRAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = INADDR_ANY; 
 bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
 printf("UDP Server is running...\n"); 
 len = sizeof(client_addr); 
 recvfrom(server, message, sizeof(message) - 1, 0,
 (struct sockaddr*)&client_addr, &len); 
 message[99] = '\0'; 
 printf("Message from Client: %s\n", message); 
 closesocket(server);
 WSACleanup(); 
 return 0;
}
//gcc UDP_Server.c -o UDP_Server.exe -lws2_32
//UDP_Server.exe
