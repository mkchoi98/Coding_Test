//
//  main.c
//  11727
//
//  Created by 최민경 on 2023/06/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    int dp[n];
    int i;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    
    for (i=3;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }
    
    printf("%d", dp[n]);
    
    return 0;
}
