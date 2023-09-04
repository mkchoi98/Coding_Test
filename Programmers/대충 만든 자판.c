#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// keymap_len은 배열 keymap의 길이입니다.
// targets_len은 배열 targets의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*targets_len);
    int i, j, u, v;
    int min_index = 0;
    
    for (i=0;i<targets_len;i++)
    {
        answer[i] = 0;
    }
    
    for (i=0;i<targets_len;i++)
    {
        for (j=0;j<strlen(targets[i]);j++)
        {
            min_index = 10000;
            for (u=0;u<keymap_len;u++)
            {   
                for (v=0;v<strlen(keymap[u]);v++)
                {
                    if (targets[i][j] == keymap[u][v])
                    {
                        if (min_index >= v) min_index = v;
                        
                        break;
                    }
                }
            }
            
            if (min_index != 10000)
                answer[i] += min_index+1;
            else 
            {
                answer[i] = -1;
                
                break;
            }
        }
    }
    
    return answer;
}
