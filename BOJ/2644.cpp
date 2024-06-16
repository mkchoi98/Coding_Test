//
//  main.cpp
//  2644
//
//  Created by 최민경 on 2024/06/16.
//

#include <iostream>
#include <queue>

using namespace std;

static int n, m;
static int a, b;
static int answer = 1;
static vector<vector<int>> adj_list;
static vector<int> visited;

void BFS()
{
    queue<int> myQueue;
    
    myQueue.push(a);
    visited[a] = 1;
    
    while (!myQueue.empty())
    {
        int cur = myQueue.front();
        
        myQueue.pop();
        
        for (int i: adj_list[cur])
        {
            if (visited[i] == 0)
            {
                visited[i] = visited[cur] + 1;
                myQueue.push(i);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    cin >> a >> b;
    cin >> m;
    
    adj_list.resize(n+1);
    visited.resize(n+1);
    
    for (int i=0;i<m;i++)
    {
        int x, y;
        
        cin >> x >> y;
        
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    BFS();
    
    cout << visited[b]-1;
    
    return 0;
}
