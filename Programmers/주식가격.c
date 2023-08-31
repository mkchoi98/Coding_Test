#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*prices_len);
    int i;
    
    int *stack = (int *)malloc(sizeof(int)*prices_len);
    int *stack_index = (int *)malloc(sizeof(int)*prices_len);
    int top = -1;
    
    stack[++top] = prices[0];
    stack_index[top] = 0;
    
    for (i=1;i<prices_len;i++)
    {
        while (stack[top] > prices[i])
        {
            answer[stack_index[top]] = i - stack_index[top];
            
            top--;
        }
        
        {
            stack[++top] = prices[i];
            stack_index[top] = i;
        }
    }
    
    while (top > -1)
    {
        answer[stack_index[top]] = prices_len - stack_index[top] -1;
        
        top--;
    }
    
    free(stack);
    
    return answer;
}
