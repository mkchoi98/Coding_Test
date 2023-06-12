//
//  main.c
//  1012
//
//  Created by 최민경 on 2023/06/12.
//

#include <stdio.h>
#include <stdlib.h>

void DFS(int **adj, int m, int n, int row, int col)
{
    adj[row][col] = 0;
    
    if (row-1 >=0 && adj[row-1][col] == 1)
        DFS(adj, m, n, row-1, col);
    if (row+1 <= m-1 && adj[row+1][col] == 1)
        DFS(adj, m, n, row+1, col);
    if (col-1 >=0 && adj[row][col-1] == 1)
        DFS(adj, m, n, row, col-1);
    if (col+1 <= n-1 && adj[row][col+1] == 1)
        DFS(adj, m, n, row, col+1);
}

int main(int argc, const char * argv[]) {
    int t;
    int n, m, k;
    int x, y;
    int i, j, l;
    int **adj;
    int cnt = 0;
    
    scanf("%d", &t);
    
    for (i=0;i<t;i++)
    {
        scanf("%d %d %d", &n, &m, &k);
        
        adj = (int **)malloc(sizeof(int*)*m);
        for (j=0;j<m;j++)
            adj[j] = (int *)malloc(sizeof(int)*n);
        
        for (j=0;j<k;j++)
        {
            scanf("%d %d", &x, &y);
            
            adj[y][x] = 1;
        }
        
        cnt = 0;
        
        for (j=0;j<m;j++)
        {
            for (l=0;l<n;l++)
            {
                if (adj[j][l] == 1)
                {
                    cnt++;
                    DFS(adj, m, n, j, l);
                }
            }
        }
        
        printf("%d\n", cnt);
        
        for (j=0;j<m;j++)
            free(adj[j]);
        free(adj);
    }
    
    return 0;
}
