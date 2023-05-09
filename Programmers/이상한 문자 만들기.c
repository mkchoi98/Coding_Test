#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(sizeof(char)*len);
    int i;
    int index = 0;
    
    for (i=0;i<len;i++)
    {
        if (s[i] == ' ')
        {
            index = 0;
            answer[i] = ' ';
            
            continue;
        }
        
        if (index % 2 == 0)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') answer[i] = s[i];
            else if (s[i] >= 'a' && s[i] <= 'z') answer[i] = s[i] - 32;
            
            index++;
        }
        
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z') answer[i] = s[i] + 32;
            else if (s[i] >= 'a' && s[i] <= 'z') answer[i] = s[i];
            
            index++;
        }
    }
    
    answer[i] = '\0';
    
    return answer;
}
