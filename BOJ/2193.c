//
//  main.c
//  2193
//
//  Created by 최민경 on 2023/06/18.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int i;
    long dp[91];
    
    scanf("%d", &n);
    
    dp[1] = 1;
    dp[2] = 1;
    
    for (i=3;i<=n;i++)
        dp[i] = dp[i-2] + dp[i-1];
    
    printf("%ld", dp[n]);
    
    return 0;
}
