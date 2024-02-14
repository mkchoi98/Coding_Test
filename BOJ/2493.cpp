//
//  main.cpp
//  2493
//
//  Created by 최민경 on 2024/02/14.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static vector<long> castle;
static vector<int> answer;
static int n;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    stack<int> myStack;
    
    cin >> n;
    
    castle.resize(n);
    answer.resize(n, 0);
    
    for (int i=0;i<n;i++)
    {
        cin >> castle[i];
    }
    
    for (int i=n-1;i>=0;i--)
    {
        while (!myStack.empty() && castle[myStack.top()] <= castle[i])
        {
            answer[myStack.top()] = i+1;
            myStack.pop();
        }
        
        myStack.push(i);
    }
    
    for (int i=0;i<n;i++)
    {
        cout << answer[i] << " ";
    }
    
    return 0;
}
