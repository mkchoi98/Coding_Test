//
//  main.c
//  14916
//
//  Created by 최민경 on 2023/09/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int cnt = 0;
    int min;
    
    scanf("%d", &n);
    
    int num = n;
    
    while (num >= 5)
    {
        cnt++;
        
        num -= 5;
    }
    
    while (num >= 2)
    {
        cnt++;
        
        num -= 2;
    }
    
    if (num != 0) min = 100000;
    
    else min = cnt;
     
   cnt = 0;
    
    while (n >= 2)
    {
        cnt++;
        
        n -= 2;
        
        if (n % 5 == 0) break;
    }
    
    while (n >= 5)
    {
        cnt++;
        
        n -= 5;
    }
    
    if (cnt < min && n == 0) min = cnt;
    
    if (min == 100000) printf("-1");
    else printf("%d", min);
    
    return 0;
}
