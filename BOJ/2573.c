//
//  main.c
//  2573
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int x[90000], y[90000];
    int front, rear;
}Queue;

void BFS(int arr[][300], int start_x, int start_y, int n, int m, int num)
{
    Queue que;
    int cur_x, cur_y, next_x, next_y;
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int i;
    
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
            next_x = cur_x+dir_x[i];
            next_y = cur_y+dir_y[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && arr[next_x][next_y] > 0)
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                arr[next_x][next_y] = num;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int arr[300][300], arr_copy[300][300];
    
    scanf("%d %d", &n, &m);
    
    int i, j, k;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int num = -1;
    
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int x, y;
    
    int zero_cnt = 0;
    
    int cnt = 0;
    
    int break_cnt = 0;
    
    while (1)
    {
        break_cnt = 0;
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (arr[i][j] == 0) break_cnt++;
            }
        }
        
        if (break_cnt == n*m)
        {
            printf("0");
            break;
        }
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                arr_copy[i][j] = arr[i][j];
            }
        }
        
        num = -1;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (arr_copy[i][j] > 0)
                {
                    BFS(arr_copy, i, j, n, m, num);
                    
                    num--;
                }
            }
        }
        
        if (abs(num) == 2)
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<m;j++)
                {
                    if (arr[i][j] != 0)
                    {
                        zero_cnt = 0;
                        // 빙하 녹이기
                        for (k=0;k<4;k++)
                        {
                            x = i+dir_x[k];
                            y = j+dir_y[k];
                            
                            if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 0)
                            {
                                zero_cnt++;
                            }
                        }
                        
                        arr[i][j] -= zero_cnt;
                        
                        if (arr[i][j] <= 0) arr[i][j] = -1;
                    }
                }
            }
            
            for (i=0;i<n;i++)
            {
                for (j=0;j<m;j++)
                {
                    if (arr[i][j] == -1) arr[i][j] = 0;
                }
            }
            
        }
        
       else
        {
            printf("%d", cnt);
            
            break;
        }
        
        cnt++;
    }
       
    
    return 0;
}
