//
//  main.cpp
//  14940
//
//  Created by 최민경 on 2024/03/07.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int n, m;
static vector<vector<int>> arr;
static vector<vector<bool>> visited;

void BFS(int start_x, int start_y);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    arr = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m));
    
    int x, y;
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            
            if (arr[i][j] == 2)
            {
                x = i;
                y = j;
                
                arr[i][j] = 0;
            }
        }
    }
    
    BFS(x, y);
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (!visited[i][j] && arr[i][j] != 0)
            {
                arr[i][j] = -1;
            }
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

void BFS(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
 
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        for (int i=0;i<4;i++)
        {
            int next_x = cur_x+dx[i];
            int next_y = cur_y+dy[i];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && arr[next_x][next_y] == 1 && !visited[next_x][next_y])
            {
                arr[next_x][next_y] = arr[cur_x][cur_y] + 1;
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
            }
        }
    }
}
