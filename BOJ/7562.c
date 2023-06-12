//
//  main.c
//  7562
//
//  Created by 최민경 on 2023/06/12.
//

#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int x[90000], y[90000];
}Queue;

void init(int arr[][300], int n)
{
    int i, j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            arr[i][j] = 1;
        }
    }
}

void BFS(int adj[][300], int start_x, int start_y, int I)
{
    Queue que;
    int x, y;
    
    que.rear = que.front = -1;
    
    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;
    
    while (que.front < que.rear)
    {
        x = que.x[++que.front];
        y = que.y[que.front];
        
        if (x-2 >= 0 && y-1 >= 0 && adj[x-2][y-1]==1)
        {
            que.x[++que.rear] = x-2;
            que.y[que.rear] = y-1;
            
            adj[x-2][y-1] = adj[x][y] + 1;
        }
        if (x-1 >= 0 && y-2 >= 0 && adj[x-1][y-2]==1)
        {
            que.x[++que.rear] = x-1;
            que.y[que.rear] = y-2;
        
            adj[x-1][y-2] = adj[x][y] + 1;
        }
        if (x+1 < I && y-2 >= 0 && adj[x+1][y-2]==1)
        {
            que.x[++que.rear] = x+1;
            que.y[que.rear] = y-2;
            
            adj[x+1][y-2] = adj[x][y] + 1;
        }
        if (x+2 < I && y-1 >= 0 && adj[x+2][y-1]==1)
        {
            que.x[++que.rear] = x+2;
            que.y[que.rear] = y-1;
            
            adj[x+2][y-1] = adj[x][y] + 1;
        }
        if (x-2 >= 0 && y+1 < I && adj[x-2][y+1]==1)
        {
            que.x[++que.rear] = x-2;
            que.y[que.rear] = y+1;
            
            adj[x-2][y+1] = adj[x][y] + 1;
        }
        if (x-1 >= 0 && y+2 < I && adj[x-1][y+2]==1)
        {
            que.x[++que.rear] = x-1;
            que.y[que.rear] = y+2;
            
            adj[x-1][y+2] = adj[x][y] + 1;
        }
        if (x+2 < I && y+1 < I && adj[x+2][y+1]==1)
        {
            que.x[++que.rear] = x+2;
            que.y[que.rear] = y+1;
            
            adj[x+2][y+1] = adj[x][y] + 1;
        }
        if (x+1 < I && y+2 < I && adj[x+1][y+2]==1)
        {
            que.x[++que.rear] = x+1;
            que.y[que.rear] = y+2;
            
            adj[x+1][y+2] = adj[x][y] + 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    int test;
    int I;
    int x, y, x_des, y_des;
    int i;
    int adj[300][300];
    
    scanf("%d", &test);
    
    for (i=0;i<test;i++)
    {
        scanf("%d", &I);
        scanf("%d %d", &x, &y);
        scanf("%d %d", &x_des, &y_des);
        
        if (x == x_des && y == y_des)
        {
            printf("0\n");
            continue;
        }
        
        init(adj, I);
        
        BFS(adj, x, y, I);
        
        printf("%d\n", adj[x_des][y_des]-1);
    }
        
    return 0;
}
