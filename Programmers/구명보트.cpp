#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int limit_copy = limit;
    
    sort(people.begin(), people.end());
    
    int i=0, j=people.size()-1;
    int sum = people[i]+people[j];
    
    while (i < j)
    {
        if (sum <= limit)
        {
            answer++;
            
            i++;
            j--;
            
            sum = people[j]+people[i];
        }
        
        else if (sum > limit)
        {
            answer++;
            
            sum -= people[j];
            j--;
            sum += people[j];
        }
        
    }
    
    if (i == j)
        answer++;
    
    return answer;
}
