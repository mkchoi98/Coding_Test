//
//  main.cpp
//  16918
//
//  Created by 최민경 on 2024/03/06.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int R, C, N;
static vector<vector<pair<char, int>>> arr;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    
    cin >> R >> C >> N;
    
    arr = vector<vector<pair<char, int>>>(R, vector<pair<char, int>>(C));
    
    for (int i=0;i<R;i++)
    {
        string row;
        
        cin >> row;
        
        for (int j=0;j<C;j++)
        {
            arr[i][j].first = row[j];
            arr[i][j].second = 2;
        }
    }
    
    int sec = 2;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while (sec <= N)
    {
        // 빈 곳에 폭탄 설치
        if (sec % 2 == 0)
        {
            for (int i=0;i<R;i++)
            {
                for (int j=0;j<C;j++)
                {
                    if (arr[i][j].first == '.')
                    {
                        arr[i][j].first = 'O';
                        arr[i][j].second = 0;
                    }
                }
            }
        }
        
        // 폭탄 폭발
        else
        {
            for (int i=0;i<R;i++)
            {
                for (int j=0;j<C;j++)
                {
                    if (arr[i][j].second == 3 && arr[i][j].first == 'O')
                    {
                        for (int d=0;d<4;d++)
                        {
                            int adj_x = i+dx[d];
                            int adj_y = j+dy[d];
                            
                            if (adj_x >= 0 && adj_x < R && adj_y >= 0 && adj_y < C && (arr[adj_x][adj_y].second != 3 && arr[adj_x][adj_y].first == 'O'))
                            {
                                arr[adj_x][adj_y].first = '.';
                                arr[adj_x][adj_y].second = 0;
                            }
                        }
                        
                        arr[i][j].first = '.';
                    }
                }
            }
        }

        sec++;
        
        for (int i=0;i<R;i++)
        {
            for (int j=0;j<C;j++)
            {
                if (arr[i][j].first == 'O')
                {
                    arr[i][j].second++;
                }
            }
        }
    }
    
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            cout << arr[i][j].first;
        }
        cout << "\n";
    }
    
    return 0;
}
