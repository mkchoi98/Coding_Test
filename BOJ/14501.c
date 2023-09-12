//
//  main.c
//  14501
//
//  Created by 최민경 on 2023/09/12.
//

#include <stdio.h>

void DFS(int t[], int p[], int n, int start, int sum, int *max)
{
    int i;
    
    if (start <= n)
    {
        if (sum > *max) *max = sum;
    }
    
    else return ;
    
    for (i=start;i<n;i++)
    {
        if (i+t[i] <= n)
        {
            sum += p[i];
            DFS(t, p, n, i+t[i], sum, max);
            sum -= p[i];
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int p[16] = {0,}, t[16] = {0,};
    
    scanf("%d", &n);
    
    int i;
    
    for (i=0;i<n;i++)
    {
        scanf("%d %d", &t[i], &p[i]);
    }
    
    int max = 0, sum;
    
    DFS(t, p, n, 0, 0, &max);
    
    printf("%d", max);
    
    return 0;
}

