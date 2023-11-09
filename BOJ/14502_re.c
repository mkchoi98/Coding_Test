//
//  main.c
//  14502
//
//  Created by 최민경 on 2023/11/09.
//

#include <stdio.h>

typedef struct Queue
{
    int x[81], y[81];
    int front, rear;
}Queue;

void BFS(int lab[][9], int n, int m, int start_x, int start_y)
{
    Queue que;
    
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int cur_x, cur_y, next_x, next_y;
    
    int i;
    
    que.front = que.rear = -1;
    
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
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && lab[next_x][next_y] == 0)
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                lab[next_x][next_y] = 2;
            }
        }
    }
}

void DFS(int lab[][9], int lab_copy[][9], int n, int m, int wall_cnt, int *answer)
{
    int i, j;
    int zero_cnt = 0;
    
    if (wall_cnt == 3)
    {
        
        /*for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                printf("%2d", lab[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                lab_copy[i][j] = lab[i][j];
            }
            
        }
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (lab[i][j] == 2)
                {
                    BFS(lab_copy, n, m, i, j);
                }
            }
        }
        
        zero_cnt = 0;
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (lab_copy[i][j] == 0)
                {
                    zero_cnt++;
                }
            }
        }
        
        //printf("%d\n", zero_cnt);
        
        if (zero_cnt > *answer)
        {
            *answer = zero_cnt;
        }
        
        return ;
    }
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (lab[i][j] == 0)
            {
                lab[i][j] = 1;
                wall_cnt++;
                
                DFS(lab, lab_copy, n, m, wall_cnt, answer);
                
                wall_cnt--;
                lab[i][j] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int lab[9][9] = {0,};
    int lab_copy[9][9] = {0,};
    
    scanf("%d %d", &n, &m);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d", &lab[i][j]);
            
            lab_copy[i][j] = lab[i][j];
        }
    }
    
    int answer = 0;
    
    DFS(lab, lab_copy, n, m, 0, &answer);
    
    printf("%d", answer);
    
    return 0;
}
