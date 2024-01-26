//
//  main.cpp
//  1916
//
//  Created by 최민경 on 2024/01/26.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX 987654321

using namespace std;

typedef pair<int, int> edge;

static int N, M;
static vector<int> m; // 최소 비용 배열
static vector <bool> visited;
static vector<vector<edge>> adj_list;
static priority_queue<edge, vector<edge>, greater<edge>> que;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> M;
    
    m.resize(N+1);
    std::fill(m.begin(), m.end(), MAX);
    visited.resize(N+1);
    std::fill(visited.begin(), visited.end(), false);
    adj_list.resize(N+1);
    
    int s, d, f;
    
    for (int i=0;i<M;i++)
    {
        cin >> s >> d >> f;
        
        adj_list[s].push_back({d, f});
    }
    
    int want_s, want_d;

    cin >> want_s >> want_d;

    m[want_s] = 0;
    que.push({0, want_s});

    while (!que.empty())
    {
        edge cur = que.top();
        
        que.pop();
        
        int cur_s = cur.second;
        
        if (visited[cur_s])
        {
            continue;
        }
        
        visited[cur_s] = true;
        
        for (int i=0;i<adj_list[cur_s].size();i++)
        {
            int next_s = adj_list[cur_s][i].first;
            int next_f = adj_list[cur_s][i].second;
            
            if (m[next_s] > m[cur_s] + next_f)
            {
                m[next_s] = m[cur_s] + next_f;
                
                que.push({m[next_s], next_s});
            }
        }
    }

    cout << m[want_d];
    
    return 0;
}
