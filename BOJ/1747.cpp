//
//  main.cpp
//  1747
//
//  Created by 최민경 on 2024/01/23.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool isPallindrome(int num)
{
    string str = to_string(num);
    int s = 0, e = str.size()-1;
   
    while (s < e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        
        s++;
        e--;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    vector<int> A(10000001, 0);
    
    for (int i=2;i<=10000000;i++)
    {
        A[i] = i;
    }
    
    for (int i=2;i<=sqrt(10000000);i++)
    {
        if (A[i] == 0) continue;
        
        for (int j=i+i;j<=10000000;j=j+i)
        {
            A[j] = 0;
        }
    }
    
    for (int i=N;i<=10000000;i++)
    {
        if (A[i] == 0) continue;
        
        if (isPallindrome(A[i]))
        {
            cout << A[i];
            
            break;
        }
    }
    
    return 0;
}
