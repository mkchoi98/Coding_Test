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

// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*score_len);
    int *arr = (int *)malloc(sizeof(int)*score_len);
    int i, j;
    
    for (i=0;i<score_len;i++)
    {
        if (i == 0)
        {
            answer[i] = score[i];
            arr[i] = score[i];
            
            continue;
        }
        
        if (i < k)
        {
            arr[i] = score[i];

            qsort(arr, i+1, sizeof(int), compare);

            answer[i] = arr[0];
        }
        
        else
        {
            if (arr[0] < score[i])
            {
                arr[0] = score[i];
                qsort(arr, k, sizeof(int), compare);
            }
            
            answer[i] = arr[0];
        }
    }
    
    return answer;
}
