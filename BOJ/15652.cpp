//
//  main.cpp
//  15652
//
//  Created by 최민경 on 2024/02/15.
//

#include <iostream>
#include <vector>

using namespace std;

static int n, m;
static vector<int> answer;
static vector<bool> visited;

void DFS(int index);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    visited.resize(n+1, false);
    
    DFS(1);
    
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
        
        return;
    }
    
    for (int i=index;i<=n;i++)
    {
        answer.push_back(i);
        DFS(i);
        answer.pop_back();
    }
}
