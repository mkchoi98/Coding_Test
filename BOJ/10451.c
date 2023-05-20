//
//  main.c
//  10451
//
//  Created by 최민경 on 2023/05/20.
//

#include <stdio.h>
#include <stdlib.h>

void DFS(int *arr, int *visited, int start, int n)
{
    visited[start] = 1;
    
    if (visited[arr[start]] == 0)
        DFS(arr, visited, arr[start], n);
}

int main(int argc, const char * argv[]) {
    int test, N;
    int *arr;
    int i, j, k;
    int *visited;
    int cnt = 0;
    
    scanf("%d", &test);
    
    for (j=0;j<test;j++)
    {
        scanf("%d", &N);
        
        arr = (int *)malloc(sizeof(int)*(N+1));
        visited = (int *)malloc(sizeof(int)*(N+1));
        
        cnt = 0;
        
        for (i=1;i<=N;i++)
        {
            visited[i] = 0;
            scanf("%d", &arr[i]);
        }
        
        for (i=1;i<=N;i++)
        {
            if (visited[i] == 0)
            {
                DFS(arr, visited, i, N);
                
                cnt++;
            }
        }
        
        printf("%d\n", cnt);
        
        free(arr);
        free(visited);
    }
    
    return 0;
}
