//
//  main.c
//  2178
//
//  Created by 최민경 on 2023/06/12.
//

#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int x[10000], y[10000];
}Queue;

void BFS(int adj[][101], int start_x, int start_y, int n, int m, int *cnt)
{
    Queue que;
    int x, y;

    que.rear = que.front = -1;
    
    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;
    
    adj[start_x][start_y] = 0;
    
    while (que.front < que.rear)
    {
        x = que.x[++que.front];
        y = que.y[que.front];
        
        if (adj[x-1][y] == 1 && x > 0)
        {
            que.x[++que.rear] = x-1;
            que.y[que.rear] = y;
            
            adj[x-1][y] = adj[x][y] + 1;
        }
        
        if (adj[x+1][y] == 1 && x < n-1)
        {
            que.x[++que.rear] = x+1;
            que.y[que.rear] = y;
            
            adj[x+1][y] = adj[x][y] + 1;
        }
        
        if (adj[x][y-1] == 1 && y > 0)
        {
            que.x[++que.rear] = x;
            que.y[que.rear] = y-1;
            
            adj[x][y-1] = adj[x][y] + 1;
        }
        
        if (adj[x][y+1] == 1 && y < m-1)
        {
            que.x[++que.rear] = x;
            que.y[que.rear] = y+1;
            
            adj[x][y+1]= adj[x][y] + 1;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int adj[101][101];
    int i, j;
    int cnt = 1;
    
    scanf("%d %d", &n, &m);
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }
    
    BFS(adj, 0, 0, n, m, &cnt);
    
    printf("%d", adj[n-1][m-1]+1);
    
    return 0;
}
