//
//  main.c
//  9012
//
//  Created by 최민경 on 2023/09/25.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    char str[51];
    int i, j;
    
    char stack[51];
    int top = -1;
    
    int len;
    int flag = 0;
    
    for (i=0;i<n;i++)
    {
        getchar();
        
        scanf("%s", str);
        
        len = strlen(str);
        flag = 0;
        top = -1;
        
        for (j=0;j<len;j++)
        {
            if (str[j] == '(')
            {
                stack[++top] = str[j];
            }
            
            else
            {
                if (top == -1)
                {
                    printf("NO\n");
                    
                    flag=1;
                    
                    break;
                }
                
                else
                {
                    top--;
                }
            }
        }
        
        if (!flag)
        {
            if (top != -1)
            {
                printf("NO\n");
            }
            
            else
            {
                printf("YES\n");
            }
        }
    }
    
    return 0;
}
