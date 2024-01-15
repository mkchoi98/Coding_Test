//
//  main.cpp
//  2470
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
    
    vector<int> arr(N, 0);
    
    for (int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int i = 0, j = N-1;
    int min_i = 0, min_j = N-1;
    int min_sum, sum;
    
    sum = arr[i]+arr[j];
  
    min_sum = abs(sum);
    
    while (i < j)
    {
        if (abs(sum) < min_sum)
        {
            min_i = i;
            min_j = j;
            min_sum = abs(sum);
        }
        
        if (sum == 0)
        {
            cout << arr[i] << ' ' << arr[j];
            
            return 0;
        }
        
        else if (sum > 0)
        {
            sum -= arr[j];
            j--;
            
            if (i == j) break;
            
            sum += arr[j];
        }
        
        else if (sum < 0)
        {
            sum -= arr[i];
            i++;
            
            if (i == j) break;
            
            sum += arr[i];
        }
    }
  
    cout << arr[min_i] << ' ' << arr[min_j];
    
    return 0;
}
