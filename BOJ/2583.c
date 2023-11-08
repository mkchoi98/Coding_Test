//
//  main.c
//  2583
//
//  Created by 최민경 on 2023/11/08.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int x[10000], y[10000];
    int front, rear;
}Queue;

void BFS(int arr[][101], int m, int n, int start_x, int start_y, int num)
{
    Queue que;
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int cur_x, cur_y, next_x, next_y;
    
    que.front = que.rear = -1;
    
    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;
    
    arr[start_x][start_y] = num;
    
    int i;
    
    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];
        cur_y = que.y[que.front];
        
        for (i=0;i<4;i++)
        {
            next_x = cur_x + dir_x[i];
            next_y = cur_y + dir_y[i];
            
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && arr[next_x][next_y] == 0)
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                arr[next_x][next_y] = num;
            }
        }
    }
}

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int m, n, k;
    int arr[101][101] = {0,};
    
    scanf("%d %d %d", &m, &n, &k);
    
    int i, j, s;
    int x1, y1, x2, y2;
    
    for (i=0;i<k;i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for (j=x1;j<x2;j++)
        {
            for (s=y1;s<y2;s++)
            {
                arr[s][j] = -1;
            }
        }
    }
    
    int num = 1;
    
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            if (arr[i][j] == 0)
            {
                BFS(arr, m, n, i, j, num);
                
                /*for (i=0;i<m;i++)
                {
                    for (j=0;j<n;j++)
                    {
                        printf("%3d", arr[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");*/
                
                num++;
            }
        }
    }
    
    printf("%d\n", num-1);
    
    int cnt[1000] = {0,};
    
    for (s=1;s<num;s++)
    {
        for(i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
            {
                if (arr[i][j] == s)
                {
                    cnt[s-1]++;
                }
            }
        }
    }
    
    qsort(cnt, num-1, sizeof(int), compare);
    
    for (i=0;i<num-1;i++) printf("%d ", cnt[i]);
    
    return 0;
}
