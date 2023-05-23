//
//  main.c
//  2644
//
//  Created by 최민경 on 2023/05/23.
//

#include <stdio.h>

void DFS(int adj[][101], int start, int end, int visited[], int n, int *flag)
{
    int i;
    
    if (start == end)
    {
        *flag = 1;
        return;
    }
    
    visited[start] = 1;
    //printf("%d ", start);
    
    for (i=1;i<=n;i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0 && !(*flag))
        {
            //printf("%d\n", i);
            DFS(adj, i, end, visited, n, flag);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int a, b;
    int x, y;
    int i;
    int adj[101][101] = {0, }, visited[101] = {0};
    int cnt = 0;
    int flag = 0;
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    
    if (a > b)
        DFS(adj, a, b, visited, n, &flag);
    else
        DFS(adj, b, a, visited, n, &flag);
    
    if (flag)
    {
        for (i=1;i<=n;i++)
        {
            if (visited[i] != 0) cnt++;
        }
        
        printf("%d\n", cnt);
    }
    
    else printf("-1\n");
    
    return 0;
}
