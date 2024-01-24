//
//  main.cpp
//  1717
//
//  Created by 최민경 on 2024/01/24.
//

#include <iostream>
#include <vector>

using namespace std;


static vector<int>arr;

void unionFunc(int a, int b);
int find(int a);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    
    cin >> n >> m;
    
    arr.resize(n+1);
    
    for (int i=0;i<=n;i++)
    {
        arr[i] = i;
    }
    
    for (int i=0;i<m;i++)
    {
        int question, a, b;
        
        cin >> question >> a >> b;
        
        if (question == 0)
        {
            unionFunc(a, b);
        }
        
        else
        {
            if (find(a) == find(b))
            {
                cout << "YES\n";
            }
            
            else
            {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}

int find(int a)
{
    if (a != arr[a])
    {
        return arr[a] = find(arr[a]);
    }
    
    else return a;
}

void unionFunc(int a, int b)
{
    int a_parents = find(a);
    int b_parents = find(b);
    
    if (a_parents != b_parents)
    {
        arr[b_parents] = a_parents;
    }
}
