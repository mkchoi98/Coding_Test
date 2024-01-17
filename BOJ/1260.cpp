//
//  main.cpp
//  1260
//
//  Created by 최민경 on 2024/01/17.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 1001

using namespace std;

static int N, M, V;
static vector<vector<int>> adj_arr;
static vector<bool> visited; // DFS
static vector<bool> discovered; // BFS

void DFS(int cur)
{
    visited[cur] = true;
    
    cout << cur << ' ';
    
    for (int i:adj_arr[cur])
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int cur)
{
    queue<int> myQueue;
    
    myQueue.push(cur);
    
    discovered[cur] = true;
    
    while (!myQueue.empty())
    {
        int now = myQueue.front();
        
        cout << now << ' ';
        
        myQueue.pop();
       
        for (int i: adj_arr[now])
        {
            if (!discovered[i])
            {
                myQueue.push(i);
                
                discovered[i] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> V;
    
    adj_arr.resize(N+1);
    
    visited = vector<bool>(N+1, false);
    discovered = vector<bool>(N+1, false);
    
    int a, b;
    
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        
        adj_arr[a].push_back(b);
        adj_arr[b].push_back(a);
    }
    
    for (int i=1;i<=N;i++)
    {
        sort(adj_arr[i].begin(), adj_arr[i].end());
    }
    
    DFS(V);
    cout << '\n';
    BFS(V);
    
    return 0;
}
