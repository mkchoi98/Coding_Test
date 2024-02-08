#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, bool> pair_scoville;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<pair_scoville, vector<pair_scoville>, greater<pair_scoville>> pq;
    
    for (int i=0;i<scoville.size();i++)
    {
        if (scoville[i] >= K) pq.push({scoville[i], true});
        else pq.push({scoville[i], false});
    }
    
    int mix_scoville;
    
    while (pq.size() > 1)
    {
        if (pq.top().second == true) break;
        
        mix_scoville = pq.top().first;
        pq.pop();
        mix_scoville += pq.top().first*2;
        pq.pop();

        if (mix_scoville < K) pq.push({mix_scoville, false});
        else pq.push({mix_scoville, true});
        
        answer++;
    }
    
    if (pq.size() > 0 && pq.top().second == false) answer = -1;
   
    return answer;
}
