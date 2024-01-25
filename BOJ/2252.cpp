//
//  main.cpp
//  2252
//
//  Created by 최민경 on 2024/01/25.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<vector<int>> adj_list;
    vector<int> degree;
    
    int N, M;
    
    cin >> N >> M;
    
    adj_list.resize(N+1);
    degree.resize(N+1, 0);
    
    int A, B;
    
    for (int i=0;i<M;i++)
    {
        cin >> A >> B;
        
        adj_list[A].push_back(B);
        degree[B]++;
    }
    
    queue<int> que;
    
    for (int i=1;i<=N;i++)
    {
        if (degree[i] == 0)
        {
            que.push(i);
        }
    }
    
    while (!que.empty())
    {
        int num = que.front();
        
        cout << num << " ";
        
        que.pop();
        
        for (int i: adj_list[num])
        {
            degree[i]--;
            
            if (degree[i] == 0)
            {
                que.push(i);
            }
        }
        
    }
    
    return 0;
}
