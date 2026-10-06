#include <stdio.h> 
int main()
{
 char message[100]; 
 printf("Client: Enter message: ");
 gets(message); 
 printf("\nClient sent: %s", message);
 printf("\nServer received: %s", message); 
 printf("\nCommunication successful."); 
 return 0;
} 
//Client: Enter message: Hello
//
//Client sent: Hello
//Server received: Hello
//Communication successful.
