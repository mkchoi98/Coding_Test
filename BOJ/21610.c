//
//  main.c
//  21610
//
//  Created by 최민경 on 2023/11/19.
//

#include <stdio.h>

typedef struct Cloud
{
    int status; // 구름이 있던 자리인지 확인
    int water;
}Cloud;

int main(int argc, const char * argv[]) {
    int n, m;
    Cloud arr[51][51] = {0,}, arr_copy[51][51] = {0,};
    int d[101] = {0,}, s[100] = {0,};
    
    scanf("%d %d", &n, &m);
    
    int i, j, k, l;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j].water);
            
            arr[i][j].status = 0;
            
            //arr_copy[i][j].water = arr[i][j].water;
        }
    }
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d", &d[i], &s[i]);
    }
    
    // 초기 구름 위치
    arr[n-1][0].status = 1;
    arr[n-1][1].status = 1;
    arr[n-2][0].status = 1;
    arr[n-2][1].status = 1;
    
    int dir_x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dir_y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    
    int diagonal_x[4] = {-1, -1, 1, 1};
    int diagonal_y[4] = {-1, 1, 1, -1};
    
    int next_x, next_y;
    int diag_x, diag_y;
    
    for (k=0;k<m;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                arr_copy[i][j].status = arr[i][j].status;
                
                arr[i][j].status = 0;
            }
        }
        
//        for (i=0;i<n;i++)
//        {
//            for (j=0;j<n;j++)
//            {
//                printf("%3d", arr_copy[i][j].status);
//            }
//            printf("\n");
//        }
//        printf("\n");
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                // 구름 이동
                if (arr_copy[i][j].status == 1)
                {
                    next_x = i + (dir_x[d[k]-1] * s[k]);
                    next_y = j + (dir_y[d[k]-1] * s[k]);
                    
                    while (next_x < 0)
                    {
                        next_x += n;
                    }
                    
                    while (next_x >= n)
                    {
                        next_x -= n;
                    }
                    
                    while (next_y < 0)
                    {
                        next_y += n;
                    }
                    
                    while (next_y >= n)
                    {
                        next_y -= n;
                    }
                    
                    arr[next_x][next_y].status = 1;
                    
                }
            }
        }
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (arr[i][j].status == 1)
                {
                    arr[i][j].water += 1;
                }
            }
        }
        
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                arr_copy[i][j].water = arr[i][j].water;
            }
        }
        
        // 물 복사 버그
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (arr[i][j].status == 1)
                {
                    for (l=0;l<4;l++)
                    {
                        diag_x = i + diagonal_x[l];
                        diag_y = j + diagonal_y[l];
                        
                        if (diag_x >= 0 && diag_x < n && diag_y >= 0 && diag_y < n && arr_copy[diag_x][diag_y].water != 0)
                        {
                            arr[i][j].water += 1;
                        }
                    }
                }
            }
        }
        
        // 구름 생성
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (arr[i][j].status == 1)
                {
                    arr[i][j].status = 0;
                    
                    continue;
                }
                
                else if (arr[i][j].water >= 2)
                {
                    arr[i][j].water -= 2;
                    arr[i][j].status = 1;
                }
            }
        }
        
//        for (i=0;i<n;i++)
//        {
//            for (j=0;j<n;j++)
//            {
//                printf("%3d", arr[i][j].water);
//            }
//            printf("\n");
//        }
//        printf("\n");
//
//        for (i=0;i<n;i++)
//        {
//            for (j=0;j<n;j++)
//            {
//                printf("%3d", arr[i][j].status);
//            }
//            printf("\n");
//        }
//        printf("\n\n");
    }
    
    int answer = 0;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            answer += arr[i][j].water;
        }
    }
    
    printf("%d", answer);
    
    return 0;
}
