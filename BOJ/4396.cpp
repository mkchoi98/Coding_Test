//
//  main.cpp
//  4396
//
//  Created by 최민경 on 2024/03/06.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    vector<vector<char>> arr(n, vector<char>(n)); // 지뢰 위치
    vector<vector<char>> game(n, vector<char>(n)); // 게임 진행 상황
    vector<vector<char>> answer(n, vector<char>(n));
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> game[i][j];
        }
    }
    
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    bool flag = false;
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (game[i][j] == 'x')
            {
                if (arr[i][j] == '*')
                {
                    flag = true;
                    
                    //break;
                }
                
                int num = 0;
                
                for (int k=0;k<8;k++)
                {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    
                    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == '*')
                    {
                        num++;
                    }
                }
                
                answer[i][j] = num + '0';
            }
            
            else answer[i][j] = '.';
        }
    }
    
    if (flag)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (arr[i][j] == '*') cout << arr[i][j];
                else cout << answer[i][j];
            }
            cout << "\n";
        }
    }
    
    else
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cout << answer[i][j];
            }
            cout << "\n";
        }
    }
    
    return 0;
}
