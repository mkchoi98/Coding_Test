//
//  main.c
//  10974
//
//  Created by 최민경 on 2023/09/08.
//

#include <stdio.h>

void DFS(int n, int index, int start, int arr[], int visited[])
{
    int i;
    
    if (index == n)
    {
        for (i=0;i<n;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        return ;
    }
    
    for (i=1;i<=n;i++)
    {
        if (visited[i] == 0)
        {
            arr[index] = i;
            index++;
            visited[i] = 1;
            DFS(n, index, start, arr, visited);
            index--;
            visited[i] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    int arr[8];
    int visited[8] = {0,};
    int i;
    
    DFS(n, 0, 1, arr, visited);
    
    return 0;
}
