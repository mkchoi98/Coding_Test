#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
 
    int row = left/n+1;
    
    for (long long i=left+1;i<=right+1;i++)
    {
        if (i % n == 0)
        {
            answer.push_back(n);
            row++;
        }
        
        else
        {
            if (i%n > row)
            {
                answer.push_back(i%n);
            }
            
            else
            {
                answer.push_back(row);
            }
        }
    }
    
    return answer;
}
