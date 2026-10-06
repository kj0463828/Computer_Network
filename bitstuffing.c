#include <stdio.h> 
int main()
{
 char data[100];
 int i, count = 0; 
 printf("Enter bit data: ");
 scanf("%s", data); 
 printf("Bit Stuffing = "); 
 for(i = 0; data[i] != '\0'; i++)
 {
 printf("%c", data[i]); 
 if(data[i] == '1')
 count++;
 else
 count = 0; 
 if(count == 5)
 {
 printf("0");
 count = 0;
 }
 } 
 return 0;
}
//Enter bit data: 11111011111
//Bit Stuffing = 1111100111110
