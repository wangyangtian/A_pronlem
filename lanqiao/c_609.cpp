#include <limits.h> 
#include <stdio.h> 

#define V 19 

int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 

    return min_index; 
} 

void printSolution(int dist[]) 
{   char s='a';
    printf("   Distance from Source\n"); 
    for (int i = 0; i < V; i++){
    printf(" %c  ", s++); 
    printf("%d\n", dist[i]); 
    }
} 

void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; 

    bool sptSet[V]; 

    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 

    dist[src] = 0; 

    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, sptSet); 

        sptSet[u] = true; 

        for (int v = 0; v < V; v++) 

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 

    printSolution(dist); 
} 

int main() 
{                      //a b c d e f g h i j k l m n o p q r s
    int graph[V][V] = { {0,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//a
                        {2,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,0},//b
                        {1,0,0,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0},//c
                        {1,0,3,0,1,0,2,1,2,0,0,0,0,0,0,0,0,0,0},//d
                        {1,0,0,1,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0},//e
                        {0,0,3,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0},//f
                        {0,1,3,2,0,1,0,0,3,0,2,0,0,0,0,0,0,0,0},//g
                        {0,0,0,1,1,0,0,0,1,0,0,2,0,0,0,0,0,0,0},//h
                        {0,0,0,2,3,0,3,1,0,0,0,0,3,0,0,0,0,0,0},//i
                        {0,2,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,2},//j
                        {0,0,0,0,0,0,2,0,0,0,0,3,0,1,0,2,0,0,0},//k
                        {0,0,0,0,0,0,0,2,0,0,3,0,1,0,0,0,0,1,0},//l
                        {0,0,0,0,0,0,0,0,3,0,0,1,0,2,0,0,1,0,1},//m
                        {0,0,0,0,0,0,0,0,0,0,1,0,2,0,0,0,1,0,0},//n
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,0},//o
                        {0,0,0,0,0,0,0,0,0,0,2,0,0,1,1,0,0,0,0},//p
                        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},//q
                        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,3,0,0,0,1},//r
                        {0,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,1,0},//s
                        }; 

    dijkstra(graph, 0); 

    return 0; 
} 

