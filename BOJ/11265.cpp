//
//  main.cpp
//  11265
//
//  Created by 최민경 on 2024/02/01.
//

#include <iostream>
#include <vector>

using namespace std;

static int N, M;
static vector<vector<int>> adj_arr;


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    adj_arr = vector<vector<int>> (N+1, vector<int>(N+1));
    
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=N;j++)
        {
            cin >> adj_arr[i][j];
        }
    }
    
    for (int k=1;k<=N;k++)
    {
        for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=N;j++)
            {
                if (adj_arr[i][j] > adj_arr[i][k] + adj_arr[k][j])
                {
                    adj_arr[i][j] = adj_arr[i][k] + adj_arr[k][j];
                }
            }
        }
    }
    
    for (int i=0;i<M;i++)
    {
        int A, B, C; // 손님이 있는 파티장 번호, 파티가 열리는 파티장 번호, 파티가 열리는데 걸리는 시간
        
        cin >> A >> B >> C;
        
        if (adj_arr[A][B] <= C)
        {
            cout << "Enjoy other party\n";
        }
        
        else
        {
            cout << "Stay here\n";
        }
    }
    
    return 0;
}
