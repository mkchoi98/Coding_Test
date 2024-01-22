//
//  main.cpp
//  2343
//
//  Created by 최민경 on 2024/01/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<int> A(N, 0);
    
    int start = 0, end = 0;
    
    for (int i=0;i<N;i++)
    {
        cin >> A[i];
        
        if (A[i] > start)
        {
            start = A[i];
        }
        
        end += A[i];
    }
    
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int sum = 0;
        int cnt = 0;
        
        for (int i=0;i<N;i++)
        {
            if (sum + A[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            
            sum += A[i];
        }
        
        if (sum != 0)
        {
            cnt++;
        }
        
        if (cnt > M)
        {
            start = mid + 1;
        }
        
        else
        {
            end = mid - 1;
        }
    }
    
    cout << start;
    
    return 0;
}
