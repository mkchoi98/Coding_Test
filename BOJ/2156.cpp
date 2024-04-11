//
//  main.cpp
//  2156
//
//  Created by 최민경 on 2024/04/11.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    int arr[10001];
    int dp[10001];
    
    cin >> n;
    
    for (int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    
    for (int i=3;i<=n;i++)
    {
        int num = 0;
        
        num = max(dp[i-1], dp[i-2]+arr[i]);
        num = max(num, dp[i-3]+arr[i-1]+arr[i]);
        
        dp[i] = num;
    }
    
    cout << dp[n];
    
    return 0;
}
