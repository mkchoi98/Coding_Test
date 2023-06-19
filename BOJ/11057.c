#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, const char* argv[]) {
    int n;
    int dp[1001][10];
    int i, j;
    int sum = 0;

    scanf("%d", &n);

    for (i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (i = 2; i <= n; i++)
    {
        dp[i][9] = 1;

        for (j = 8; j >= 0; j--)
        {
            dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % 10007;
        }
    }

    int answer = 0;

    for (i = 0; i < 10; i++)
        answer += dp[n][i]%10007;

    printf("%d", answer % 10007);

    return 0;
}
