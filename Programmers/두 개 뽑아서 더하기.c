#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer;
    int* sum_arr;
    int temp;
    int flag=0;
    int i, j, k =0, l =0;
    int max_len = 0;
    
    for (i=numbers_len-1;i>=1;i--)
    {
        max_len += i;   
    }
    
    answer = (int*)malloc(sizeof(int)*max_len);
    sum_arr = (int*)malloc(sizeof(int)*max_len);
    
    for (i=0;i<numbers_len-1;i++)
    {
        for (j=i+1;j<numbers_len;j++)
        {
            sum_arr[k++] = numbers[i] + numbers[j];
        }
    }
    
    for (i=0;i<k-1;i++)
    {
       flag = 0;
        for (j=i+1;j<k;j++)
        {
            if (sum_arr[i] == sum_arr[j])
                flag = 1;
        }
       if (flag == 0)
           answer[l++] = sum_arr[i];
    }
    
    answer[l++] = sum_arr[i];
    
    for (i=0;i<l-1;i++)
    {
        for (j=i+1;j<l;j++)
        {
            if (answer[i] > answer[j])
            {
                temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    
    free(sum_arr);
    
    return answer;
}
