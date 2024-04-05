//
//  main.cpp
//  1987
//
//  Created by 최민경 on 2024/04/05.
//

#include <iostream>

using namespace std;

static int R, C;
static char arr[20][20];
static bool visited[26];
static int answer;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(char c, int , int, int);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;
    
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    DFS(arr[0][0], 0, 0, 1);
    
    cout << answer;
    
    return 0;
}

void DFS(char c, int x, int y, int cnt)
{
    answer = max(answer, cnt);
    
    visited[arr[x][y]-'A'] = true;
    
    for (int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[arr[nx][ny]-'A'])
        {
            DFS(arr[nx][ny], nx, ny, cnt+1);
            visited[arr[nx][ny]-'A'] = false;
        }
    }
}
