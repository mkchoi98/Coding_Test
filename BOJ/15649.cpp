//
//  main.cpp
//  15649
//
//  Created by 최민경 on 2024/02/15.
//

#include <iostream>
#include <vector>

using namespace std;

static int n, m;
static vector<int> number;
static vector<int> answer;
static vector<bool> visited;

void DFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    visited.resize(n+1, false);
    number.resize(n+1);
    // answer.resize(m);
    
    for (int i=1;i<=n;i++)
    {
        number[i] = i;
    }
    
    DFS();
    
    return 0;
}

void DFS()
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
    
    for (int i=1;i<=n;i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            answer.push_back(i);
            
            DFS();
            
            answer.pop_back();
            visited[i] = false;
        }
    }
}
