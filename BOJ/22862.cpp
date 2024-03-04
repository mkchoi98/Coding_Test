//
//  main.cpp
//  22862
//
//  Created by 최민경 on 2024/03/04.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int N, K;
static vector<int> S;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    S.resize(N);
    
    for (int i=0;i<N;i++)
    {
        cin >> S[i];
    }
    
    int L = 0, R = 0;
    int answer = 0;
    int del = 0;
    
    while (R < N)
    {
        if (del <= K)
        {
            if (S[R] % 2 == 1)
            {
                del++;
            }
            
            R += 1;
        }
        
        else if (del > K)
        {
            if (S[L] % 2 == 1)
            {
                del--;
            }
            
            L += 1;
        }
        
        if (del <= K)
        {
            answer = max(answer, R-L-del);
        }
    }
    
    cout << answer;
    
    return 0;
}
