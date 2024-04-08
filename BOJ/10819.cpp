//
//  main.cpp
//  10819
//
//  Created by 최민경 on 2024/04/08.
//

#include <iostream>
#include <vector>

using namespace std;

static int n;
static int arr[8];
static vector<int> num;
static vector<bool> visited;
static int answer;

void DFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    visited.resize(n, false);
    
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    DFS();
    
    cout << answer;
    
    return 0;
}

void DFS()
{
    if (num.size() == n)
    {
        int sum = 0;
        
        for (int i=1;i<n;i++)
        {
            sum += abs(num[i-1] - num[i]);
        }
        
        answer = max(sum, answer);
        
        return;
    }
    
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            num.push_back(arr[i]);
            visited[i] = true;
            
            DFS();
            
            visited[i] = false;
            num.pop_back();
        }
    }
}
