//
//  main.cpp
//  2018
//
//  Created by 최민경 on 2024/01/12.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    // vector<int> arr(n+1, 0);
    
    cin >> n;
    
    int start_index = 1, end_index = 1;
    int sum = 1, cnt = 1;
    
    while (end_index != n)
    {
        if (sum == n)
        {
            cnt++;
            end_index++;
            sum += end_index;
        }
        
        else if (sum > n)
        {
            sum -= start_index;
            start_index++;
        }
        
        else if (sum < n)
        {
            end_index++;
            sum += end_index;
        }
    }
    
    cout << cnt;
    
    return 0;
}
