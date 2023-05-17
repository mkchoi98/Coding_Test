//
//  main.c
//  1260
//
//  Created by 최민경 on 2023/05/15.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear;
    int data[1000];
}Queue;

void init(int *arr, int n)
{
    int i;
    
    for (i=0;i<n;i++)
        arr[i] = 0;
}

void DFS(int **adj, int *visited, int start, int n)
{
    int i;
    
    visited[start] = 1;
    printf("%d ", start+1);
    
    for (i=0;i<n;i++)
    {
        if (adj[start][i] == 1)
        {
            if (!visited[i])
            {
                DFS(adj, visited, i, n);
            }
        }
    }
}

void BFS(int **adj, int *discovered, int start, int n)
{
    Queue que;
    int i, index;
    
    que.front = que.rear = -1;
    
    discovered[start] = 1;
    que.data[++que.rear] = start;
    
    while (que.front < que.rear)
    {
        index = que.data[++que.front];
        printf("%d ", index+1);
        
        for (i=0;i<n;i++)
        {
            if (adj[index][i] == 1 && discovered[i] == 0)
            {
                discovered[i] = 1;
                que.data[++que.rear] = i;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m, v;
    int **adj, *visited, *discovered;
    int i;
    int x, y;
    
    scanf("%d %d %d", &n, &m, &v);
    
    adj = (int **)malloc(sizeof(int *)*n);
    for (i=0;i<n;i++)
        adj[i] = (int *)malloc(sizeof(int)*n);
    
    visited = (int *)malloc(sizeof(int)*n);
    discovered = (int *)malloc(sizeof(int)*n);
    
    init(visited, n);
    init(discovered, n);
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d", &x, &y);
        adj[x-1][y-1] = 1;
        adj[y-1][x-1] = 1;
    }
    
    DFS(adj, visited, v-1, n);
    printf("\n");
    BFS(adj, discovered, v-1, n);
    
    for(i=0;i<n;i++)
        free(adj[i]);
    free(adj);
    
    free(visited);
    
    free(discovered);
    
    return 0;
}
