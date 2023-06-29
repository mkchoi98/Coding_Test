//
//  main.c
//  14503
//
//  Created by 최민경 on 2023/06/29.
//

#include <stdio.h>

void DFS(int adj[][50], int n, int m, int start_x, int start_y, int d)
{
    int i, j =0;
    int direction_x[4] = {0, -1, 0, 1};
    int direction_y[4] = {-1, 0, 1, 0};
    int x, y;
    int direction = 0;
    int flag = 1;
    
    if (adj[start_x][start_y] == 0)
        adj[start_x][start_y] = 2;

    while (j < 4)
    {
        x = start_x+direction_x[d];
        y = start_y+direction_y[d];
        
        if (x >= 0 && x < n && y >=0 && y < m)
        {
            flag = 1;
            if (adj[x][y] == 0)
            {
                flag = 0;

                direction = d;
                
                break;
            }
        }
        
        if (d == 0) d = 3;
        else d = d-1;
        
        j++;
    }
    
    if (!flag) // 주변에 청소가 안 된 부분이 있는 경우
    {
        {
            x = start_x+direction_x[direction];
            y = start_y+direction_y[direction];
            
            if (direction == 0) d = 3;
            else d = direction-1;
            
            if (x >= 0 && x < n && y >=0 && y < m)
            {
                if (adj[x][y] == 0)
                {
                    DFS(adj, n, m, x, y, d);
                }
            }
        }
    }
    
    if (flag) // 주변에 청소가 안 된 부분이 없는 경우
    {
        if (d == 0 && start_x+1 < n)
        {
            if (adj[start_x+1][start_y] == 2)
                DFS(adj, n, m, start_x+1, start_y, d);
            if (adj[start_x+1][start_y] == 1) return ;
        }
        
        if (d == 1 && start_y-1 >= 0 && adj[start_x][start_y-1] == 2)
        {
            if (adj[start_x][start_y-1] == 2)
                DFS(adj, n, m, start_x, start_y-1, d);
            if (adj[start_x][start_y-1] == 1) return;
        }
        
        if (d == 2 && start_x-1 >= 0 && adj[start_x-1][start_y] == 2)
        {
            if (adj[start_x-1][start_y] == 2)
                DFS(adj, n, m, start_x-1, start_y, d);
            if (adj[start_x-1][start_y] == 1) return ;
        }
        
        if (d == 3 && start_y+1 < m && adj[start_x][start_y+1] == 2)
        {
            if (adj[start_x][start_y+1] == 2)
                DFS(adj, n, m, start_x, start_y+1, d);
            if (adj[start_x][start_y+1] == 1) return ;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int r, c, d;
    int room[50][50];
    int i, j;
    int cnt = 0;
    
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d", &room[i][j]);
        }
    }
    
    DFS(room, n, m, r, c, d);
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (room[i][j] == 2) cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}
