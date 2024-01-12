//
//  main.cpp
//  1940
//
//  Created by 최민경 on 2024/01/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<int> num(N, 0);
    
    for (int i=0;i<N;i++)
    {
        cin >> num[i];
    }
    
    sort(num.begin(), num.end(), compare);
    
    int i = 0, j = N-1;
    int cnt = 0;
    
    while (i < j)
    {
        if (num[i] + num[j] == M)
        {
            cnt++;
            i++;
            j--;
        }
        
        else if (num[i] + num[j] > M)
        {
            j--;
        }
        
        else if (num[i] + num[j] < M)
        {
            i++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
