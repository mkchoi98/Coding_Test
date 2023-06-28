#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int arr[100000];
    long i = 0, j, ternary = 1;
    
    while (n > 0)
    {
        arr[i++] = n % 3;
        
        n /= 3;
    }
    
    for (j=i-1;j>=0;j--)
    {
        answer += arr[j] * ternary;
        
        ternary *= 3;
    }
    
    return answer;
}
