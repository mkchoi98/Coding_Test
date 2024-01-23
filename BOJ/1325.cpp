//
//  main.cpp
//  1325
//
//  Created by 최민경 on 2024/01/23.
//

#include <iostream>
#include <queue>

using namespace std;

static int N, M;
static vector<vector<int>> adj_list;
static vector<bool> discovered;

void BFS(int start);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    adj_list.resize(N+1);
    
    int A, B;
    
    for (int i=0;i<M;i++)
    {
        cin >> A >> B;
        
        adj_list[B].push_back(A);
    }
    
    int cnt;
    int max = 0;
    
    vector<int> index_cnt(N+1, 0);
    
    for (int i=1;i<=N;i++)
    {
        cnt = 0;
        discovered = vector<bool>(N+1, false);
        
        BFS(i);
        
        for (int j=1;j<=N;j++)
        {
            if (discovered[j]) cnt++;
        }
        
        index_cnt[i] = cnt;
        
        if (cnt >= max)
        {
            max = cnt;
        }
    }

    for (int i=1;i<=N;i++)
    {
        if (index_cnt[i] == max)
        {
            cout << i << "\n";
        }
    }
    
    return 0;
}

void BFS(int start)
{
    queue<int> que;
    
    que.push(start);
    
    discovered[start] = true;
    
    while (!que.empty())
    {
        int cur = que.front();
        
        que.pop();
        
        for (int i: adj_list[cur])
        {
            if (!discovered[i])
            {
                que.push(i);
                discovered[i] = true;
            }
        }
    }
}
