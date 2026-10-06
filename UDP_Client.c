#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <stdlib.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET client;
 struct sockaddr_in server_addr;
 char message[100]; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 client = socket(AF_INET, SOCK_DGRAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
 printf("Enter message: ");
 fgets(message, sizeof(message), stdin); 
 sendto(client, message, strlen(message), 0,
 (struct sockaddr*)&server_addr, sizeof(server_addr)); 
 printf("Message sent to Server.\n"); 
 closesocket(client);
 WSACleanup(); 
 return 0;
}
//gcc UDP_Client.c -o UDP_Client.exe -lws2_32
//UDP_Client.exe
