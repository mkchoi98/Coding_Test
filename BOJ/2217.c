//
//  main.c
//  2217
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int n;
    int arr[100000];
    
    scanf("%d", &n);
    
    int i;
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);
    
    int min = arr[0];
    int max = 0;
    
    int k = n;
    int w;
    
    i = 1;
    
    for (i=0;i<n;i++)
    {
        w = arr[i]*k;
        
        k--;
        
        if (max < w)
        {
            max = w;
        }
    }
    
    printf("%d", max);
    
    return 0;
}
