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

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    int i, j;
    
    qsort(A, A_len, sizeof(int), compare);
    qsort(B, B_len, sizeof(int), compare);
    
    for (i=0, j=B_len-1;i<A_len, j>=0;i++, j--)
    {
        answer += A[i] * B[j];
    }
    
    return answer;
}
