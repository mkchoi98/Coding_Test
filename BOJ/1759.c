//
//  main.c
//  1759
//
//  Created by 최민경 on 2023/09/08.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const char *a, const char *b)
{
    if (*(char *)a > *(char *)b)
        return 1;
    else if (*(char *)a < *(char *)b)
        return -1;
    else return 0;
}

void DFS(char ch[], char str[], int l, int c, int index, int start)
{
    int i;
    
    if (index == l)
    {
        int a_cnt = 0; //모음 개수
        int b_cnt = 0; //자음 개수
        
        for (i=0;i<l;i++)
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                a_cnt++;
            else b_cnt++;
        }
        
        if (a_cnt >= 1 && b_cnt >= 2)
        {
            str[l] = '\0';
            printf("%s\n", str);
        }
        
        return ;
    }
    
    for (i=start;i<c;i++)
    {
        str[index] = ch[i];
        index++;
        start++;
        DFS(ch, str, l, c, index, start);
        index--;
    }
}

int main(int argc, const char * argv[]) {
    int l, c;
    char ch[15];
    
    scanf("%d %d", &l, &c);
    
    int i;
    
    for (i=0;i<c;i++)
    {
        getchar();
        scanf("%c", &ch[i]);
    }
    
    qsort(ch, c, sizeof(char), compare);
    
    /*for (i=0;i<c;i++)
    {
        printf("%c ", ch[i]);
    }
    printf("\n");*/
    
    char str[16];
    
    DFS(ch, str, l, c, 0, 0);
    
    return 0;
}
