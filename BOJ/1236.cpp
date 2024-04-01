//
//  main.cpp
//  1236
//
//  Created by 최민경 on 2024/04/01.
//

#include <iostream>
#include <vector>

#define MAX_N 51
#define MAX_M 51

using namespace std;

static int N, M;
static char arr[MAX_N][MAX_M];
static int answer;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    vector<bool> row(N, false);
    vector<bool> col(M, false);
    
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0;i<N;i++)
    {
        bool flag = false;
        for (int j=0;j<M;j++)
        {
            if (arr[i][j] == 'X')
            {
                flag = true;
            }
        }
        
        if (!flag)
        {
            row[i] = false;
        }
        
        else
        {
            row[i] = true;
        }
    }
    
    for (int i=0;i<M;i++)
    {
        bool flag = false;
        for (int j=0;j<N;j++)
        {
            if (arr[j][i] == 'X')
            {
                flag = true;
            }
        }
        
        if (!flag)
        {
            col[i] = false;
        }
        
        else
        {
            col[i] = true;
        }
    }
    
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            if (!row[i] && !col[j])
            {
                answer++;
                arr[i][j] = 'X';
                
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    
    for (int i=0;i<M;i++)
    {
        if (!col[i])
        {
            answer++;
        }
    }
    
    for (int i=0;i<N;i++)
    {
        if (!row[i]) answer++;
    }
    
    cout << answer;
    
    return 0;
}
