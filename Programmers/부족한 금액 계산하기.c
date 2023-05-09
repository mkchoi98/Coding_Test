#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    int i;
    long long sum = 0;
    
    for (i=1;i<=count;i++)
    {
        sum += price * i;
    }
    
    answer = sum - money;
    
    if (answer <= 0)
        return 0;
    
    return answer;
}
