//
//  main.cpp
//  12891
//
//  Created by 최민경 on 2024/01/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int S, P;
    string dna;
    int arr[4], arr_cnt[4] = {0,}; // A, C, G, T
    
    cin >> S >> P;
    cin >> dna;
    
    for (int i=0;i<4;i++)
    {
        cin >> arr[i];
    }
    
    int i = 0, j = P-1;
    
    for (int s=i;s<=j;s++)
    {
        if (dna[s] == 'A') arr_cnt[0]++;
        else if (dna[s] == 'C') arr_cnt[1]++;
        else if (dna[s] == 'G') arr_cnt[2]++;
        else if (dna[s] == 'T') arr_cnt[3]++;
    }
    
    int answer = 0;
    bool flag = true;
    
    while (j < S)
    {
        int s;
        
        flag = true;
        
        for (s=0;s<4;s++)
        {
            if (arr[s] > arr_cnt[s])
            {
                flag = false;
            }
        }
        
        if (flag) answer++;
        
        if (dna[i] == 'A') arr_cnt[0]--;
        else if (dna[i] == 'C') arr_cnt[1]--;
        else if (dna[i] == 'G') arr_cnt[2]--;
        else if (dna[i] == 'T') arr_cnt[3]--;
        
        i++;
        j++;
        
        if (j == S) break;
        
        if (dna[j] == 'A') arr_cnt[0]++;
        else if (dna[j] == 'C') arr_cnt[1]++;
        else if (dna[j] == 'G') arr_cnt[2]++;
        else if (dna[j] == 'T') arr_cnt[3]++;
    }
    
    cout << answer;
    
    return 0;
}
