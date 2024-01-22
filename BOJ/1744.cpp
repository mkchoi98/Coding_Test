//
//  main.cpp
//  1744
//
//  Created by 최민경 on 2024/01/22.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    priority_queue<int> zero;
    priority_queue<int, vector<int>, greater<int>> negative;
    priority_queue<int> positive;
    
    int n;
    
    for (int i=0;i<N;i++)
    {
        cin >> n;
        
        if (n == 0)
        {
            zero.push(n);
        }
        
        else if (n < 0)
        {
            negative.push(n);
        }
        
        else
        {
            positive.push(n);
        }
    }
    
    int sum = 0;
    int n1, n2;
    
    while (positive.size() > 1)
    {
        n1 = positive.top();
        positive.pop();
        n2 = positive.top();
        positive.pop();
        
        if (n1 == 1 || n2 == 1)
        {
            sum += n1 + n2;
        }
        
        else sum += (n1 * n2);
    }
    
    if (positive.size() == 1)
    {
        sum += positive.top();
    }
    
    while (negative.size() > 1)
    {
        n1 = negative.top();
        negative.pop();
        n2 = negative.top();
        negative.pop();
        
        sum += (n1 * n2);
    }
    
    if (negative.size() == 1)
    {
       if (zero.size() == 0)
       {
           sum += negative.top();
       }
    }
    
    cout << sum;
    
    return 0;
}
