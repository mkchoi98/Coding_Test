//
//  main.cpp
//  1005
//
//  Created by 최민경 on 2024/01/31.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, N, K;
    vector<int> D;
    vector<vector<int>> adj_list;
    vector<int> degree;
    vector<int> answer;
    queue<int> que;
    
    cin >> T;
    
    for (int t=0;t<T;t++)
    {
        cin >> N >> K;
        
        D.resize(N+1);
        adj_list.resize(N+1);
        degree.resize(N+1);
        answer.resize(N+1);
        
        for (int i=1;i<=N;i++)
        {
            cin >> D[i];
        }
        
        for (int i=0;i<K;i++)
        {
            int X, Y;
            
            cin >> X >> Y;
            
            adj_list[X].push_back(Y);
            degree[Y]++;
        }
        
        int W;
        
        cin >> W;
        
        for (int i=1;i<=N;i++)
        {
            if (degree[i] == 0)
            {
                que.push(i);
                answer[i] = D[i];
            }
        }
        
        while (!que.empty())
        {
            int cur = que.front();
            
            que.pop();
            
            for (int i: adj_list[cur])
            {
                degree[i]--;
                
                answer[i] = max(answer[i], answer[cur]+D[i]);
                
                if (degree[i] == 0)
                {
                    que.push(i);
                }
            }
        }
        
        cout << answer[W] << "\n";
        
        D.clear();
        adj_list.clear();
        answer.clear();
        degree.clear();
    }
    
    return 0;
}
