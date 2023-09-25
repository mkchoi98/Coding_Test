//
//  main.c
//  1158
//
//  Created by 최민경 on 2023/09/25.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, k;
    
    scanf("%d %d", &n, &k);
    
    if (n == 1)
    {
        printf("<1>");
        
        return 0;
    }
    
    int i, j;
    int arr[5001];
    
    for (i=1;i<=n;i++)
    {
        arr[i] = i;
    }
    
    int cnt = 0;
    
    int first = 0, last = 0;
    
    i = 1;
    j = k;
    
    printf("<%d, ", arr[k]);
    arr[k] = 0;
    
    while (i < n)
    {
        if (i == 0) first = 1;
        else if (i == n-1) last = 1;
        
        cnt = 1;
        
        while (cnt <= k)
        {
            j++;
            
            if (j == n+1) j = 1;
            
            if (arr[j] == 0) continue;
            else cnt++;
        }
        
        if (last)
        {
            printf("%d>", arr[j]);
            arr[j] = 0;
            last = 0;
        }
        
        else
        {
            printf("%d, ", arr[j]);
            arr[j] = 0;
        }
        
        i++;
    }
    
    return 0;
}
