//
//  main.c
//  1389
//
//  Created by 최민경 on 2023/06/13.
//

#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int data[10000];
}Queue;

void init(int *arr, int n)
{
    int i;
    
    for (i=0;i<=n;i++)
        arr[i] = 0;
}

void BFS(int adj[][101], int discovered[], int n, int start)
{
    Queue que;
    int data;
    int i;
    
    que.rear = que.front = -1;
    
    que.data[++que.rear] = start;
    discovered[start] = 1;
    
    while (que.front < que.rear)
    {
        data = que.data[++que.front];
        
        //printf("%d ", data);
        for (i=1;i<=n;i++)
        {
            if (adj[data][i] == 1 && discovered[i] == 0)
            {
                que.data[++que.rear] = i;
                discovered[i] = discovered[data]+1;
                
                //printf("%d ", i);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int a, b;
    int adj[101][101] = {0,}, discovered[101] = {0};
    int i, j;
    int sum[101] = {0};
    int min, min_index;
    
    scanf("%d %d", &n, &m);
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d", &a, &b);
        
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    for (i=1;i<=n;i++)
    {
        init(discovered, n);
        
        BFS(adj, discovered, n, i);
        
        for (j=1;j<=n;j++)
        {
            sum[i] += discovered[j];
        }
        //printf("\n");
    }
    
    min = sum[1];
    min_index = 1;
    
    for (i=2;i<=n;i++)
    {
        if (min > sum[i])
        {
            min = sum[i];
            min_index = i;
        }
    }
    
    printf("%d", min_index);

    return 0;
}
