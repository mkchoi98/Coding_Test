//
//  main.cpp
//  1935
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
    
    vector<pair<int, int>>time(N);
    
    for (int i=0;i<N;i++)
    {
        cin >> time[i].second; // 종료시간
        cin >> time[i].first;  // 시작시간
    }
    
    sort(time.begin(), time.end());
    
    int start, end;
    int cnt = 1;
    
    end = time[0].first;
    
    for (int i=1;i<N;i++)
    {
        start = time[i].second;
        
        if (start >= end)
        {
            cnt++;
            
            end = time[i].first;
        }
    }
    
    cout << cnt;
    
    return 0;
}
