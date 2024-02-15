//
//  main.cpp
//  1697
//
//  Created by 최민경 on 2024/02/15.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int n, k;
static vector<int> visited;

void BFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;

    visited.resize(200001, 0);
    
    BFS();
    
    cout << visited[k]-1;
    
    return 0;
}

void BFS()
{
    queue<int> que;
    
    que.push(n);
    
    visited[n] = 1;
    
    while (!que.empty())
    {
        int cur = que.front();
        
        que.pop();
        
        if (cur-1 >= 0 && visited[cur-1] == 0)
        {
            que.push(cur-1);
            visited[cur-1] = visited[cur] + 1;
        }
        
        if (cur+1 <= 200000 && visited[cur+1] == 0)
        {
            que.push(cur+1);
            visited[cur+1] = visited[cur] + 1;
        }
        
        if (cur*2 <= 200000 && visited[cur*2] == 0)
        {
            que.push(cur*2);
            visited[cur*2] = visited[cur] + 1;
        }
        
        if (visited[k] != 0) break;
    }
        
}
