//
//  main.cpp
//  14567
//
//  Created by 최민경 on 2024/01/31.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M;
static vector<vector<int>> adj_list;
static vector<int> degree;
static queue<int> que;
static vector<int> answer;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    adj_list.resize(N+1);
    degree.resize(N+1);
    answer.resize(N+1);
    
    int a, b;
    
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        
        adj_list[a].push_back(b);
        degree[b]++;
    }
  
    for (int i=1;i<=N;i++)
    {
        if (degree[i] == 0)
        {
            que.push(i);
            answer[i] = 1;
        }
    }

    int cur;
    
    while (!que.empty())
    {
        cur = que.front();
        que.pop();

        for (int i: adj_list[cur])
        {
            degree[i]--;
            
            if (degree[i] == 0)
            {
                que.push(i);
                answer[i] = answer[cur]+1;
            }
        }
    }
    
    for (int i=1;i<=N;i++)
    {
        cout << answer[i] << " ";
    }
    
    return 0;
}
