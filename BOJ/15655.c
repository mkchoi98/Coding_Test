//
//  main.c
//  15655
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

void DFS(int n, int m, int num[], int visited[], int arr[], int index, int start)
{
    int i;
    
    if (index == m)
    {
        for (i=0;i<m;i++) printf("%d ", arr[i]);
        
        printf("\n");
    }
    
    for (i=start;i<n;i++)
    {
        arr[index] = num[i];
        
        if (visited[i] == 0)
        {
            index++;
            visited[i] = 1;
            
            DFS(n, m, num, visited, arr, index, i);
            
            visited[i] = 0;
            index--;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int num[8], arr[8];
    int visited[8] = {0, };
    
    scanf("%d %d", &n, &m);
    
    int i;
    
    for (i=0;i<n;i++) scanf("%d", &num[i]);
    
    qsort(num, n, sizeof(int), compare);
    
    DFS(n, m, num, visited, arr, 0, 0);
    
    return 0;
}
