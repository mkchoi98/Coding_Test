//
//  main.c
//  2847
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int arr[100];
    
    scanf("%d", &n);
    
    int i;
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int cnt = 0;
    
    for (i=n-1;i>=1;i--)
    {
        while (arr[i] <= arr[i-1])
        {
            arr[i-1] -= 1;
            
            cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}
