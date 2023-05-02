#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer;
    int len = 0;
    long long num = n;
    int i = 0;
    char str[10];
    
    // str = n + '0';
    
    while (1)
    {
        if (num == 0)
            break;
        
        len++;
        
        num /= 10;
    }
    
    answer = (int*)malloc(sizeof(int)*len);
    
    num = n;
    
    while (1)
    {
        if (num == 0)
            break;
        
        answer[i] = num % 10;
        
        num /= 10;
        
        i++;
    }
    
    return answer;
}
