//
//  main.cpp
//  15654
//
//  Created by 최민경 on 2024/02/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int n, m;
static vector<int> num;
static vector<int> answer;
static vector<bool> visited;

void DFS(int index);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    num.resize(n);
    visited.resize(n, false);
    
    for (int i=0;i<n;i++)
    {
        cin >> num[i];
    }
    
    sort(num.begin(), num.end());
    
    DFS(0);
    
    return 0;
}

void DFS(int index)
{
    if (answer.size() == m)
    {
        for (int i=0;i<m;i++)
        {
            cout << answer[i] << " ";
        }
        
        cout << "\n";
        
        return ;
    }
    
    for (int i=index;i<n;i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            answer.push_back(num[i]);
            DFS(index);
            answer.pop_back();
            visited[i] = false;
        }
    }
}
