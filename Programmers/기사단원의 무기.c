#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int number, int limit, int power) {
    int answer = 0;
    long long i, j;
    int cnt = 0;
    
    for (i=1;i<=number;i++)
    {
        cnt = 0;
        for (j=1;j<=sqrt(i);j++)
        {
            if (i % j == 0) 
            {
                cnt=cnt+2;
                
                if (j * j == i)
                    cnt--;
            }
        }
        
        if (cnt > limit) cnt = power;
        
        answer += cnt;
    }
    
    return answer;
}
