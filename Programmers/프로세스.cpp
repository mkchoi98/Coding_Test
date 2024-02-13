#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i=0;i<priorities.size();i++)
    {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    // sort(priorities.begin(), priorities.end(), greater<int>());
    
    while (true)
    {
        if (pq.top() == q.front().second)
        {
            if (q.front().first == location)
            {
                break;
            }
            
            else
            {
                answer++;
                pq.pop();
                q.pop();
            }
        }
        
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}
