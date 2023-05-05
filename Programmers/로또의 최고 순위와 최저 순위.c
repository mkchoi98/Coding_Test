#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*2);
    int i, j;
    int cnt = 0, zero_cnt = 0;
    
    for (i=0;i<lottos_len;i++)
    {
        if (lottos[i] == 0)
        {
            zero_cnt++;
            continue;
        }
        
        for (j=0;j<win_nums_len;j++)
        {
            if (lottos[i] == win_nums[j]) cnt++;
        }
    }
    
    if (zero_cnt == 6)
    {
        answer[0] = 1;
        answer[1] = 6;
        
        return answer;
    }
    
    if (cnt == 0)
    {
        answer[0] = answer[1] = 6;
        
        return answer;
    }
    
    for (i=1;i<=6;i++)
    {
        if (cnt+zero_cnt == i) answer[0] = 7-i;
        if (cnt == i) answer[1] = 7-i;
    }
    
    return answer;
}
