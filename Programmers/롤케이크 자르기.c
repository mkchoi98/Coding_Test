#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct topping_cnt
{
    int cnt;
}topping_cnt;

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int i;
    
    int max = 0;
    for (i=0;i<topping_len;i++)
    {
        if (topping[i] > max)
            max = topping[i];
    }
    
    topping_cnt *t = (topping_cnt *)malloc(sizeof(topping_cnt)*(max+1));
    topping_cnt *t_cs = (topping_cnt *)malloc(sizeof(topping_cnt)*(max+1));
    
    int cnt = 0;
    int cnt_cs = 0;
    
    for (i=0;i<topping_len;i++)
    {
        t[topping[i]].cnt = 0;
        t_cs[topping[i]].cnt = 0;
    }
    
    for (i=0;i<topping_len;i++)
    {
        t[topping[i]].cnt++;
        
        if (t[topping[i]].cnt == 1) cnt++;
    }
    
    
        for (i=0;i<topping_len;i++)
        {
            if (t[topping[i]].cnt == 0) continue;
            
            t[topping[i]].cnt--;
            t_cs[topping[i]].cnt++;

            if (t[topping[i]].cnt == 0) cnt--;
            
            if (t_cs[topping[i]].cnt == 1) cnt_cs++;

            if (cnt_cs == cnt) 
            {
                answer++;
            }
        }
    
    
    
    
    return answer;
}
