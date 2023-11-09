//
//  main.c
//  15686
//
//  Created by 최민경 on 2023/11/09.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Visited
{
    int x, y;
    int status;
}Visited;

void DFS(int arr[][51], int arr_copy[][51], Visited visited[], int n, int m, int chicken_cnt, int cnt, int *answer, int start)
{
    int i, j, s, t;
    
    if (cnt == m)
    {
        int sum = 0;
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (arr_copy[i][j] == 1)
                {
                    int dis_x = 0;
                    int dis_y = 0;
                    int dis = 0;
                    
                    int min_dis = 100000;
                    
                    for (s=0;s<n;s++)
                    {
                        for (t=0;t<n;t++)
                        {
                            if (arr_copy[s][t] == 2)
                            {
                                dis_x = i-s;
                                dis_y = j-t;
                                
                                dis = abs(dis_x) + abs(dis_y);
                                
                                if (dis < min_dis && dis != 0)
                                {
                                    min_dis = dis;
                                }
                            }
                        }
                    }
                    
                    sum += min_dis;
                }
            }
        }
        
        if (sum < *answer)
        {
            *answer = sum;
        }
        
        return ;
    }
    
    for (i=start;i<=chicken_cnt;i++)
    {
        if (visited[i].status == 0)
        {
            visited[i].status = 1;
            cnt++;
            arr_copy[visited[i].x][visited[i].y] = 2;
            start++;
            
            DFS(arr, arr_copy, visited, n, m, chicken_cnt, cnt, answer, start);
            
            cnt--;
            arr_copy[visited[i].x][visited[i].y] = 0;
            visited[i].status = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int arr[51][51] = {0,}, arr_copy[51][51] = {0,};
    int chicken_cnt = -1;
    
    Visited visited[51];
    
    scanf("%d %d", &n, &m);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
            
            if (arr[i][j] == 1)
            {
                arr_copy[i][j] = 1;
            }
            
            else if (arr[i][j] == 2)
            {
                chicken_cnt++;
                
                visited[chicken_cnt].x = i;
                visited[chicken_cnt].y = j;
            }
        }
    }
    
    for (i=0;i<=chicken_cnt;i++) visited[i].status = 0;
    
    int answer = 100000;
    
    DFS(arr, arr_copy, visited, n, m, chicken_cnt, 0, &answer, 0);
    
    printf("%d", answer);
    
    return 0;
}
