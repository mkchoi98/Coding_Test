#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) {
    int answer = 0;
    
    long long convert = 0;
    long long i = 1;
    int j = 0, u;
    
    int *num;
    
    while (n > 0)
    {
        convert += (n % k)*i;
        
        n /= k;
        i *= 10;
        
        j++;
    }
    
    num = (int *)malloc(sizeof(int)*j);
    
    i /= 10;
    
    for (u=0;u<j;u++)
    {
        num[u] = convert / i;
        
        convert %= i;
        i /= 10;
    }
    
    int m = 0;
    int index;
    int a = 1;
    
    int flag = 0;
    
    for (i=0;i<=j;i++)
    {
        m = 0;
        a = 1;
        
        if (num[i] == 0 || i == j)
        {
            index = i;
        
            u = index - 1;
            
            if (num[u] == 0) continue;
            
            while (1)
            {
                m += a*num[u];
                
                a *= 10;
                
                u--;
                
                if (u == -1 || num[u] == 0) break;
            }
            
            flag = 0;
            
            for (u=2;u<m;u++)
            {
                if (m % u == 0)
                {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0 && m != 1) answer++;
        }
    }
    
    free(num);
    
    return answer;
}
