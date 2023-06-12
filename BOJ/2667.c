//
//  main.c
//  2667
//
//  Created by 최민경 on 2023/06/12.
//

#include <stdio.h>
#include <stdlib.h>

void DFS(int adj[][25], int n, int row, int col, int *arr, int cnt)
{
    adj[row][col] = 0;
    arr[cnt]++;
    
    //printf("%d %d\n", row, col);
    
    if (adj[row][col-1] == 1 && col-1 >= 0)
        DFS(adj, n, row, col-1, arr, cnt);
    if (adj[row][col+1] == 1 && col+1 <= n-1)
        DFS(adj, n, row, col+1, arr, cnt);
    if (adj[row-1][col] == 1 && row-1 >= 0)
        DFS(adj, n, row-1, col, arr, cnt);
    if (adj[row+1][col] == 1 && row+1 <= n-1)
        DFS(adj, n, row+1, col, arr, cnt);
    
    return ;
}

void bubble_sort(int *arr, int n)
{
    int temp;
    int i, j;
    
    for (i=0;i<n-1;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int adj[25][25];
    int arr[25] = {0};
    int i, j;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (adj[i][j] == 1)
            {
                DFS(adj, n, i, j, arr, cnt);
                //printf("\n");
                cnt++;
            }
        }
    }
    
    printf("%d\n", cnt);
    
    bubble_sort(arr, cnt);
    
    for (i=0;i<cnt;i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
