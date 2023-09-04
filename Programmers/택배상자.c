#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// order_len은 배열 order의 길이입니다.
int solution(int order[], size_t order_len) {
    int answer = 0;
    int *stack = (int *)malloc(sizeof(int)*order_len);
    
    int top = -1;

    int i, j=0;
    
    for (i=1;i<=order_len;i++)
    {
        if (order[j] != i)
        {
            stack[++top] = i;
        }
        
        else if (order[j] == i)
        {
            answer++;
            j++;
        }
        
        while (1)
        {
            if (stack[top] == order[j])
            {
                top--;
                answer++;
                j++;
            }
            
            else break;
            
            if (j == order_len) break;
        }
    }
    
    return answer;
}
