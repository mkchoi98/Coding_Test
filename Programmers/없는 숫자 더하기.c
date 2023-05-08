#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int index[9] = {0,};
    int i;
    
    for (i=0;i<numbers_len;i++)
    {
        index[numbers[i]]++;
    }
    
    for (i=0;i<9;i++)
    {
        if (index[i+1] == 0)
            answer += i+1;
    }
    
    return answer;
}
