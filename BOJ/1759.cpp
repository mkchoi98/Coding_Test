//
//  main.cpp
//  1759
//
//  Created by 최민경 on 2024/04/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int L, C;
static vector<char> arr;
static vector<char> password;

void DFS(int start);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> L >> C;
    
    arr.resize(C);
    
    for (int i=0;i<C;i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    DFS(0);
    
    return 0;
}

void DFS(int start)
{
    if (password.size() == L)
    {
        bool flag = false;
        
        for (int i=0;i<L;i++)
        {
            if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
            {
                flag = true;
                
                break;
            }
        }
        
        int cnt = 0;
        
        if (flag)
        {
            for (int i=0;i<L;i++)
            {
                if (password[i] != 'a' && password[i] != 'e' && password[i] != 'i' && password[i] != 'o' && password[i] != 'u')
                {
                    cnt++;
                }
            }
        }
        
        if (cnt >= 2)
        {
            for (int i=0;i<L;i++)
            {
                cout << password[i];
            }
            cout << "\n";
        }
        
        return ;
    }
    
    for (int i=start;i<C;i++)
    {
        password.push_back(arr[i]);
        DFS(i+1);
        password.pop_back();
    }
}
