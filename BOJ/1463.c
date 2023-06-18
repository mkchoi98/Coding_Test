//
//  main.c
//  1463
//
//  Created by 최민경 on 2023/06/18.
//

#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    
    return b;
}

int main(int argc, const char * argv[]) {
    int n;
    int i;
    
    scanf("%d", &n);
    
    int dp[n+1];
    
    dp[2] = 1;
    dp[3] = 1;
    
    for(i=4;i<=n;i++)
    {
        dp[i] = dp[i-1]+1;
        
        if (i%2 == 0)
        {
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        
        if (i%3 == 0)
        {
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }
    
    printf("%d", dp[n]);
    
    return 0;
}
