//
//  main.cpp
//  11660
//
//  Created by 최민경 on 2024/01/11.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<int>>arr(n+1, vector<int>(n+1, 0));
    vector<vector<int>>sum_arr(n+1, vector<int>(n+1, 0));
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    sum_arr[1][1] = arr[1][1];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            sum_arr[i][j] = arr[i][j] + sum_arr[i-1][j] + sum_arr[i][j-1] - sum_arr[i-1][j-1];
        }
    }
    
    int x1, y1, x2, y2;
    
    for (int i=0;i<m;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        int result = sum_arr[x2][y2] - sum_arr[x1-1][y2] - sum_arr[x2][y1-1] + sum_arr[x1-1][y1-1];
        
        cout << result << "\n";
    }
    
    return 0;
}
