#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

static vector<bool> visited;

void BFS(int n, vector<vector<int>> &computers, int start);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited = vector<bool>(n, false);
    
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            BFS(n, computers, i);
            answer++;
        }
    }
    
    //answer = max - 9999;
    
    return answer;
}

void BFS(int n, vector<vector<int>> &computers, int start)
{
    queue<int> que;
    
    que.push(start);
    
    visited[start] = true;
    
    while (!que.empty())
    {
        int cur= que.front();
        
        que.pop();
        
        for (int i=0;i<n;i++)
        {
            if (computers[cur][i] == 1 && !visited[i])
            {
                que.push(i);
                visited[i] = true;
            }
        }
    }
}
