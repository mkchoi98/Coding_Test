#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int min = 0;
    int i = 0;
    
    for (i=2;i<=n;i++)
    {
        if ((n-1) % i == 0)
        {
            answer = i;
            
            break;
        }
    }
    
    return answer;
}
