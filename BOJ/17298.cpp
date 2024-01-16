//
//  main.cpp
//  17298
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
    
    int N;
    
    cin >> N;
    
    vector<int> arr(N, 0);
    vector<int> result(N, -1);
    
    for (int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    
    stack<int> myStack;
    
    for (int i=0;i<N;i++)
    {
        while(!myStack.empty() && arr[myStack.top()] < arr[i])
        {
            int top = myStack.top();
            
            result[top] = arr[i];
            
            myStack.pop();
        }
        
        myStack.push(i);
    }
    
    for (int i=0;i<N;i++)
    {
        cout << result[i] << ' ';
    }
    
    return 0;
}
