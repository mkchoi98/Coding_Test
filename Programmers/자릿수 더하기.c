#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int num = n;
    
    while (1)
    {
        if (num == 0)
            break;
        sum += num%10;
        num /= 10;
    }
    
    answer = sum;
    
    return answer;
}
