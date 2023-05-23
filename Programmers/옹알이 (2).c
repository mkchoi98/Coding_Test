#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    int i, j, k;
    char check[4][4] = {"aya", "ye", "woo", "ma"};
    int flag[4] = {0,};
    int stop = 1;
    
    for (i=0;i<babbling_len;i++)
    {
        if (strlen(babbling[i]) < 2)
            continue;
        
        j = 0;
        while (1)
        {
            for (k=0;k<4;k++)
            {
                // 이전 단어와 겹친 경우
                if (flag[k])
                {
                    flag[0] = flag[1] = flag[2] = flag[3] = 0;
                    continue;
                }
                
                if (strncmp(babbling[i]+j, check[k], strlen(check[k]))==0 && flag[k] == 0)
                {
                    flag[k] = 1;
                    j += strlen(check[k]);
                    
                    stop = 0;
                    break;
                }
                stop = 1;
            }
            if (stop) break;
        }
        if (j == strlen(babbling[i])) answer++;
        
        flag[0] = flag[1] = flag[2] = flag[3] = 0;
    }
    
    return answer;
}
