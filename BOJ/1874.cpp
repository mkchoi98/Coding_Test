//
//  main.cpp
//  1874
//
//  Created by 최민경 on 2024/01/16.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n, 0);
    vector<char> result;
    
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    stack<int> numStack;
    int num = 1;
    int curN;
    
    for (int i=0;i<n;i++)
    {
        curN = arr[i];
        
        if (curN >= num)
        {
            while (curN >= num)
            {
                numStack.push(num++);
                result.push_back('+');
            }
            
            numStack.pop();
            result.push_back('-');
        }
        
        else
        {
            int top = numStack.top();
            
            if (top > curN)
            {
                cout << "NO";
                
                return 0;
            }
            
            numStack.pop();
            result.push_back('-');
        }
    }
    
    for (int i=0;i<result.size();i++)
    {
        cout << result[i] << '\n';
    }
    
    return 0;
}
