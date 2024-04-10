//
//  main.cpp
//  2579
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
    
    int step[301] = {0, };
    int dp[301] = {0, };
    
    for (int i=1;i<=n;i++)
    {
        cin >> step[i];
    }
    
    dp[1] = step[1];
    dp[2] = dp[1]+step[2];
    dp[3] = max(step[1]+step[3], step[2]+step[3]);
    
    for (int i=4;i<=n;i++)
    {
        dp[i] = max(dp[i-2]+step[i], dp[i-3]+step[i-1]+step[i]);
    }
    
    cout << dp[n];
   
    return 0;
}
