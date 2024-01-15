//
//  main.cpp
//  2167
//
//  Created by 최민경 on 2024/01/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<vector<int>> arr(N+1, vector<int>(M+1, 0));
    
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=M;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    vector<vector<int>> sum_arr(N+1, vector<int>(M+1, 0));
    
    sum_arr[1][1] = arr[1][1];
    
    for (int i=2;i<=N;i++)
    {
        sum_arr[i][1] = sum_arr[i-1][1] + arr[i][1];
    }
    
    for (int i=2;i<=M;i++)
    {
        sum_arr[1][i] = sum_arr[1][i-1] + arr[1][i];
    }
    
    for (int i=2;i<=N;i++)
    {
        for (int j=2;j<=M;j++)
        {
            sum_arr[i][j] = sum_arr[i][j-1] + sum_arr[i-1][j] + arr[i][j] - sum_arr[i-1][j-1];
        }
    }
    
    int K;
    
    cin >> K;
    
    int x1, y1, x2, y2;
    
    for (int i=0;i<K;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        int result = 0;
        
        result = sum_arr[x2][y2] - (sum_arr[x1-1][y2] + sum_arr[x2][y1-1]) + sum_arr[x1-1][y1-1];
        
        cout << result << '\n';
    }
    
    return 0;
}
