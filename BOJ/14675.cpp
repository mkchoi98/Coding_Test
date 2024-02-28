//
//  main.cpp
//  14675
//
//  Created by 최민경 on 2024/02/28.
//

#include <iostream>
#include <vector>

using namespace std;

static int N;
static int q;
static vector<vector<int>> tree;
static vector<bool> visited;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    tree.resize(N+1);
    visited.resize(N+1, false);
    
    for (int i=0;i<N-1;i++)
    {
        int a, b;
        
        cin >> a >> b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    cin >> q;
    
    for (int i=0;i<q;i++)
    {
        int t, k;
        
        cin >> t >> k;
        
        if (t == 2)
        {
            cout << "yes\n";
            
            continue;
        }
        
        if (tree[k].size() >= 2) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}
