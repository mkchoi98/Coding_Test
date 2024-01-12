//
//  main.cpp
//  1253
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
    
    int N;
    
    cin >> N;
    
    vector<int> A(N, 0);
    
    for (int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int M;
    int sum, cnt = 0;
    
    for (int i=0;i<N;i++)
    {
        M = A[i];
        
        int cur_index = i;
        int start_index = 0, end_index = N-1;
        
        sum = 0;
        
        while (start_index < end_index)
        {
            if (start_index == cur_index)
            {
                start_index++;
                continue;
            }
            
            if (end_index == cur_index)
            {
                end_index--;
                continue;
            }
            
            sum = A[start_index] + A[end_index];
            
            if (sum == M)
            {
                cnt++;
                break;
            }
            
            else if (sum < M)
            {
                start_index++;
            }
            
            else if (sum > M)
            {
                end_index--;
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}
