#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len);
    
    int *stack = (int *)malloc(sizeof(int)*numbers_len);
    int *index = (int *)malloc(sizeof(int)*numbers_len);
    
    int top = -1;
    
    int i = 0, j;
    
    for (i=0;i<numbers_len;i++)
    {
        answer[i] = -1;
    }
    
    for (i=0;i<numbers_len-1;i++)
    {
        stack[++top] = numbers[i];
        index[top] = i;
        
        
        while (numbers[i+1] > stack[top] && top != -1)
        {
            answer[index[top]] = numbers[i+1];
            
            top--;
        }
    }
    
    return answer;
}
