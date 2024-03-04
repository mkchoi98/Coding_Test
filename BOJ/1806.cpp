//
//  main.cpp
//  1806
//
//  Created by 최민경 on 2024/03/04.
//

#include <iostream>
#include <vector>

using namespace std;

static int N, S;
static vector<int> num;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> S;
    
    num.resize(N);
    
    for (int i=0;i<N;i++)
    {
        cin >> num[i];
    }
    
    int s = 0, e = 0;
    int sum = 0;
    int answer = 987654321;
    
    sum = num[s];
    
    while (s <= e)
    {
        if (sum >= S)
        {
            answer = min(e-s+1, answer);
        }
        
        if (sum < S)
        {
            e++;
            sum += num[e];
        }
        
        else
        {
            sum -= num[s];
            s++;
        }
        
        if (e == N) break;
    }
    
    if (answer == 987654321) answer = 0;
    
    cout << answer;
    
    return 0;
}
