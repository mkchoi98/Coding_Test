//
//  main.cpp
//  11403
//
//  Created by 최민경 on 2024/01/29.
//

#include <iostream>
#include <vector>

using namespace std;

static int n;
static vector<vector<int>> adj_arr;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    adj_arr.resize(n);
    
    for (int i=0;i<n;i++)
    {
        adj_arr[i].resize(n);
    }
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> adj_arr[i][j];
        }
    }
    
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (adj_arr[i][k] == 1 && adj_arr[k][j] == 1)
                {
                    adj_arr[i][j] = 1;
                }
            }
        }
    }
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout << adj_arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
