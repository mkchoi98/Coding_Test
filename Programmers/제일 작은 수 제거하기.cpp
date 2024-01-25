#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    if (arr.size() == 1)
    {
        vector<int> answer(1, -1);
        
        return answer;
    }
    
    vector<int> answer(arr.size()-1, 0);
    
    int min = 987654321;
    int min_index;
    
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index= i;
        }
    }
    
    int i = 0, j = 0;
    
    while (i < arr.size())
    {
        if (i == min_index)
        {
            i++;
            continue;
        }
        
        answer[j] = arr[i];
    
        i++;
        j++;
    }
    
    return answer;
}
