//
//  main.cpp
//  2578
//
//  Created by 최민경 on 2024/03/06.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<vector<int>> bingo(5, vector<int>(5));
    
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            cin >> bingo[i][j];
        }
    }
    
    for (int k=0;k<25;k++)
    {
        int num;
        
        cin >> num;
        
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++)
            {
                if (num == bingo[i][j])
                {
                    bingo[i][j] = 0;
                    
                    break;
                }
            }
        }
        
        int cnt = 0;
        
        if (k >= 4)
        {
            bool flag = true;
            
            // 가로 확인
            for (int i=0;i<5;i++)
            {
                flag = true;
                for (int j=0;j<5;j++)
                {
                    if (bingo[i][j] != 0)
                    {
                        flag = false;
                        
                        break;
                    }
                }
                if (flag)
                {
                    cnt++;
                }
            }
            
            // 세로 확인
            for (int i=0;i<5;i++)
            {
                flag = true;
                for (int j=0;j<5;j++)
                {
                    if (bingo[j][i] != 0)
                    {
                        flag = false;
                        
                        break;
                    }
                }
                if (flag)
                {
                    cnt++;
                }
            }
            
            // 대각선 확인
            flag = true;
            for (int i=0;i<5;i++)
            {
                if (bingo[i][i] != 0)
                {
                    flag = false;
                    
                    break;
                }
            }
            
            if (flag)
            {
                cnt++;
            }
            
            flag = true;
            for (int i=4,j=0;i>=0,j<5;i--,j++)
            {
                if (bingo[j][i] != 0)
                {
                    flag = false;
                    
                    break;
                }
            }
            
            if (flag)
            {
                cnt++;
            }
        }
        
        if (cnt >= 3)
        {
            cout << k+1;
            
            break;
        }
    }
    
    return 0;
}
