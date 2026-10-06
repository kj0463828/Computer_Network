#include <stdio.h> 
int main()
{
 int n, i, ack; 
 printf("Enter number of frames: ");
 scanf("%d", &n); 
 for(i = 1; i <= n; i++)
 {
 printf("\nSending Frame %d", i); 
 printf("\nEnter ACK (1 = Yes, 0 = No): ");
 scanf("%d", &ack); 
 if(ack == 1)
 {
 printf("Frame %d received.", i);
 }
 else
 {
 printf("Frame %d lost.", i);
 i--;
 }
 } 
 printf("\nAll frames sent successfully."); 
 return 0;
}
//Enter number of frames: 3
//
//Sending Frame 1
//Enter ACK (1 = Yes, 0 = No): 1
//Frame 1 received.
//Sending Frame 2
//Enter ACK (1 = Yes, 0 = No): 1
//Frame 2 received.
//Sending Frame 3
//Enter ACK (1 = Yes, 0 = No): 1
//Frame 3 received.
//All frames sent successfully.
