//
//  main.c
//  9655.c
//
//  Created by 최민경 on 2023/08/31.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int cnt = 0;
    
    scanf("%d", &n);
    
    while (n != 0)
    {
        if (n >= 3) n -= 3;
        
        else n--;
        
        cnt++;
    }
    
    if (cnt % 2 == 1) printf("SK");
    else printf("CY");
    
    return 0;
}
