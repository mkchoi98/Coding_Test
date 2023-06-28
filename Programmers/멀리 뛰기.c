#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    int i;
    long long dp[2001];
    
    dp[1] = 1;
    dp[2] = 2;
    
    for (i=3;i<=n;i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) % 1234567;
    }
    
    answer = dp[n] % 1234567;
    
    return answer;
}
