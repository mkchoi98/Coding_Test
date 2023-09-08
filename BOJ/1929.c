//
//  main.c
//  1929
//
//  Created by 최민경 on 2023/09/08.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int m, n;
    int arr[1000001] = {0,};
    
    scanf("%d %d", &m, &n);
    
    int i, j;
    
    arr[1] = 1;
    
    for (i=2;i<=sqrt(n);i++)
    {
        if (arr[i] == 0)
        {
            for (j=2;i*j<=n;j++)
            {
                arr[i*j] = 1;
            }
        }
    }
    
    for (i=m;i<=n;i++)
    {
        if (arr[i] == 0)
            printf("%d\n", i);
    }
    
    return 0;
}
