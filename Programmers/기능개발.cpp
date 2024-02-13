#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    vector<int> arr(progresses.size());
    int index = 0;
    
    while (index < size)
    {
        for (int i=index;i<size;i++)
        {
            progresses[i] += speeds[i];
        }
        
        int cnt = 0;
        while (progresses[index] >= 100)
        {
            cnt++;
            index++;
            
            if (index == size) break;
        }
        
        if (cnt != 0)
        {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}
