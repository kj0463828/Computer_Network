#include <stdio.h> 
int main()
{
 int cost[10][10], dist[10][10];
 int n, i, j, k; 
 printf("Enter number of routers: ");
 scanf("%d", &n); 
 printf("Enter cost matrix:\n"); 
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 {
 scanf("%d", &cost[i][j]);
 dist[i][j] = cost[i][j];
 }
 } 
 for(k = 0; k < n; k++)
 {
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 {
 if(dist[i][j] > cost[i][k] + dist[k][j])
 dist[i][j] = cost[i][k] + dist[k][j];
 }
 }
 } 
 printf("\nDistance Table:\n"); 
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 printf("%d ", dist[i][j]); 
 printf("\n");
 } 
 return 0;
}
//Enter number of routers: 3
//Enter cost matrix:
//0 2 7
//2 0 3
//7 3 0
//
//Distance Table:
//0 2 5
//2 0 3
//5 3 0
