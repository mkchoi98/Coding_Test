//
//  main.cpp
//  2164
//
//  Created by 최민경 on 2024/01/16.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    queue<int> myQueue;
    
    for (int i=1;i<=N;i++)
    {
        myQueue.push(i);
    }
    
    while (myQueue.size() != 1)
    {
        myQueue.pop();
        
        int num = myQueue.front();
        
        myQueue.pop();
        
        myQueue.push(num);
    }
    
    cout << myQueue.front();
    
    return 0;
}
