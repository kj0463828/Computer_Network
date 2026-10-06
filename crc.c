#include <stdio.h>
#include <string.h> 
int main()
{
 char data[100], key[20], temp[120];
 int i, j;
 int n, k; 
 printf("Enter data: ");
 scanf("%s", data); 
 printf("Enter divisor: ");
 scanf("%s", key); 
 n = strlen(data);
 k = strlen(key); 
 strcpy(temp, data); 
 for(i = 0; i < k - 1; i++)
 strcat(temp, "0"); 
 for(i = 0; i < n; i++)
 {
 if(temp[i] == '1')
 {
 for(j = 0; j < k; j++)
 {
 if(temp[i+j] == key[j])
 temp[i+j] = '0';
 else
 temp[i+j] = '1';
 }
 }
 } 
 printf("CRC = "); 
 for(i = n; i < n+k-1; i++)
 printf("%c", temp[i]); 
 return 0;
}
//Enter data: 110101
//Enter divisor: 1011
//CRC = 111
