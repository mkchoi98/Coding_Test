/
//  main.c
//  10828
//
//  Created by 최민경 on 2023/04/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int stack[], int num, int *top)
{
    stack[++(*top)] = num;
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("-1\n");
        return ;
    }
    
    printf("%d\n", stack[(*top)--]);
}

void top_func(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("-1\n");
        return ;
    }
    
    printf("%d\n", stack[*top]);
}

void empty(int top)
{
    if (top == -1)
    {
        printf("1\n");
        return;
    }
    
    printf("0\n");
}

int main(int argc, const char * argv[]) {
    int n;
    char str[6];
    int top = -1;
    int *stack;
    int i;
    int num;
    
    scanf("%d", &n);
    
    stack = (int *)malloc(sizeof(int)*n);
    
    for (i=0;i<n;i++)
    {
        scanf("%s", str);
        if (strcmp(str, "push")==0)
        {
            scanf("%d", &num);
            
            push(stack, num, &top);
        }
        else if (strcmp(str, "pop")==0)
        {
            pop(stack, &top);
        }
        
        else if (strcmp(str, "size")==0)
        {
            printf("%d\n", top+1);
        }
        
        else if (strcmp(str, "empty")==0)
        {
            empty(top);
        }
        
        else if (strcmp(str, "top")==0)
        {
            top_func(stack, &top);
        }
    }
    
    free(stack);
    
    return 0;
}

