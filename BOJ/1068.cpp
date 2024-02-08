//
//  main.cpp
//  1068
//
//  Created by 최민경 on 2024/02/08.
//

#include <iostream>
#include <vector>

using namespace std;

static int N;
static vector<bool> visited;
static vector<vector<int>> tree;
static int remove_node;
static int root;
static int answer;

void DFS(int root);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    visited.resize(N);
    std::fill(visited.begin(), visited.end(), false);
    tree.resize(N);
    
    for (int i=0;i<N;i++)
    {
        int p;
        
        cin >> p;
       
        if (p == -1)
        {
            root = i;
        }
        
        else
        {
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
    }
    
    cin >> remove_node;
    
    if (remove_node == root)
        answer = 0;
    
    else DFS(root);
    
    cout << answer;
    
    return 0;
}

void DFS(int root)
{
    visited[root] = true;
    int child_node = 0;
    
    for (int i: tree[root])
    {
        if (!visited[i] && i != remove_node)
        {
            DFS(i);
            child_node++;
        }
    }

    if (child_node == 0)
        answer++;
}
