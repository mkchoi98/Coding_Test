//
//  main.c
//  1926
//
//  Created by 최민경 on 2023/11/08.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int x[250000], y[250000];
    int front, rear;
}Queue;

void BFS(int arr[][501], int arr_copy[][501], int n, int m, int start_x, int start_y, int num)
{
    Queue que;
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int cur_x, cur_y, next_x, next_y;

    que.front = que.rear = -1;
    
    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;
    
    arr[start_x][start_y] = num;
    
    int cnt = 0;
    
    arr_copy[start_x][start_y] = ++cnt;
    
    int i;
    
    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];
        cur_y = que.y[que.front];
        
        for (i=0;i<4;i++)
        {
            next_x = cur_x + dir_x[i];
            next_y = cur_y + dir_y[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && arr[next_x][next_y] == 1)
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                arr[next_x][next_y] = num;
                arr_copy[next_x][next_y] = ++cnt;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int arr[501][501] = {0,};
    int arr_copy[501][501] = {0, };
    
    scanf("%d %d", &n, &m);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d", &arr[i][j]);
            arr_copy[i][j] = arr[i][j];
        }
    }
    
    int num = -1;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (arr[i][j] == 1)
            {
                BFS(arr, arr_copy, n, m, i, j, num);
                num--;
            }
        }
    }
    
    printf("%d\n", (num+1)*-1);
    
    int max = 0;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (arr_copy[i][j] > max)
            {
                max = arr_copy[i][j];
            }
        }
    }
    
    printf("%d", max);
    
    return 0;
}
