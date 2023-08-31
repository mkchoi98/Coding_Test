//
//  main.c
//  1157
//
//  Created by 최민경 on 2023/08/31.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[1000000];
    
    scanf("%s", str);
    
    long len = strlen(str);
    
    long i;
    
    int cnt[26] = {0,};
    int index;
    
    for (i=0;i<len;i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i]-65;
            cnt[index]++;
        }
        
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i]-97;
            cnt[index]++;
        }
    }
    
    int max = 0, max_index = 0;
    int same = 0;
    
    for (i=0;i<26;i++)
    {
        if (cnt[i] >= max && cnt[i] != 0)
        {
            if (cnt[i] == max)
            {
                same = 1;
            }
            
            else same = 0;
            
            max = cnt[i];
            max_index = i;
        }
    }
    
    if (same == 0) printf("%c", max_index+65);
    else printf("?");
    
    return 0;
}
