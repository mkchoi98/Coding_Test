//
//  main.cpp
//  15961
//
//  Created by 최민경 on 2024/03/04.
//

#include <iostream>
#include <vector>

using namespace std;

static int N, d, k, c;
static vector<int> sushi;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> d >> k >> c;
    
    sushi.resize(N);
    
    for (int i=0;i<N;i++)
    {
        cin >> sushi[i];
    }
    
    vector<int> kind(3000001, 0);
    
    int cnt = 0;
    
    for (int i=0;i<k;i++)
    {
        kind[sushi[i]]++;
        
        if (kind[sushi[i]] == 1)
        {
            cnt++;
        }
    }
    
    int s = 0, e = k-1;
    int answer = 0;
    
    while (s < N)
    {
        kind[sushi[s%N]]--;
        if (kind[sushi[s%N]] == 0) cnt--;
        s++;
        
        e++;
        kind[sushi[e%N]]++;
        if (kind[sushi[e%N]] == 1) cnt++;
        
        if (kind[c] == 0) answer = max(answer, cnt+1);
        else answer = max(answer, cnt);
    }
    
    cout << answer;
    
    return 0;
}
