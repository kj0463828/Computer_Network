#include <stdio.h>
#include <string.h> 
int binaryToDecimal(char binary[])
{
 int i, num = 0; 
 for (i = 0; binary[i] != '\0'; i++)
 {
 num = num * 2 + (binary[i] - '0');
 } 
 return num;
} 
void decimalToBinary(int num, char binary[], int bits)
{
 int i; 
 for (i = bits - 1; i >= 0; i--)
 {
 binary[i] = (num % 2) + '0';
 num = num / 2;
 } 
 binary[bits] = '\0';
} 
int main()
{
 int n, i;
 int bits;
 int sum = 0;
 int maxValue;
 char data[20][20];
 char binarySum[20];
 char checksum[20]; 
 printf("Enter number of data blocks: ");
 scanf("%d", &n); 
 printf("Enter number of bits in each block: ");
 scanf("%d", &bits); 
 for (i = 0; i < n; i++)
 {
 printf("Enter binary data %d: ", i + 1);
 scanf("%s", data[i]);
 } 
 /* Add all data blocks */
 for (i = 0; i < n; i++)
 {
 sum = sum + binaryToDecimal(data[i]);
 } 
 maxValue = 1 << bits; 
 /* Add carry */
 while (sum >= maxValue)
 {
 sum = (sum % maxValue) + (sum / maxValue);
 } 
 /* Convert sum to binary */
 decimalToBinary(sum, binarySum, bits); 
 /* Find 1's complement */
 for (i = 0; i < bits; i++)
 {
 if (binarySum[i] == '0')
 checksum[i] = '1';
 else
 checksum[i] = '0';
 } 
 checksum[bits] = '\0'; 
 printf("\nData Blocks:\n"); 
 for (i = 0; i < n; i++)
 {
 printf("%s\n", data[i]);
 } 
 printf("Sum : %s\n", binarySum);
 printf("Checksum : %s\n", checksum); 
 /* Receiver side */
 sum = sum + binaryToDecimal(checksum); 
 while (sum >= maxValue)
 {
 sum = (sum % maxValue) + (sum / maxValue);
 } 
 decimalToBinary(sum, binarySum, bits); 
 printf("Final Sum: %s\n", binarySum); 
 /* Check error */
 for (i = 0; i < bits; i++)
 {
 if (binarySum[i] != '1')
 break;
 } 
 if (i == bits)
 printf("No Error Detected\n");
 else
 printf("Error Detected\n"); 
 return 0;
}
//Enter number of data blocks: 3
//Enter number of bits in each block: 4
//Enter binary data 1: 1010
//Enter binary data 2: 1100
//Enter binary data 3: 0011
//
//Data Blocks:
//1010
//1100
//0011
//Sum : 1010
//Checksum : 0101
//Final Sum: 1111
//No Error Detected
