#include <stdio.h> 
int main()
{
 int n, i;
 int ack[20]; 
 printf("Enter number of frames: ");
 scanf("%d", &n); 
 for(i = 1; i <= n; i++)
 {
 printf("Enter ACK for Frame %d (1/0): ", i);
 scanf("%d", &ack[i]);
 } 
 printf("\nRetransmitting lost frames:\n"); 
 for(i = 1; i <= n; i++)
 {
 if(ack[i] == 0)
 printf("Frame %d retransmitted.\n", i);
 } 
 printf("Selective Repeat completed."); 
 return 0;
}
//Enter number of frames: 4
//Enter ACK for Frame 1 (1/0): 1
//Enter ACK for Frame 2 (1/0): 0
//Enter ACK for Frame 3 (1/0): 1
//Enter ACK for Frame 4 (1/0): 0
//
//Retransmitting lost frames:
//Frame 2 retransmitted.
//Frame 4 retransmitted.
//Selective Repeat completed.
