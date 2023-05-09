#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*strlen(s)+1);
    int i, j, k = 1;
    int len = strlen(s);
    int flag = 0;
    
    answer[0] = -1;
    
    for (i=1;i<len;i++)
    {
        flag = 0;
        for (j=i-1;j>=0;j--)
        {
            if (s[i] == s[j])
            {
                answer[k++] = i-j;
                
                flag = 1;
                
                break;
            }
        }
        if (flag == 0) answer[k++] = -1;
    }
    
    return answer;
}
