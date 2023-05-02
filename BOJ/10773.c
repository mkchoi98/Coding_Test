//
//  main.c
//  10773
//
//  Created by 최민경 on 2023/04/11.
//

#include <stdio.h>
#include <stdlib.h>

int sum(int stack[], int top)
{
    int i;
    int sum = 0;
    
    for (i=0;i<top+1;i++)
        sum += stack[i];
    
    return sum;
}

int main(int argc, const char * argv[]) {
    int n;
    int *stack, top = -1;
    int num;
    int i;
    
    scanf("%d", &n);
    
    stack = (int *)malloc(sizeof(int)*n);
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &num);
        
        if (num == 0) top--;
        else stack[++top] = num;
    }
    
    printf("%d", sum(stack, top));
    
    free(stack);
    
    return 0;
}

