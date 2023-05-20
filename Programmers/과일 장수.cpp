#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    long long min = 1000000;
    
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    
    for (int i=0;i<score.size()-(score.size()%m);i=i+m)
    {
        for (int j=i;j<i+m;j++)
        {
            if (min > score[j])
                min = score[j];
        }
        answer += min*m;
    }
    
    return answer;
}
