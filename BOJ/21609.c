#include <stdio.h>

typedef struct Queue
{
    int x[404], y[404];
    int front, rear;
}Queue;

void BFS(int arr[][20], int n, int start_x, int start_y, int k, int *cnt, int *rainbow_cnt, int *row, int *col, int num)
{
    Queue que;
    int cur_x, cur_y, next_x, next_y;
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int i, j;
    
    que.front = que.rear = -1;
    
    arr[start_x][start_y] = num;
    
    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;
    
    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];
        cur_y = que.y[que.front];
        
        for (i=0;i<4;i++)
        {
            next_x = cur_x + dir_x[i];
            next_y = cur_y + dir_y[i];
            
            if (next_x < n && next_x >= 0 && next_y < n && next_y >= 0 && (arr[next_x][next_y] == k || arr[next_x][next_y] == 0))
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                if (arr[next_x][next_y] == k) arr[next_x][next_y] = num;
                if (arr[next_x][next_y] == 0) arr[next_x][next_y] = num-1;
            }
        }
    }
    
    int min_i = n, min_j = n;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (arr[i][j] == num-1) (*rainbow_cnt)++;
            
            if (arr[i][j] == num)
            {
                (*cnt)++;
                
                if (min_i > i)
                {
                    min_i = i;
                }
                
                if (min_j > j)
                {
                    min_j = j;
                }
            }
        }
    }
    
    if (*cnt == 0)
    {
        //*cnt -= 1;
    }
    
    else
    {
        if (*cnt == 1 && *rainbow_cnt == 0)
        {
            *cnt = 0;
            return;
        }
        
        *cnt = *cnt + *rainbow_cnt;
        
        *row = min_i;
        *col = min_j;
        
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int answer = 0;
    
    scanf("%d %d", &n, &m);
    
    int arr[20][20];
    int arr_copy[20][20];
    int arr_rotation[20][20];
    
    int i, j, k;
    int max = 0 , cnt;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int u, v;
    int max_num, max_rainbow_cnt, max_row, max_col;
    int rainbow_cnt = 0, row, col;
    int num = -2;
    
    int index_i = -1, index_j = -1;
    
    while(1)
    {
        max = 0;
        max_num = -1;
        max_rainbow_cnt = 0;
        max_row = -1;
        max_col = -1;
        
        index_i = -1;
        index_j = -1;
        
        for (k=1;k<=m;k++)
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    for (u=0;u<n;u++)
                    {
                        for (v=0;v<n;v++)
                        {
                            arr_copy[u][v] = arr[u][v];
                        }
                    }
                    
                    if (arr_copy[i][j] == k)
                    {
                        cnt = 0;
                        rainbow_cnt = 0;
                        row = -1;
                        col = -1;
                        
                        BFS(arr_copy, n, i, j, k, &cnt, &rainbow_cnt, &row, &col, num);
                        
                        //printf("%d\n", cnt);
                        
                        if (cnt > 0)
                        {
                            if (cnt > max)
                            {
                                max_row = row;
                                max_col = col;
                                max = cnt;
                                max_num = k;
                                max_rainbow_cnt = rainbow_cnt;
                                
                                index_i = i;
                                index_j = j;
                            }
                            
                            else if (cnt == max && rainbow_cnt > max_rainbow_cnt)
                            {
                                max_row = row;
                                max_col = col;
                                max = cnt;
                                max_num = k;
                                max_rainbow_cnt = rainbow_cnt;
                                
                                index_i = i;
                                index_j = j;
                            }
                            
                            else if (cnt == max && rainbow_cnt == max_rainbow_cnt && row > max_row)
                            {
                                max_row = row;
                                max_col = col;
                                max = cnt;
                                max_num = k;
                                max_rainbow_cnt = rainbow_cnt;
                                
                                index_i = i;
                                index_j = j;
                            }
                            
                            else if (cnt == max && rainbow_cnt == max_rainbow_cnt && row == max_row && col > max_col)
                            {
                                max_row = row;
                                max_col = col;
                                max = cnt;
                                max_num = k;
                                max_rainbow_cnt = rainbow_cnt;
                                
                                index_i = i;
                                index_j = j;
                            }
                        }
                    }
                }
            }
        }
        
        if (max == 0) break;
        
        answer += max*max;
        
        BFS(arr, n, index_i, index_j, max_num, &cnt, &rainbow_cnt, &row, &col, num);

        // 중력 작용
        for (j=0;j<n;j++)
        {
            i = n-1;
            while (i > 0)
            {
                if ((arr[i][j] < -1) && (arr[i-1][j] > -1))
                {
                    u = i-1;
                    while (u < n-1 && (arr[u+1][j] < -1))
                    {
                        u++;
                    }
                    arr[u][j] = arr[i-1][j];
                    arr[i-1][j] = num;
                }
                i--;
            }
        }
        
        // 반시계방향 회전
        for (i=0, v=0;i<n, v<n;i++, v++)
        {
            for (j=0, u=n-1;j<n, u>=0;j++, u--)
            {
                arr_rotation[u][v] = arr[i][j];
            }
        }
        
        // 다시 중력 작용
        for (j=0;j<n;j++)
        {
            i = n-1;
            while (i > 0)
            {
                if ((arr_rotation[i][j] < -1) && (arr_rotation[i-1][j] > -1))
                {
                    u = i-1;
                    while (u < n-1 && (arr_rotation[u+1][j] < -1))
                    {
                        u++;
                    }
                    
                    arr_rotation[u][j] = arr_rotation[i-1][j];
                    arr_rotation[i-1][j] = num;
                }
                i--;
            }
        }
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                arr[i][j] = arr_rotation[i][j];
            }
        }
        
        num = num-3;
    }

    printf("%d", answer);
    
    return 0;
}
