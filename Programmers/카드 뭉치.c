#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cards1_len은 배열 cards1의 길이입니다.
// cards2_len은 배열 cards2의 길이입니다.
// goal_len은 배열 goal의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*4);
    int i = 0, j = 0, k = 0;
    
    while (k < goal_len)
    {
        if (i < cards1_len && strcmp(goal[k], cards1[i]) == 0)
        {
            k++;
            i++;
        }
        
        else if (j < cards2_len && strcmp(goal[k], cards2[j]) == 0 )
        {
            k++;
            j++;
        }
        
        else break;
    }
    
    if (k != goal_len) answer = "No";
    else answer = "Yes";
    
    return answer;
}
