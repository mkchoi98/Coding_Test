//
//  main.cpp
//  1976
//
//  Created by 최민경 on 2024/01/24.
//

#include <iostream>
#include <vector>

using namespace std;

static vector<int> parents;

void unionFunc(int a, int b);
int findFunc(int a);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    
    cin >> N;
    cin >> M;
    
    parents = vector<int>(N+1);
    
    for (int i=0;i<=N;i++)
    {
        parents[i] = i;
    }
    
    int n;
    
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=N;j++)
        {
            cin >> n;
            
            if (n == 0) continue;
            
            unionFunc(i, j);
        }
    }
    
    int travel;
    int p;
    bool check = true;
    
    for (int i=0;i<M;i++)
    {
        cin >> travel;
        
        if (i == 0)
        {
            p = findFunc(travel);
            
            continue;
        }
        
        if (p != findFunc(travel))
        {
            check = false;
            
            break;
        }
    }
    
    if (check) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}

void unionFunc(int a, int b)
{
    a = findFunc(a);
    b = findFunc(b);
    
    if (a != b)
    {
        parents[b] = a;
    }
}

int findFunc(int a)
{
    if (parents[a] == a)
    {
        return a;
    }
    
    else return parents[a] = findFunc(parents[a]);
}
