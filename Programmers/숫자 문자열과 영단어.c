#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char arr[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char answer_arr[50]="";
    int i = 0, j = 0, answer_index = 0;

    while (i < strlen(s))
    {
        if (s[i]-'0' >= 0 && s[i]-'0' <= 9)
        {
            answer_arr[answer_index++] = s[i++];
            continue;
        }
        
        for (j=0;j<10;j++)
        {
            if (memcmp(&s[i], &arr[j], strlen(arr[j])) == 0)
            {
                answer_arr[answer_index++] = j + '0';
                i += strlen(arr[j]);
                
                break;
            }
        }
    }
    
    answer = atoi(answer_arr);
    
    return answer;
}
