//
//  main.c
//  17141
//
//  Created by 최민경 on 2023/11/13.
//

#include <stdio.h>

typedef struct Visited
{
    int x, y;
    int status;
}Visited;

typedef struct Queue
{
    int x[2500], y[2500];
    int front, rear;
}Queue;

void BFS(Queue que, int lab[][51], int n)
{
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int cur_x, cur_y, next_x, next_y;
    
    int i;
    
    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];
        cur_y = que.y[que.front];
        
        for (i=0;i<4;i++)
        {
            next_x = cur_x + dir_x[i];
            next_y = cur_y + dir_y[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && (lab[next_x][next_y] == 0 || lab[next_x][next_y] == 2))
            {
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
                
                lab[next_x][next_y] = lab[cur_x][cur_y] + 1;
            }
        }
    }
}

void DFS(Visited visited[], int lab[][51], int lab_copy[][51], int virus_cnt, int n, int m, int cnt, int start, int *answer)
{
    Queue que;
    int i, j;
    
    if (cnt == m)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                lab_copy[i][j] = lab[i][j];
            }
        }
        
        que.front = que.rear = -1;
        
        for (i=0;i<virus_cnt;i++)
        {
            if (visited[i].status == 1)
            {
                que.x[++que.rear] = visited[i].x;
                que.y[que.rear] = visited[i].y;
            }
        }
        
        BFS(que, lab_copy, n);
        
        int max = 0;
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (lab_copy[i][j] > max)
                {
                    max = lab_copy[i][j];
                }
                
                if (lab_copy[i][j] == 0)
                {
                    break;
                }
            }
            
            if (j != n) break;
        }
        
        if (i < n && j < n)
        {
            return ;
        }
        
        else if (*answer > max && *answer != -1)
        {
            *answer = max;
        }
        
        return ;
    }
    
    for (i=start;i<virus_cnt;i++)
    {
        if (visited[i].status == 0)
        {
            visited[i].status = 1;
            lab[visited[i].x][visited[i].y] = 10000;
            
            cnt++;
            start++;
            
            DFS(visited, lab, lab_copy, virus_cnt, n, m, cnt, start, answer);
            
            cnt--;
            
            lab[visited[i].x][visited[i].y] = 0;
            visited[i].status = 0;
        }
    }

}

int main(int argc, const char * argv[]) {
    int n, m;
    int lab[51][51] = {0,}, lab_copy[51][51] = {0,};
    int virus_cnt = 0;
    
    Visited visited[51];
    
    scanf("%d %d", &n, &m);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &lab[i][j]);
            lab_copy[i][j] = lab[i][j];
            
            if (lab[i][j] == 2)
            {
                visited[virus_cnt].x = i;
                visited[virus_cnt].y = j;
                
                lab_copy[i][j] = lab[i][j] = 0;
                
                virus_cnt++;
            }
        }
    }
    
    for (i=0;i<virus_cnt;i++) visited[i].status = 0;
    
    int answer = 987654;
    
    DFS(visited, lab, lab_copy, virus_cnt, n, m, 0, 0, &answer);
    
    if (answer == 987654) printf("-1");
    else printf("%d", answer-10000);
    
    return 0;
}
