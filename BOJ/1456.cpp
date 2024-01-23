//
//  main.cpp
//  1456
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
    
    long long A, B;
    
    cin >> A >> B;
    
    vector<long long> arr(10000000+1, 0);
    vector<long long> answer(10000000+1, 0);
    
    for (long long i=2;i<=10000000;i++)
    {
        arr[i] = i;
    }
    
    for (long long i=2;i<=sqrt(10000000);i++)
    {
        if (arr[i] == 0) continue;
        
        for (long long j=i+i;j<=10000000;j=j+i)
        {
            arr[j] = 0;
        }
    }
    
    int cnt=0;
    
    for (long long i=2;i<=10000000;i++)
    {
        if (arr[i] == 0) continue;
        
        long long temp = arr[i];
        
        while ((double)arr[i] <= (double)B/(double)temp)
        {
            if ((double)arr[i] >= (double)A/(double)temp)
            {
                cnt++;
            }
            
            temp *= arr[i];
        }
    }
    
    cout << cnt;
    
    return 0;
}
