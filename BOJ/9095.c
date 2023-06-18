//
//  main.c
//  9095
//
//  Created by 최민경 on 2023/06/18.
//

#include <stdio.h>

void init(int arr[], int n)
{
    int i;
    
    for (i=0;i<=n;i++)
        arr[i] = 0;
}

int main(int argc, const char * argv[]) {
    int t, n;
    int i, j;
    int dp[12];
    
    scanf("%d", &t);
    
    for (i=0;i<t;i++)
    {
        scanf("%d", &n);
        
        init(dp, n);
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for (j=4;j<=n;j++)
        {
            dp[j] = dp[j-3] + dp[j-2] + dp[j-1];
        }
        
        printf("%d\n", dp[n]);
    }
    
    return 0;
}
