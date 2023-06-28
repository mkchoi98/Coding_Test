#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    char *num;
    long zero_cnt = 0, len = 0, cnt = 1;
    long i, j;
    
    if (strlen(s) == 1)
    {
        answer[0] = 0;
        answer[1] = 1;
        
        return answer;
    }
    
    for (i=0;i<strlen(s);i++)
    {
        if (s[i] == '1')
        {
            len++;
        }
        
        else zero_cnt++;
    }
    
    while (len > 1)
    {
        i = 0;
        num = (char *)malloc(sizeof(char)*((int)(len/2+1)));
        
        while (len > 0)
        {
            num[i++] = (len % 2) + '0';
 
            len /= 2;
        }
        
        len = 0;
        
        for (j=0;j<i;j++)
        {
            if (num[j] == '1') len++;

            else zero_cnt++;
        }
        
        free(num);
        
        cnt++;
    }
    
    answer[0] = cnt;
    answer[1] = zero_cnt;
    
    return answer;
}
