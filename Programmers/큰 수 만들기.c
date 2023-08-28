#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(number);
    char* answer = (char*)malloc(sizeof(char)*(len-k+1));
    
    int i, j;
    
    int max = 0;
    int max_index = 0;
    int index = 0;
    
    for (i=0;i<len-k;i++)
    {
        max = 0;
        max_index = index;
        for (j=index;j<=k+i;j++)
        {
            if (max < number[j]- '0')
            {
                max = number[j] - '0';
                max_index = j;
            }
        }
        
        answer[i] = max +'0';
        index = max_index+1;
    }
    
    answer[i] = '\0';
    
    return answer;
}
