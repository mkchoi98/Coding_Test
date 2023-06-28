#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    long *arr = (long *)malloc(sizeof(long)*(n+1));
    long i;
    
    if (n == 0) arr[0] = 0;
    
    if (n == 1) arr[1] = 1;
    
    
    for (i=2;i<=n;i++)
    {
        arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
    }
    
    answer = arr[n] % 1234567;
    
    free(arr);
    
    return answer;
}
