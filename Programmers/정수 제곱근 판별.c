#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = 0;
    double root_n = sqrt(n);
    
    if (fmod(root_n, 1) == 0)
        answer = (root_n+1) * (root_n+1);
    else
        answer = -1;
    
    return answer;
}
