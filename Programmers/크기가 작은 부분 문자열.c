#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    int i, j;
    int num;
    
    for (i=0;i<=strlen(t)-strlen(p);i++)
    {
        for (j=0;j<strlen(p);j++)
        {
            if (p[j]-'0' > t[i+j]-'0')
            {
                answer++;
                
                break;
            }
            
            else if (p[j]-'0' < t[i+j]-'0') break;
        }
        
        if (j == strlen(p)) answer++;
    }
    
    return answer;
}
