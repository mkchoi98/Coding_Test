//
//  main.cpp
//  11724
//
//  Created by 최민경 on 2024/01/17.
//

#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> adj_arr(1000+1, vector<int> (1001, 0));

void DFS(vector<bool> &visited, int n, int N)
{
    visited[n] = true;
    
    for (int i=1;i<=N;i++)
    {
        if (!visited[i] && adj_arr[n][i] == 1)
        {
            DFS(visited, i, N);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    int u, v;
    
    //vector<vector<int>> adj_arr(1000+1, vector<int> (1001, 0));
    vector<bool> visited(1000+1, false);
    
    for (int i=0;i<M;i++)
    {
        cin >> u >> v;
        
        adj_arr[u][v] = 1;
        adj_arr[v][u] = 1;
    }
    
    int cnt = 0;
    
    for (int i=1;i<=N;i++)
    {
        if (!visited[i])
        {
            DFS(visited, i, N);
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
