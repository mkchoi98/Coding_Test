//
//  main.cpp
//  7576
//
//  Created by 최민경 on 2024/03/07.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int n, m;
static vector<vector<int>> tomato;
static queue<pair<int, int>> q;
static vector<vector<bool>> visited;

void BFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n;
    
    tomato = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m));
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> tomato[i][j];
            
            if (tomato[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    BFS();
    
    int max = 0;
    bool flag = false;
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (tomato[i][j] != -1 && !visited[i][j])
            {
                flag = true;
            }
            
            else
            {
                if (tomato[i][j] > max)
                {
                    max = tomato[i][j];
                }
            }
        }
    }
    
    if (!flag) cout << max-1;
    else cout << "-1";
    
    return 0;
}

void BFS()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        for (int i=0;i<4;i++)
        {
            int next_x = cur_x+dx[i];
            int next_y = cur_y+dy[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y] && tomato[next_x][next_y] == 0)
            {
                q.push({next_x, next_y});
                visited[next_x][next_y] = true;
                tomato[next_x][next_y] = tomato[cur_x][cur_y] + 1;
            }
        }
    }
}
