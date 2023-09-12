//
//  main.c
//  14889
//
//  Created by 최민경 on 2023/09/12.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void DFS(int arr[][20], int visited[], int n, int cnt, int start, int *min)
{
    int i, j;
    int sum_link = 0;
    int sum_start = 0;
    
    if (cnt == n/2)
    {
        for (i=0;i<n;i++)
        {
            if (visited[i] == 0)
            {
                for (j=0;j<n;j++)
                {
                    if (arr[i][j] != 0 && visited[j] == 0)
                    {
                        sum_link += arr[i][j];
                    }
                }
            }
            
            if (visited[i] == 1)
            {
                for (j=0;j<n;j++)
                {
                    if (arr[i][j] != 0 && visited[j] == 1)
                    {
                        sum_start += arr[i][j];
                    }
                }
            }
        }
        
        if (abs(sum_link - sum_start) < *min)
            *min = abs(sum_link - sum_start);
        
        return ;
    }
    
    for (i=start;i<n;i++)
    {
        if (visited[i] == 0 && arr[start][i] != 0)
        {
            visited[i] = 1;
            cnt++;
            
            DFS(arr, visited, n, cnt, i, min);
            
            visited[i] = 0;
            cnt--;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int arr[20][20];
    int visited[20] = {0, };
    
    scanf("%d", &n);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int min = 200;
    
    //for (i=0;i<n;i++)
    
    DFS(arr, visited, n, 0, 0, &min);
    
    printf("%d", min);
    
    return 0;
}
