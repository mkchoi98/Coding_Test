//
//  main.c
//  2468
//
//  Created by 최민경 on 2023/09/06.
//

#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int x[10001], y[10001];
}Queue;

void BFS(int arr[][101], int n, int start_x, int start_y, int num)
{
    Queue que;
    int cur_x, cur_y;
    int i;
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int next_x, next_y;
    
    que.front = que.rear = -1;
    
    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;
    
    arr[start_x][start_y] = num;
    
    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];
        cur_y = que.y[que.front];
        
        for (i=0;i<4;i++)
        {
            next_x = cur_x + dir_x[i];
            next_y = cur_y + dir_y[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && arr[next_x][next_y] == 0)
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                arr[next_x][next_y] = num;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int arr[101][101] = {0,};
    int arr_copy[101][101] = {0,};
    
    scanf("%d", &n);
    
    int i, j, k;
    int max = 0;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
            
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    
    int num = 1;
    int answer = 0;
    
    for (i=0;i<=max;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                arr_copy[j][k] = arr[j][k];
            }
        }
                    
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                if (arr_copy[j][k] > i)
                {
                    arr_copy[j][k] = 0;
                }
            }
        }
       
        num = 1;
        
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                if (arr_copy[j][k] == 0)
                {
                    BFS(arr_copy, n, j, k, num);
                    
                    num++;
                }
            }
        }
        
        if (num-1 > answer) answer = num-1;
    }
    
    printf("%d", answer);
    
    return 0;
}
