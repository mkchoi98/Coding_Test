//
//  main.cpp
//  14467
//
//  Created by 최민경 on 2024/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    int arr[11];
    int answer = 0;
    
    for (int i=1;i<=10;i++) arr[i] = -1;
    
    for (int i=0;i<n;i++)
    {
        int a, b;
        
        cin >> a >> b;
        
        if (arr[a] == -1)
        {
            arr[a] = b;
        }
        
        else
        {
            if (arr[a] == b) continue;
            
            arr[a] = b;
            answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}
