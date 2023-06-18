//
//  main.c
//  2747
//
//  Created by 최민경 on 2023/06/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int i;
    int a = 0, b = 1;
    int answer;
    
    scanf("%d", &n);
    
    if (n < 2)
    {
        printf("%d", n);
        return 0;
    }
    
    for (i=1;i<=n-1;i++)
    {
        answer = a+b;
        a = b;
        b = answer;
    }
    
    printf("%d", answer);
    
    return 0;
}
