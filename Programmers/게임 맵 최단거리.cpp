#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> &maps, int n, int m);

int solution(vector<vector<int> > maps)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    BFS(maps, n, m);
    
    if (maps[n-1][m-1] == 1) answer = -1;
    else answer = maps[n-1][m-1] - 99;
    
    return answer;
}

void BFS(vector<vector<int>> &maps, int n, int m)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int, int>> que;
    
    que.push({0, 0});
    
    maps[0][0] = 100;
    
    while (!que.empty())
    {
        int cur_x = que.front().first;
        int cur_y = que.front().second;
        
        que.pop();
        
        for (int i=0;i<4;i++)
        {
            int next_x = cur_x+dx[i];
            int next_y = cur_y+dy[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && maps[next_x][next_y] == 1)
            {
                maps[next_x][next_y] = maps[cur_x][cur_y] + 1;
                que.push({next_x, next_y});
            }
        }
    }
}
