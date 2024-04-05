//
//  main.cpp
//  6550
//
//  Created by 최민경 on 2024/04/05.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string str1, str2;
    
    while (cin >> str1 >> str2)
    {
        int i = 0, j = 0;
        bool flag;
        
        while (true)
        {
            if (str1[i] == str2[j])
            {
                i++;
                j++;
            }
            
            else
            {
                j++;
            }
            
            if (i == str1.length())
            {
                flag = true;
                break;
            }
            
            if (j == str2.length())
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            cout << "Yes\n";
        }
        
        else
        {
            cout << "No\n";
        }
    }
    
    return 0;
}
