//
//  main.c
//  10844
//
//  Created by 최민경 on 2023/06/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int dp[101][10];
    int i,j;
    
    scanf("%d", &n);
    
    for (i=0;i<10;i++)
        dp[1][i] = 1;
    
    dp[1][0] = 0;
    
    for(i=2;i<=n;i++)
    {
        for (j=0;j<10;j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i-1][j+1];
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            }
        }
    }
    
    int answer = 0;
    
    for (i=0;i<10;i++)
    {
        answer = (answer + dp[n][i]) % 1000000000;
    }
    
    printf("%d", answer);
    
    return 0;
}
