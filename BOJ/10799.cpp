//
//  main.cpp
//  10799
//
//  Created by 최민경 on 2024/03/10.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    
    cin >> str;
    
    stack<char> myStack;
    int answer = 0;
    
    myStack.push(str[0]);
    
    for (int i=1;i<str.size();i++)
    {
        if (str[i] == '(')
        {
            myStack.push(str[i]);
        }
        
        else
        {
            myStack.pop();
            
            if (str[i-1] == '(') answer += myStack.size();
            
            else answer += 1;
        }
    }
    
    cout << answer;
    
    return 0;
}
