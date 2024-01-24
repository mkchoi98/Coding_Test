#include <iostream>
#include <vector>

using namespace std;

static int V, E;
static vector<vector<int>>adj_list;
static vector<bool> visited;
static vector<int> check;
static bool flag;

void DFS(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int K;
    
    cin >> K;
    
    for (int i=0;i<K;i++)
    {
        cin >> V >> E;
        
        adj_list.resize(V+1);
        visited = vector<bool>(V+1, false);
        check = vector<int>(V+1);
        
        for (int j=0;j<E;j++)
        {
            int u, v;
            
            cin >> u >> v;
            
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        flag = true;
        
        for (int j=1;j<=V;j++)
        {
            DFS(j);
            
            if (!flag) break;
        }
        
        if (flag)
        {
            cout << "YES\n";
        }
        
        else
        {
            cout << "NO\n";
        }
        
        adj_list.clear();
        visited.clear();
        check.clear();
    }
    
    return 0;
}

void DFS(int start)
{
    visited[start] = true;
    
    for (int i: adj_list[start])
    {
        if (!visited[i])
        {
            check[i] = (check[start] + 1) % 2;
            DFS(i);
        }
        
        else if (check[i] == check[start])
        {
            flag = false;
        }
    }
}
