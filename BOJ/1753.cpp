#include <iostream>
#include <queue>
#include <vector>

#define MAX 987654321

using namespace std;

// 다익스트라
typedef pair<int, int> edge;
static int V, E, K;
static vector<int> mdistance;
static vector<bool> visited;
static vector<vector<edge>> adj_list;
static priority_queue<edge, vector<edge>, greater<edge>> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E >> K;
    
    mdistance.resize(V+1);
    std::fill(mdistance.begin(), mdistance.end(), MAX);
    visited.resize(V+1);
    std::fill(visited.begin(), visited.end(), false);
    adj_list.resize(V+1);
    
    int u, v, w;
    
    for (int i=0;i<E;i++)
    {
        cin >> u >> v >> w;
        
        adj_list[u].push_back({v, w});
    }
    
    que.push({0, K}); // 가중치 0, 시작 노드 K
    mdistance[K] = 0; // 시작 노드 거리 0
    
    while (!que.empty())
    {
        edge cur = que.top();
        
        que.pop();
        
        int c_v = cur.second;
        
        if (visited[c_v])
        {
            continue;
        }
        
        visited[c_v] = true;
        
        for (int i=0;i<adj_list[c_v].size();i++)
        {
            int next_v = adj_list[c_v][i].first;
            int next_w = adj_list[c_v][i].second;
            
            if (mdistance[next_v] > mdistance[c_v] + next_w)
            {
                mdistance[next_v] = mdistance[c_v] + next_w;
                que.push({mdistance[next_v], next_v});
            }
        }
    }
    
    for (int i=1;i<=V;i++)
    {
        if (visited[i])
        {
            cout << mdistance[i] << "\n";
        }
        
        else
        {
            cout << "INF\n";
        }
    }
    
    return 0;
}
