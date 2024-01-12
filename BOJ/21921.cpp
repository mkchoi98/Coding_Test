//
//  main.cpp
//  21921
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
    
    int N, X;
    
    cin >> N >> X;
    
    vector<int> arr(N, 0);
    
    for (int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    
    int i = 0;
    int j = i+1;
    int sum = 0, max = 0, cnt = 0;
    
    sum = arr[i] + arr[j];
    
    while (j < N)
    {
        if (j-i == X-1)
        {
            if (max < sum)
            {
                max = sum;
                cnt = 1;
            }
            
            else if (max == sum)
            {
                cnt++;
            }
            
            j++;
            sum += arr[j];
        }
        
        else if (j-i > X-1)
        {
            sum -= arr[i];
            i++;
        }
        
        else if (j-i < X-1)
        {
            j++;
            sum += arr[j];
        }
    }
    
    if (max == 0)
    {
        cout << "SAD";
    }
    
    else
    {
        cout << max << "\n" << cnt;
    }
    
    return 0;
}
