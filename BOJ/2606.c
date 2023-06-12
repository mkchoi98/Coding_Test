//
//  main.c
//  2606
//
//  Created by 최민경 on 2023/06/12.
//

#include <stdio.h>

void DFS(int adj[][101], int *visited, int start, int n, int *cnt)
{
    int i;
    
    visited[start] = 1;
    
    for (i=1;i<=n;i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
        {
            (*cnt)++;
            //printf("%d ", i);
            DFS(adj, visited, i, n, cnt);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int i;
    int visited[101] = {0}, adj[101][101] ={0,};
    int u, v;
    int cnt = 0;
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d", &u, &v);
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    DFS(adj, visited, 1, n, &cnt);
    
    printf("%d", cnt);
    
    return 0;
}
