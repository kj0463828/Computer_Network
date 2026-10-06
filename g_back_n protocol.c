#include <stdio.h> 
int main()
{
 int n, lost, i; 
 printf("Enter number of frames: ");
 scanf("%d", &n); 
 printf("Enter lost frame number: ");
 scanf("%d", &lost); 
 printf("\nFrames sent:\n"); 
 for(i = 1; i < lost; i++)
 printf("Frame %d sent.\n", i); 
 printf("Frame %d lost.\n", lost); 
 printf("\nRetransmitting from Frame %d:\n", lost); 
 for(i = lost; i <= n; i++)
 printf("Frame %d sent again.\n", i); 
 return 0;
}
//Enter number of frames: 5
//Enter lost frame number: 3
//
//Frames sent:
//Frame 1 sent.
//Frame 2 sent.
//Frame 3 lost.
//
//Retransmitting from Frame 3:
//Frame 3 sent again.
//Frame 4 sent again.
//Frame 5 sent again.
