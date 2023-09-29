//
//  main.c
//  15652
//
//  Created by 최민경 on 2023/09/27.
//

#include <stdio.h>

void DFS(int n, int m, int arr[], int index, int start)
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
        
        for (i=start;i<=n;i++)
        {
            arr[index] = i;
            index++;
            
            DFS(n, m, arr, index, start++);
            
            index--;
        }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int arr[9];
    
    scanf("%d %d", &n, &m);
    
    DFS(n, m, arr, 0, 1);
    
    return 0;
}
