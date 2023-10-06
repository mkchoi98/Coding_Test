//
//  main.c
//  15657
//
//  Created by 최민경 on 2023/10/06.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else return 0;
}

void DFS(int n, int m, int num[], int arr[], int index, int start)
{
    int i;
    
    if (index == m)
    {
        for (i=0;i<m;i++) printf("%d ", arr[i]);
        
        printf("\n");
        
        return ;
    }
    
    for (i=start;i<n;i++)
    {
        arr[index] = num[i];
    
        index++;
        
        DFS(n, m, num, arr, index, i);
        
        index--;
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int num[8], arr[8];
    
    scanf("%d %d", &n, &m);
    
    int i;
    
    for (i=0;i<n;i++) scanf("%d", &num[i]);
    
    qsort(num, n, sizeof(int), compare);
    
    DFS(n, m, num, arr, 0, 0);
    
    return 0;
}
