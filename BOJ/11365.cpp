//
//  main.cpp
//  11365
//
//  Created by 최민경 on 2024/03/05.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[501];
    
    while (1)
    {
        gets(str);
        
        if (strcmp("END", str) == 0)
        {
            break;
        }
        
        int len = strlen(str);
        
        for (int i=len-1;i>=0;i--)
        {
            printf("%c", str[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}
