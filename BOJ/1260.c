//
//  main.c
//  1260
//
//  Created by 최민경 on 2023/05/15.
//

#include <stdio.h>
#include <stdlib.h>

void init(int *visited, int n)
{
    int i;
    
    for (i=0;i<n;i++)
        visited[i] = 0;
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

int main(int argc, const char * argv[]) {
    int n, m, v;
    int **adj, *visited;
    int i;
    int x, y;
    
    scanf("%d %d %d", &n, &m, &v);
    
    adj = (int **)malloc(sizeof(int *)*n);
    for (i=0;i<n;i++)
        adj[i] = (int *)malloc(sizeof(int)*n);
    
    visited = (int *)malloc(sizeof(int)*n);
    
    init(visited, n);
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d", &x, &y);
        adj[x-1][y-1] = 1;
        adj[y-1][x-1] = 1;
    }
    
    DFS(adj, visited, v-1, n);
    printf("\n");
    
    for(i=0;i<n;i++)
        free(adj[i]);
    free(adj);
    
    free(visited);
    
    return 0;
}
