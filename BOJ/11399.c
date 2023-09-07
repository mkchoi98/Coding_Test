//
//  main.c
//  11399
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
    int n;
    
    scanf("%d", &n);
    
    int i, j;
    int p[1000];
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &p[i]);
    }
    
    qsort(p, n, sizeof(int), compare);
    
    int sum = 0;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<=i;j++)
        {
            sum += p[i];
        }
    }
    
    printf("%d", sum);
    
    return 0;
}
