#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int r, c, t;
    int room[51][51] = {0,}, room_copy[51][51] = {0,};
    int machine1 = 0, machine2 = 0;
    
    scanf("%d %d %d", &r, &c, &t);

    int i, j;

    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            scanf("%d", &room[i][j]);

            if (room[i][j] == -1)
            {
                machine2 = i;
            }
        }
    }

    machine1 = machine2-1;

    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    int next_x, next_y;

    int k, time;

    for (time=0;time<t;time++)
    {
        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                room_copy[i][j] = room[i][j];
            }
        }

        // 미세먼지 확산
        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                if (room_copy[i][j] >= 5)
                {
                    for (k=0;k<4;k++)
                    {
                        next_x = i + dir_x[k];
                        next_y = j + dir_y[k];

                        if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c && room_copy[next_x][next_y] != -1)
                        {
                            room[next_x][next_y] += room_copy[i][j] / 5;
                            room[i][j] -= room_copy[i][j] / 5;
                        }
                    }
                }
            }
        }

        for (i=machine1-2;i>=0;i--)
        {
            room[i+1][0] = room[i][0];
        }
        
        for (i=1;i<c;i++)
        {
            room[0][i-1] = room[0][i];
        }
        
        for (i=1;i<=machine1;i++)
        {
            room[i-1][c-1] = room[i][c-1];
        }
        
        for (i=c-2;i>=1;i--)
        {
            room[machine1][i+1] = room[machine1][i];
        }
        
        room[machine1][1] = 0;
        
        
        for (i=machine2+2;i<r;i++)
        {
            room[i-1][0] = room[i][0];
        }
        
        for (i=1;i<c;i++)
        {
            room[r-1][i-1] = room[r-1][i];
        }
        
        for (i=r-2;i>=machine2;i--)
        {
            room[i+1][c-1] = room[i][c-1];
        }
        
        for (i=c-2;i>=1;i--)
        {
            room[machine2][i+1] = room[machine2][i];
        }
        
        room[machine2][1] = 0;
    }
    
    int answer = 0;
        
        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                if (room[i][j] != -1)
                {
                    answer += room[i][j];
                }
            }
        }
        
        printf("%d", answer);
    
    return 0;
}

