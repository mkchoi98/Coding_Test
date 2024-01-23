//
//  main.cpp
//  18352
//
//  Created by 최민경 on 2024/01/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M, K, X;
vector<vector<int>> adj_arr;
vector<int> discovered;

void BFS(int start);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K >> X;
    
    int A, B;
    
    adj_arr.resize(N+1);
    discovered = vector<int> (N+1, 0);
    
    for (int i=0;i<M;i++)
    {
        cin >> A >> B;
        
        adj_arr[A].push_back(B);
    }
    
    BFS(X);
    
    int cnt = 0;
    
    for (int i=1;i<=N;i++)
    {
        if (discovered[i] - 1 == K)
        {
            cout << i << "\n";
            
            cnt++;
        }
    }
    
    if (cnt == 0) cout << -1;
    
    return 0;
}

void BFS(int start)
{
    queue<int> que;
    
    que.push(start);
    
    discovered[start] = 1;
    
    while (!que.empty())
    {
        int cur = que.front();
        
        que.pop();
        
        for (int i:adj_arr[cur])
        {
            if (discovered[i] == 0)
            {
                discovered[i] = discovered[cur] + 1;
                que.push(i);
            }
        }
    }
}
