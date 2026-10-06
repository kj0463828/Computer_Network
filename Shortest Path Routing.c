#include <stdio.h> 
#define INF 999 
int main()
{
 int graph[10][10];
 int dist[10], visited[10], parent[10];
 int n, source, destination;
 int i, j, count;
 int min, next; 
 printf("Enter number of routers: ");
 scanf("%d", &n); 
 printf("Enter cost matrix:\n"); 
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 scanf("%d", &graph[i][j]);
 } 
 printf("Enter source: ");
 scanf("%d", &source); 
 printf("Enter destination: ");
 scanf("%d", &destination); 
 for(i = 0; i < n; i++)
 {
 dist[i] = INF;
 visited[i] = 0;
 parent[i] = -1;
 } 
 dist[source] = 0; 
 for(count = 0; count < n; count++)
 {
 min = INF;
 next = -1; 
 for(i = 0; i < n; i++)
 {
 if(!visited[i] && dist[i] < min)
 {
 min = dist[i];
 next = i;
 }
 } 
 if(next == -1)
 break; 
 visited[next] = 1; 
 for(j = 0; j < n; j++)
 {
 if(graph[next][j] != 0 &&
 dist[next] + graph[next][j] < dist[j])
 {
 dist[j] = dist[next] + graph[next][j];
 parent[j] = next;
 }
 }
 } 
 printf("\nShortest Cost = %d", dist[destination]); 
 printf("\nPath: "); 
 i = destination; 
 while(i != -1)
 {
 printf("%d ", i);
 i = parent[i];
 } 
 return 0;
} 
//Enter number of routers: 4
//Enter cost matrix:
//0 2 5 0
//2 0 1 4
//5 1 0 3
//0 4 3 0
//Enter source: 0
//Enter destination: 3
//
//Shortest Cost = 6
//Path: 3 1 0
