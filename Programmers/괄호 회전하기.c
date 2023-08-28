#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    char *str = s;
    int answer = 0;
    int len = strlen(s);
    int i, j;
    
    char *stack = (char *)malloc(sizeof(char)*len);
    int top = -1;
    char temp;
    
    int flag = 0;
    
    for (j=0;j<len;j++)
    {
        flag = 0;
        for (i=0;i<len;i++)
        {
            if (top == -1 && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
            {
                flag = 0;
                break;
            }

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack[++top] = s[i];
            }

            else
            {
                if (stack[top] == '(' && s[i] == ')')
                {
                    flag = 1;
                    top--;
                }
                else if (stack[top] == '{' && s[i] == '}')
                {
                    flag = 1;
                    top--;
                }
                else if (stack[top] == '[' && s[i] == ']')
                {
                    flag = 1;
                    top--;
                }
           
                else
                {
                    flag = 0;
                    top--;
                    break;
                }
            }
        }
        
        if (flag == 1 && top == -1) answer++;
        
        temp = str[0];
        
        for (i=0;i<len-1;i++)
        {
            str[i] = str[i+1];
        }
        
        str[i] = temp;
        
    }
    free(stack);
    
    return answer;
}
