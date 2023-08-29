#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// want_len은 배열 want의 길이입니다.
// number_len은 배열 number의 길이입니다.
// discount_len은 배열 discount의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    int answer = 0;
    int i, j, k;
    int *number_copy = (int *)malloc(sizeof(int)*number_len);
    
    for (i=0;i<=discount_len-10;i++)
    {
        for (k=0;k<number_len;k++)
        {
            number_copy[k] = number[k];
        }
        
        for (k=0;k<want_len;k++)
        {
            for (j=0;j<10;j++)
            {
                if (strcmp(discount[i+j], want[k]) == 0)
                {
                    number_copy[k]--;
                }
            }
        }
        
        for (k=0;k<number_len;k++)
        {
            if (number_copy[k] != 0)
                break;
        }
        
        if (k == number_len) answer++;
    }
    
    return answer;
}
