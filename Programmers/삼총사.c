#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// number_len은 배열 number의 길이입니다.
int solution(int number[], size_t number_len) {
    int answer = 0;
    int i, j, k;
    
    for (i=0;i<number_len-2;i++)
    {
        for (j=i+1;j<number_len-1;j++)
        {
            for (k=j+1;k<number_len;k++)
            {
                if (number[i] + number[j] + number[k] == 0)
                    answer++;
            }
        }
    }
    
    return answer;
}
