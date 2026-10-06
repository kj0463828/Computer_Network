#include <stdio.h>
#include <string.h> 
int main()
{
 char data[20];
 int code[50];
 int m, r = 0, n;
 int i, j, p;
 int parity; 
 printf("Enter data bits: ");
 scanf("%s", data); 
 m = strlen(data); 
 while((1 << r) < (m + r + 1))
 r++; 
 n = m + r; 
 j = 0; 
 for(i = 1; i <= n; i++)
 {
 if((i & (i - 1)) == 0)
 code[i] = 0;
 else
 {
 code[i] = data[j] - '0';
 j++;
 }
 } 
 for(p = 1; p <= n; p = p * 2)
 {
 parity = 0; 
 for(i = 1; i <= n; i++)
 {
 if(i & p)
 parity = parity ^ code[i];
 } 
 code[p] = parity;
 } 
 printf("Hamming Code = "); 
 for(i = 1; i <= n; i++)
 printf("%d", code[i]); 
 return 0;
}
//Enter data bits: 1011
//Hamming Code = 0110011
