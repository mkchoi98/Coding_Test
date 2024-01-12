//
//  main.cpp
//  20922
//
//  Created by 최민경 on 2024/01/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    
    cin >> N >> K;
    
    if (N == 1)
    {
        cout << 1;
        
        return 0;
    }
    
    vector<int>A (N, 0);
    
    for (int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    
    vector<int> cnt(100001, 0);
    
    int i = 0, j = 1;
    int length, max_length = 0;
    
    cnt[A[i]]++;
    cnt[A[j]]++;
    
    length = 2;
    
    while (j < N)
    {
        if (cnt[A[j]] == K+1)
        {
            if (max_length < length-1)
            {
                max_length = length-1;
            }
            
            cnt[A[i]]--;
            length--;
            
            i++;
        }
        
        else
        {
            j++;
            
            if (j == N) break;
            
            cnt[A[j]]++;
            length++;
        }
    }
    
    if (max_length < length)
    {
        max_length = length;
    }
    
    cout << max_length;
    
    return 0;
}
