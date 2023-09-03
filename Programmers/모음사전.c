#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void dfs(char str[], char *word, char aeiou[], int *cnt, int *index, int *answer)
{
    int i;
        
    if (strcmp(str, word) == 0)
    {
        *answer = *cnt;
        
        return;
    }
    
    (*cnt)++;
    
    if (*index == 5) return ;
    
    
    for (i=0;i<5;i++)
    {
        str[*index] = aeiou[i];

        (*index)++;
        str[*index] = '\0';
        
        dfs(str, word, aeiou, cnt, index, answer);
        
        (*index)--;
    }
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* word) {
    int answer = 0;
    int cnt = 0;
    char aeiou[5] = {'A', 'E', 'I', 'O', 'U'};
    int index = 0;
    char str[6];
    
    dfs(str, word, aeiou, &cnt, &index, &answer);
    
    return answer;
}
