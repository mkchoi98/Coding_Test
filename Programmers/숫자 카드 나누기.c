#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return 1;
    else if (*(int *)a > *(int *)b)
        return -1;
    else return 0;
}

// arrayA_len은 배열 arrayA의 길이입니다.
// arrayB_len은 배열 arrayB의 길이입니다.
int solution(int arrayA[], size_t arrayA_len, int arrayB[], size_t arrayB_len) {
    int answer = 0;
    int i, j, k;
    
    qsort(arrayA, arrayA_len, sizeof(int), compare);
    qsort(arrayB, arrayB_len, sizeof(int), compare);

    int min = arrayA[arrayA_len-1];
    
    for (i=1;i<=min;i++)
    {
        for (j=0;j<arrayA_len;j++)
        {
            if (arrayA[j] % i != 0)
                break;
        }
        
        if (j == arrayA_len)
        {
            for (k=0;k<arrayB_len;k++)
            {
                if (arrayB[k] % i == 0)
                    break;
            }
            
            if (k == arrayB_len) answer = i;
        }
    }
    
    min = arrayB[arrayB_len-1];
    
    for (i=1;i<=min;i++)
    {
        for (j=0;j<arrayB_len;j++)
        {
            if (arrayB[j] % i != 0)
                break;
        }
        
        if (j == arrayB_len)
        {
            for (k=0;k<arrayA_len;k++)
            {
                if (arrayA[k] % i == 0)
                    break;
            }
            
            if (k == arrayA_len)
            {
                if (answer < i)
                    answer = i;
            }
        }
    }
    
    
    return answer;
}
