//
//  main.cpp
//  6603
//
//  Created by 최민경 on 2024/04/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> arr;
vector<bool> visited;
vector<int> answer;

void DFS(int start);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while (true)
    {
        cin >> k;
        
        if (k == 0) break;
        
        arr.resize(k);
        visited.resize(k, false);
        
        for (int i=0;i<k;i++)
        {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        DFS(0);
        
        cout << "\n";
    }
    
    return 0;
}

void DFS(int start)
{
    if (answer.size() == 6)
    {
        for (int i=0;i<6;i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        
        return ;
    }
    
    for (int i=start;i<k;i++)
    {
        //if (!visited[i])
        {
            answer.push_back(arr[i]);
            visited[i] = true;
            
            DFS(i+1);
            
            visited[i] = false;
            answer.pop_back();
        }
    }
}
