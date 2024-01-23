//
//  main.cpp
//  1929
//
//  Created by 최민경 on 2024/01/23.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, N;
    
    cin >> M >> N;
    
    vector<int> A(N+1, 0);
    
    for (int i=2;i<=N;i++)
    {
        A[i] = i;
    }
    
    for (int i=2;i<=sqrt(N);i++)
    {
        if (A[i] == 0) continue;
        
        for (int j=i+i;j<=N;j=j+i)
        {
            A[j] = 0;
        }
    }
    
    for (int i=M;i<=N;i++)
    {
        if (A[i] != 0) cout << A[i] << "\n";
    }
    
    return 0;
}
