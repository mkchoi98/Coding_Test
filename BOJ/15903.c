//
//  main.c
//  15903
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(long long *)a > *(long long *)b)
        return 1;
    else if (*(long long *)a < *(long long *)b)
        return -1;
    else return 0;
}

int main(int argc, const char * argv[]) {
    int n, m;
    long long arr[1001];
    
    int i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i=0;i<n;i++)
    {
        scanf("%lld", &arr[i]);
    }
    
    long long sum = 0;
    long long num;
    
    for (i=0;i<m;i++)
    {
        qsort(arr, n, sizeof(long long), compare);
        
        num = arr[0]+arr[1];
        
        arr[0] = arr[1] = num;
    }
    
    for (j=0;j<n;j++)
    {
        sum += arr[j];
    }
    
    printf("%lld", sum);
    
    return 0;
}
