//
//  main.cpp
//  1389
//
//  Created by 최민경 on 2024/01/29.
//

#include <iostream>
#include <vector>

using namespace std;

static int n, m;
static vector<vector<int>> adj_arr;
static vector<int> mdistance;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    adj_arr = vector<vector<int>>(n+1, vector<int>(n+1, 987654321));
    mdistance.resize(n+1);
    
    for (int i=0;i<m;i++)
    {
        int a, b;
        
        cin >> a >> b;
        
        adj_arr[a][b] = 1;
        adj_arr[b][a] = 1;
    }
    
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
//                if (adj_arr[i][j] == 1)
//                {
//                    mdistance[i] = 1;
//                }
                if (adj_arr[i][j] > adj_arr[i][k] + adj_arr[k][j])
                {
                    adj_arr[i][j] = adj_arr[i][k] + adj_arr[k][j];
                }
            }
        }
    }
    
    int min = 987654321;
    int answer = 0;
    
    for (int i=1;i<=n;i++)
    {
        int sum = 0;
        for (int j=1;j<=n;j++)
        {
            sum += adj_arr[i][j];
        }
        if (min > sum)
        {
            answer = i;
            min = sum;
        }
    }
    
    cout << answer;
    
    return 0;
}
