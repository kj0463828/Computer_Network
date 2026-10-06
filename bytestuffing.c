#include <stdio.h> 
int main()
{
 char data[100];
 int i; 
 printf("Enter data: ");
 scanf("%s", data); 
 printf("Byte Stuffing = ~"); 
 for(i = 0; data[i] != '\0'; i++)
 {
 if(data[i] == '~')
 printf("}"); 
 printf("%c", data[i]);
 } 
 printf("~"); 
 return 0;
}
//Enter data: ABC~DEF
//Byte Stuffing = ~ABC}~DEF~
