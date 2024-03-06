//
//  main.cpp
//  2178
//
//  Created by 최민경 on 2024/03/06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

static int n, m;
static vector<vector<long>> arr;
static vector<vector<bool>> visited;

void BFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    arr = vector<vector<long>>(n, vector<long>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    
    for (int i=0;i<n;i++)
    {
        string row;
        
        cin >> row;
        
        for (int j=0;j<m;j++)
        {
            arr[i][j] = row[j] -'0';
        }
    }
    
    BFS();
    
    cout << arr[n-1][m-1];
    
    return 0;
}

void BFS()
{
    queue<pair<int, int>> q; // x, y
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        for (int i=0;i<4;i++)
        {
            int next_x = cur_x+dx[i];
            int next_y = cur_y+dy[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y] && arr[next_x][next_y] != 0)
            {
                q.push({next_x, next_y});
                visited[next_x][next_y] = true;
                arr[next_x][next_y] = arr[cur_x][cur_y] + 1;
            }
        }
    }
}
