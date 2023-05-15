#include <stdio.h>

int main(void) {
    int a;
    int b;
    int i,j;
    
    scanf("%d %d", &a, &b);
    //printf("%d", a + b);
    
    for (i=0;i<b;i++)
    {
        for (j=0;j<a;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
