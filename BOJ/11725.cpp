//
//  main.cpp
//  11725
//
//  Created by 최민경 on 2024/02/08.
//

#include <iostream>
#include <vector>

using namespace std;

static int N;
static vector<int> answer;
static vector<bool> visited;
static vector<vector<int>> tree;

void DFS(int num);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    answer.resize(N+1);
    visited.resize(N+1);
    tree.resize(N+1);
    
    for (int i=0;i<N-1;i++)
    {
        int a, b;
        
        cin >> a >> b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1);
    
    for (int i=2;i<=N;i++)
    {
        cout << answer[i] << "\n";
    }
    
    return 0;
}

void DFS(int num)
{
    visited[num] = true;
    
    for (int i: tree[num])
    {
        if (!visited[i])
        {
            answer[i] = num;
            DFS(i);
        }
    }
}
