#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// wallpaper_len은 배열 wallpaper의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*4);
    int i, j;
    int len = strlen(wallpaper[0]);
    
    int min_x=51, min_y=51, max_x=0, max_y=0;
    
    for (i=0;i<wallpaper_len;i++)
    {
        for (j=0;j<len;j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (i > max_x) max_x = i;
                if (j > max_y) max_y = j;
                if (i < min_x) min_x = i;
                if (j < min_y) min_y = j;
            }
        }
    }
    
    answer[0] = min_x;
    answer[1] = min_y;
    answer[2] = max_x + 1;
    answer[3] = max_y + 1;
    
    return answer;
}
