//
//  main.cpp
//  15651
//
//  Created by 최민경 on 2024/02/15.
//

#include <iostream>
#include <vector>

using namespace std;

static int n, m;
static vector<int> answer;

void DFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
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
        
        return;
    }
    
    for (int i=1;i<=n;i++)
    {
        answer.push_back(i);
        DFS();
        answer.pop_back();
    }
}
