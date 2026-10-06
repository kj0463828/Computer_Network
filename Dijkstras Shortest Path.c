#include <stdio.h> 
#define INF 999 
int main()
{
 int graph[10][10];
 int dist[10], visited[10];
 int n, source;
 int i, j, count;
 int min, next; 
 printf("Enter number of vertices: ");
 scanf("%d", &n); 
 printf("Enter graph:\n"); 
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 scanf("%d", &graph[i][j]);
 } 
 printf("Enter source vertex: ");
 scanf("%d", &source); 
 for(i = 0; i < n; i++)
 {
 dist[i] = graph[source][i];
 visited[i] = 0;
 } 
 dist[source] = 0;
 visited[source] = 1; 
 for(count = 1; count < n; count++)
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
 for(i = 0; i < n; i++)
 {
 if(!visited[i] &&
 dist[next] + graph[next][i] < dist[i])
 {
 dist[i] = dist[next] + graph[next][i];
 }
 }
 } 
 printf("\nShortest Distance:\n"); 
 for(i = 0; i < n; i++)
 printf("To %d = %d\n", i, dist[i]); 
 return 0;
}
//Enter number of vertices: 4
//Enter graph:
//0 2 5 0
//2 0 1 4
//5 1 0 3
//0 4 3 0
//Enter source vertex: 0
//
//Shortest Distance:
//To 0 = 0
//To 1 = 2
//To 2 = 3
//To 3 = 0
