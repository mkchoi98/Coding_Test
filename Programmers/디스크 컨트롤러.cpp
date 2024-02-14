#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    
    sort(jobs.begin(), jobs.end(), compare);
    
    int time = 0;
    int i;
    bool flag = false;
    
    while (!jobs.empty())
    {
        for (i=0;i<jobs.size();i++)
        {
            flag = false;
            if (jobs[i][0] <= time)
            {
                time += jobs[i][1];
                answer += time - jobs[i][0];
                jobs.erase(jobs.begin()+i);
                
                flag = true;
                
                break;
            }
        }
        
        if (!flag)
        {
            time++;
        }
    }
    
    return answer/size;
}
