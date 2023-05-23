#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char x;
    int x_cnt=0, other_cnt=0;
    int i = 0;
    
    while(i < strlen(s))
    {
        x = s[i++];
        
        x_cnt = 1;
        other_cnt = 0;
        
        while (x_cnt != other_cnt)
        {
            if (s[i++] != x)
            {
                other_cnt++;
                continue;
            }
            
            x_cnt++;
        }
        answer++;
    }
    
    return answer;
}
