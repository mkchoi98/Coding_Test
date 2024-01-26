#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    long sum = 0;
    int i = 0;
    
    while (sum < budget)
    {
        sum += d[i++];
        
        if (i == d.size()) break;
    }
    
    if (i == d.size())
    {
        if (sum <= budget) answer = i;
        else answer = i-1;
    }
    
    else
    {
        if (sum == budget) answer = i;
        else answer = i-1;
    }
    
    return answer;
}
