//
//  main.cpp
//  11404
//
//  Created by 최민경 on 2024/01/29.
//

#include <iostream>
#include <vector>

using namespace std;

static int n, m;
static vector<vector<int>> adj_arr;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    adj_arr = vector<vector<int>>(n+1, vector<int>(n+1));
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i == j)
            {
                adj_arr[i][j] = 0;
            }
            
            else
            {
                adj_arr[i][j] = 987654321;
            }
        }
    }
    
    for (int i=0;i<m;i++)
    {
        int s, e, w;
        
        cin >> s >> e >> w;
        
        if (adj_arr[s][e] > w) adj_arr[s][e] = w;
    }
    
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (adj_arr[i][j] > adj_arr[i][k] + adj_arr[k][j])
                {
                    adj_arr[i][j] = adj_arr[i][k] + adj_arr[k][j];
                }
            }
        }
    }
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (adj_arr[i][j] == 987654321)
            {
                cout << "0 ";
            }
            
            else
            {
                cout << adj_arr[i][j] << " ";
            }
        }
        
        cout << "\n";
    }
    
    return 0;
}
