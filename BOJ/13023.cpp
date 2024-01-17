//
//  main.cpp
//  13023
//
//  Created by 최민경 on 2024/01/17.
//

#include <iostream>
#include <vector>

#define MAX_SIZE 2000

using namespace std;

static bool answer = false;
static int N;
static int M;
static vector<vector<int>> adj_arr;
static vector<bool> visited(MAX_SIZE, false);

void DFS(int num, int depth)
{
    if (depth == 5)
    {
        answer = true;
        
        return ;
    }
    
    visited[num] = true;
    
    for (int i:adj_arr[num])
    {
        if (!visited[i])
        {
            depth++;
            
            DFS(i, depth);
            
            depth--;
        }
    }
    
    visited[num] = false;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    adj_arr.resize(N);
    
    int a, b;
    
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        
        adj_arr[a].push_back(b);
        adj_arr[b].push_back(a);
    }
    
    for (int i=0;i<N;i++)
    {
        DFS(i, 1);
        
        if (answer)
        {
            break;
        }
    }
    
    if (answer) cout << 1;
    
    else cout << 0;
    
    return 0;
}
