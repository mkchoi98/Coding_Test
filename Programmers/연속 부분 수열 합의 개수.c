#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
int solution(int elements[], size_t elements_len) {
    int answer = 0;
    int i, j, k;
    
    int *elements_copy = (int *)malloc(sizeof(int)*(2*elements_len));
    
    for (i=0;i<elements_len;i++)
    {
        elements_copy[i] = elements[i];
    }
    
    for (i=elements_len;i<elements_len*2;i++)
    {
        elements_copy[i] = elements[i-elements_len];
    }
    
    int *sum_arr = (int *)malloc(sizeof(int)*10000000);
    
    for (i=0;i<10000000;i++)
        sum_arr[i]= 0;
    
    int sum = 0;
    
    int front, rear;
    
    for (i=1;i<elements_len;i++)
    {
        front = 0;
        rear = i;
        
        while(1)
        {
            sum = 0;

            for (j=front;j<rear;j++)
            {
                sum += elements_copy[j];
            }
            
            sum_arr[sum]++;
            
            front++;
            rear++;
            
            if (front == elements_len) break;
        }
        
    }
    
    for (i=0;i<elements_len;i++)
    {
        sum += elements[i];
    }
    
    sum_arr[sum]++;
    
    for (i=0;i<10000000;i++)
    {
        if (sum_arr[i] != 0) answer++;
    }
    
    free(sum_arr);
    free(elements_copy);
    
    return answer;
}
