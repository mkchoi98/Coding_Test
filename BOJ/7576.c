//
//  main.c
//  7576
//
//  Created by 최민경 on 2023/06/14.
//

#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int x[1000000];
    int y[1000000];
}Queue;

void result(int adj[][1000], int x, int y, int n, int m)
{
    int i, j;
    int max = 0;
    
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if (adj[i][j] == 0)
            {
                printf("-1\n");
                return;
            }
            
            if (max < adj[i][j])
            {
                max = adj[i][j];
            }
        }
    }
    printf("%d\n", max-1);
}

void BFS(int adj[][1000], Queue que, int n, int m)
{
    int x, y, nextX, nextY;
    int i;
    int directionX[4] = {0, 0, -1, 1};
    int directionY[4] = {-1, 1, 0, 0};
    
    while (que.front < que.rear)
    {
        x = que.x[++que.front];
        y = que.y[que.front];
        
        for (i=0;i<4;i++)
        {
            nextX = x+directionX[i];
            nextY = y+directionY[i];
            
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
            {
                if (adj[nextX][nextY] == 0)
                {
                    adj[nextX][nextY] = adj[x][y] + 1;
                    que.x[++que.rear] = nextX;
                    que.y[que.rear] = nextY;
                }
            }
        }
    }
    
    result(adj, nextX, nextY, n, m);
}

int main(int argc, const char * argv[]) {
    Queue que;
    int n, m;
    int adj[1000][1000];
    int i, j;

    que.front = que.rear = -1;
    
    scanf("%d %d", &n, &m);
    
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &adj[i][j]);
            
            if (adj[i][j] == 1)
            {
                que.x[++que.rear] = i;
                que.y[que.rear] = j;
            }
        }
    }
    
    BFS(adj, que, n, m);

    return 0;
}

