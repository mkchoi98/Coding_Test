#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    int temp;
    if (a > b)
    {
        temp = a;
        
        a = b;
        b = temp;
    }
    
    int m = abs(a-b);
    
    if (b % 2 == 1)
    {
        m = 2;
    }
    
    while (m != 1)
    {
        if (a % 2 == 0)
        {
            a /= 2;
        }
        
        else
        {
            a = (a+1)/2;
        }
        
        if (b % 2 == 0)
        {
            b /= 2;
        }
        
        else
        {
            b = (b+1)/2;
        }
        
        if (b % 2 == 1)
        {
            answer++;
            continue;
        }
        
        answer++;
        m = abs(a-b);
    }

    return answer;
}
