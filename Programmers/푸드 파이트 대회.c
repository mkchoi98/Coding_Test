#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*10000);
    char* flip = (char*)malloc(sizeof(char)*10000);
    int i, j, k = 0, l= 0;
    
    for (i=1;i<food_len;i++)
    {
        for(j=0;j<food[i]/2;j++)
        {
            answer[k++] = i + '0';
        }
    }
    
    for (i=food_len-1;i>= 1;i--)
    {
        for(j=0;j<food[i]/2;j++)
        {
            flip[l++] = i + '0';
        }
    }
    
    answer[k++] = 0 + '0';
    answer[k] = '\0';
    flip[l] = '\0';
    
    strcat(answer, flip);
    
    return answer;
}
