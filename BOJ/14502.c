#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int x[64], y[64];
}Queue;

int BFS(int adj_copy[][8], Queue que, int n, int m)
{
    int deque_x, deque_y;
    int x, y;
    int x_direction[4] = { -1, 1, 0, 0 };
    int y_direction[4] = { 0, 0, -1, 1 };
    int i, j;
    int adj[8][8];
    int zero_cnt = 0;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            adj[i][j] = adj_copy[i][j];
        }
    }
    
    while (que.front < que.rear)
    {
        deque_x = que.x[++que.front];
        deque_y = que.y[que.front];
        
        for (i = 0; i < 4; i++)
        {
            x = deque_x + x_direction[i];
            y = deque_y + y_direction[i];
            
            if (x >= 0 && x < n && y >= 0 && y < m)
            {
                if (adj[x][y] == 0)
                {
                    que.x[++que.rear] = x;
                    que.y[que.rear] = y;
                    
                    adj[x][y] = 2;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (adj[i][j] == 0) zero_cnt++;
        }
    }
    
    return zero_cnt;
}

void build_wall(int cnt, int adj_copy[][8], Queue que, int n, int m, int *answer)
{
    int i, j;
    int zero_cnt;

    if (cnt == 3)
    {
        zero_cnt = BFS(adj_copy, que, n, m);

        //printf("\n%d\n", zero_cnt);
        if (zero_cnt > *answer)
        {
            *answer = zero_cnt;
        }
        
        return;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (adj_copy[i][j] == 0)
            {
                adj_copy[i][j] = 1;
                build_wall(cnt + 1, adj_copy, que, n, m, answer);
                adj_copy[i][j] = 0;
            }
        }
    }
    
}

int main()
{
    Queue que;
    int n, m;
    int i, j, u, v;
    int adj[8][8], adj_copy[8][8];
    int answer = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &adj[i][j]);
            //adj_copy[i][j] = adj[i][j];
        }
    }
    
    que.front = que.rear = -1;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (adj[i][j] == 2)
            {
                que.x[++que.rear] = i;
                que.y[que.rear] = j;
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (adj[i][j] == 0)
            {
                for (u = 0; u < n; u++)
                {
                    for (v = 0; v < m; v++)
                    {
                        adj_copy[u][v] = adj[u][v];
                    }
                }
                adj_copy[i][j] = 1;
                build_wall(1, adj_copy, que, n, m, &answer);
                adj_copy[i][j] = 0;
            }
        }
    }
    
    printf("%d", answer);
    
    return 0;
}
