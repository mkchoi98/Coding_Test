//
//  main.cpp
//  2346
//
//  Created by 최민경 on 2024/01/16.
//

#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    vector<int> arr;
    
    int x;
    
    for (int i=0;i<N;i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    
    deque<int> myQueue;
    
    for (int i=1;i<=N;i++)
    {
        myQueue.push_back(i);
    }
    
    while (!myQueue.empty())
    {
        int index = myQueue.front()-1;
        
        cout << myQueue.front() << ' ';
        
        myQueue.pop_front();
        
        int n = 0;
        
        if (arr[index] > 0)
        {
            while (n < arr[index]-1)
            {
                myQueue.push_back(myQueue.front());
                myQueue.pop_front();
                
                n++;
            }
        }
        
        else
        {
            while (n > arr[index])
            {
                myQueue.push_front(myQueue.back());
                myQueue.pop_back();
                
                n--;
            }
        }
    }
    
    return 0;
}
