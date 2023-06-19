//
//  main.c
//  11053
//
//  Created by 최민경 on 2023/06/19.
//

#include <stdio.h>

int max(int a, int b)
{
    if (a > b) return a;
    
    return b;
}

int main(int argc, const char * argv[]) {
    int n;
    int i, j;
    
    scanf("%d", &n);
    
    int arr[n];
    int dp[n];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    dp[0] = 1;
    
    for(i=1;i<n;i++)
    {
        dp[i] = 1;
        for (j=0;j<i;j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    int answer;
    
    answer = dp[0];
    
    for (i=1;i<n;i++)
    {
        if (answer < dp[i])
            answer = dp[i];
    }
    
    printf("%d", answer);
    
    return 0;
}
