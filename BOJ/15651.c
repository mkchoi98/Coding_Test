//
//  main.c
//  15651
//
//  Created by 최민경 on 2023/09/27.
//

#include <stdio.h>

void DFS(int n, int m, int arr[], int index)
{
    int i;
    
    if (index == m)
    {
        for (i=0;i<index;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        return ;
    }
    
    for (i=1;i<=n;i++)
    {
        arr[index] = i;
        index++;
        
        DFS(n, m, arr, index);
        
        index--;
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int arr[8];
    
    scanf("%d %d", &n, &m);
    
    DFS(n, m, arr, 0);
    
    return 0;
}
