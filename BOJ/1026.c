//
//  main.c
//  1026
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return 1;
    else if (*(int *)a > *(int *)b)
        return -1;
    else return 0;
}

int main(int argc, const char * argv[]) {
    int n, a[50], b[50];
    
    scanf("%d", &n);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &b[i]);
    }
    
    qsort(a, n, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare);
    
    int min = 0;
    
    for (i=0, j=n-1; i<n, j>=0; i++, j--)
    {
        min += a[i] * b[j];
    }
    
    printf("%d", min);
    
    return 0;
}
