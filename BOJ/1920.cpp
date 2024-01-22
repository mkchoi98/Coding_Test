//
//  main.cpp
//  1920
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
    
    int N;
    
    cin >> N;
    
    vector<int> A(N);
    
    for (int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int M;
    
    cin >> M;
    
    int num;
    
    for (int i=0;i<M;i++)
    {
        cin >> num;
        
        int start = 0;
        int end = N-1;
        
        bool find = false;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            
            if (num < A[mid])
            {
                end = mid-1;
            }
            
            else if (num > A[mid])
            {
                start = mid+1;
            }
            
            else
            {
                find = true;
                break;
            }
        }
        
        if (find)
        {
            cout << 1 << "\n";
        }
        
        else
        {
            cout << 0 << "\n";
        }
    }
    
    
    return 0;
}
