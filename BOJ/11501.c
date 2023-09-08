//
//  main.c
//  11501
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int t, n;
    int arr[1000001];
    
    scanf("%d", &t);
    
    int i, j;
    int max = 0;
    long long sum = 0;
    
    for (i=0;i<t;i++)
    {
        scanf("%d", &n);
        
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[j]);
        }
        
        max = 0;
        sum = 0;
        
        for (j=n-1;j>=0;j--)
        {
            if (arr[j] >= max)
            {
                max = arr[j];
            }
            
            else sum += max-arr[j];
        }
        
        printf("%lld\n", sum);
    }
    
    return 0;
}
