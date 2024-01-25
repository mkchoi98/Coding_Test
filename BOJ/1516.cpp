//
//  main.cpp
//  1516
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
    vector<int> time;
    vector<int> answer;
    
    int N;
    
    cin >> N;
    
    adj_list.resize(N+1);
    degree.resize(N+1, 0);
    time.resize(N+1);
    answer.resize(N+1);
    
    for (int i=1;i<=N;i++)
    {
        int b;
        
        cin >> time[i];
        
        while (1)
        {
            cin >> b;
            
            if (b == -1) break ;
            
            adj_list[b].push_back(i);
            degree[i]++;
        }
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
        int n = que.front();
        
        que.pop();
        
        for (int i: adj_list[n])
        {
            degree[i]--;
            
            answer[i] = max(answer[i], answer[n]+time[n]);
            
            if (degree[i] == 0)
            {
                que.push(i);
            }
        }
    }
    
    for (int i=1;i<=N;i++)
    {
        cout << time[i] + answer[i] << "\n";
    }
        
    return 0;
}
