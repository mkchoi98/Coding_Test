#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = false;
    long top = -1;
    long i;
    
    if (s[0] == ')' || s[strlen(s)-1] == '(') return answer;
    
    for (i=0;i<strlen(s);i++)
    {
        if (s[i] == '(') top++;
        
        else top--;
        
        if (top < -1) return answer;
    }
    
    if (top == -1) answer = true;
    
    return answer;
}
