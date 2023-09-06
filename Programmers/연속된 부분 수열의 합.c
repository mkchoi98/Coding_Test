#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
int* solution(int sequence[], size_t sequence_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*2);
    int s = 0, e = 0;
    int sum = sequence[0];
    int len = 0, min_len = sequence_len+1;
    
    while (e < sequence_len)
    {
        len = e-s+1;
        
        if (sum == k)
        {
            if (len < min_len)
            {
                answer[0] = s;
                answer[1] = e;
                
                min_len = len;
            }
            
            if (len == min_len)
            {
                if (answer[0] > s)
                {
                    answer[0] = s;
                    answer[1] = e;
                }
            }
            
            sum -= sequence[s++];
            sum += sequence[++e];
        }
        
        else if (sum > k)
        {
            sum -= sequence[s++];
            
            //printf("%d\n", s);
        }
        
        else if (sum < k)
        {
            sum += sequence[++e];
        }
    }
    
    return answer;
}
