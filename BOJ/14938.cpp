#include <iostream>
#include <queue>
#include <vector>

#define MAX 987654321

using namespace std;

typedef pair<int, int> edge;

static vector<vector<edge>> adj_list;
static vector<bool> visited;
static vector<int> mdistance;
static vector<int> item;
static vector<int> max_item;
static priority_queue<edge, vector<edge>, greater<edge>> que;

static int n, m, r; // 지역의 개수 (노드 개수), 수색 범위, 길의 개수 (에지 개수)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> r;
    
    adj_list.resize(n+1);
    visited.resize(n+1);
    std::fill(visited.begin(), visited.end(), false);
    mdistance.resize(n+1);
    std::fill(mdistance.begin(), mdistance.end(), MAX);
    max_item.resize(n+1);
    item.resize(n+1);
    
    for (int i=1;i<=n;i++)
    {
        cin >> item[i];
    }
    
    for (int i=0;i<r;i++)
    {
        int a, b, I;
        
        cin >> a >> b >> I;
        
        adj_list[a].push_back({b, I});
        adj_list[b].push_back({a, I});
    }
    
    for (int i=1;i<=n;i++)
    {
        mdistance[i] = 0;
        
        que.push({0, i});
        
        while (!que.empty())
        {
            int cur_v = que.top().second;
            que.pop();
            
            if (visited[cur_v])
            {
                continue;
            }
            
            visited[cur_v] = true;
            
            for (int j=0;j<adj_list[cur_v].size();j++)
            {
                int next_v = adj_list[cur_v][j].first;
                int next_w = adj_list[cur_v][j].second;
                
                if (mdistance[next_v] > mdistance[cur_v] + next_w)
                {
                    mdistance[next_v] = mdistance[cur_v] + next_w;
                    que.push({mdistance[next_v], next_v});
                }
            }
        }
        
        for (int j=1;j<=n;j++)
        {
            if (mdistance[j] <= m)
            {
                max_item[i] += item[j];
            }
        }
        
        std::fill(visited.begin(), visited.end(), false);
        std::fill(mdistance.begin(), mdistance.end(), MAX);
    }
    
    int answer = 0;
    
    for (int i=1;i<=n;i++)
    {
        if (max_item[i] > answer)
            answer = max_item[i];
    }
    
    cout << answer;
    
    return 0;
}
