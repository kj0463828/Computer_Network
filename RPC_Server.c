#include <stdio.h>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib") 
int main()
{
 WSADATA wsa;
 SOCKET server, client;
 struct sockaddr_in server_addr;
 int a, b, result;
 int len; 
 WSAStartup(MAKEWORD(2, 2), &wsa); 
 server = socket(AF_INET, SOCK_STREAM, 0); 
 server_addr.sin_family = AF_INET;
 server_addr.sin_port = htons(8080);
 server_addr.sin_addr.s_addr = INADDR_ANY; 
 bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)); 
 listen(server, 1); 
 printf("RPC Server is waiting...\n"); 
 len = sizeof(server_addr); 
 client = accept(server, (struct sockaddr*)&server_addr, &len); 
 recv(client, (char*)&a, sizeof(a), 0);
 recv(client, (char*)&b, sizeof(b), 0); 
 result = a + b; 
 send(client, (char*)&result, sizeof(result), 0); 
 printf("Calculation completed.\n"); 
 closesocket(client);
 closesocket(server);
 WSACleanup(); 
 return 0;
}
//gcc RPC_Server.c -o RPC_Server.exe -lws2_32
//RPC_Server.exe
