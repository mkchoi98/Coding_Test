#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else  return 0;
}

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    int *cnt;
    int max = 0;
    int i, j;
    
    for (i=0;i<tangerine_len;i++)
    {
        if (tangerine[i] > max)
            max = tangerine[i];
    }
    
    cnt = (int *)malloc(sizeof(int)*(max+1));
    
    for (i=0;i<=max;i++)
    {
        cnt[i] = 0; 
    }
    
    for (j=0;j<tangerine_len;j++)
    {
        cnt[tangerine[j]]++;
    }
    
    qsort(cnt, max+1, sizeof(int), compare);
    
    int sum = 0;
    
    i = max;
    
    while (sum < k)
    {
        sum += cnt[i--];
        
        answer++;
    }
    
    free(cnt);
    
    return answer;
}
