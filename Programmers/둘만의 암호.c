#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s, const char* skip, int index) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*(strlen(s)+1));
    char* s_copy = s;
    
    int i, j = 0, k;
    int n;
    
    for (i=0;i<strlen(s);i++)
    {
        j = 0;
        
        while(j < index)
        {
            s_copy[i] += 1;
            
            if (s_copy[i] > 'z') s_copy[i] = 'a';
            
            for (k=0;k<strlen(skip);k++)
            {
                if (skip[k] == s_copy[i])
                   break;   
            }
            
            if (k < strlen(skip)) continue;
            
            j++;
        }
        answer[i] = s_copy[i];
    }
    
    answer[i] = '\0';
    
    return answer;
}
