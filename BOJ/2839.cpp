//
//  main.cpp
//  2839
//
//  Created by 최민경 on 2024/04/10.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    
    cin >> n;
    
    int dp[5001] = {0, };
    
    dp[3] = dp[5] = 1;
    
    for (int i=6;i<=n;i++)
    {
        if (dp[i-3] && dp[i-5]) dp[i] = min(dp[i-3]+1, dp[i-5]+1);
        
        else if (dp[i-3]) dp[i] = dp[i-3]+1;
        
        else if (dp[i-5]) dp[i] = dp[i-5]+1;
    }
    
    if (dp[n] == 0) dp[n] = -1;
    
    cout << dp[n];
    
    return 0;
}
