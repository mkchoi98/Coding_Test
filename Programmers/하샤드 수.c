#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int num = x;
    
    while (1)
    {
        if (num == 0)
            break;
        
        sum += num % 10;
        
        num /= 10;
    }
    
    answer = x % sum == 0 ? true : false;
    
    return answer;
}
