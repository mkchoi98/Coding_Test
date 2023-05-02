#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int i;
    int sum = 0;
    
    for (i=1;i<=n;i++)
    {
        if (n % i == 0)
            sum+=i;
    }
    
    answer = sum;
    
    return answer;
}
