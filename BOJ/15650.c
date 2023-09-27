//
//  main.c
//  15650
//
//  Created by 최민경 on 2023/09/27.
//

#include <stdio.h>

void DFS(int n, int m, int arr[], int visited[], int index, int start)
{
    int i;
    
    if (index == m)
    {
        for (i=0;i<index;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    for (i=start;i<=n;i++)
    {
        if (visited[i] == 0)
        {
            arr[index++] = i;
            visited[i] = 1;
            start++;
            
            DFS(n, m, arr, visited, index, start);
            
            visited[i] = 0;
            index--;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int arr[9];
    int visited[9] = {0, };
    
    scanf("%d %d", &n, &m);
    
    DFS(n, m, arr, visited, 0, 1);
    
    return 0;
}
