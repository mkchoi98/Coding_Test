//
//  main.cpp
//  17073
//
//  Created by 최민경 on 2024/02/28.
//

#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static int N;
static long W;
static int cnt; // 리프노드 개수

void DFS(int root);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> W;
    
    tree.resize(N+1);
    visited.resize(N+1, false);
    
    for (int i=0;i<N-1;i++)
    {
        int u, v;
        
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    DFS(1);
    
    printf("%.10f", (double)W/(double)cnt);
    
    return 0;
}

void DFS(int root)
{
    int cNode = 0;
    
    visited[root] = true;
    
    for (int i: tree[root])
    {
        if (!visited[i])
        {
            cNode++;
            DFS(i);
        }
    }
    
    if (cNode == 0)
        cnt++;
}
