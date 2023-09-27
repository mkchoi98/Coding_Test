//
//  main.c
//  15649
//
//  Created by 최민경 on 2023/09/27.
//

#include <stdio.h>

void DFS(int n, int m, int visited[], int index, int arr[])
{
    int i;
    
    if (index == m)
    {
        for (i=0;i<index;i++)
        {
            printf("%d ", arr[i]);
        }
        
        printf("\n");
        
        return;
    }
  
    for (i=1;i<=n;i++)
    {
        if (visited[i] == 0)
        {
            arr[index++] = i;
            visited[i] = 1;
            
            DFS(n, m, visited, index, arr);
            
            visited[i] = 0;
            index--;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int visited[9] = {0, };
    int arr[9];
    
    scanf("%d %d", &n, &m);
    
    DFS(n, m, visited, 0, arr);
    
    return 0;
}
