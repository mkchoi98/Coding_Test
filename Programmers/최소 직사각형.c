#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int width_max = 0, height_max = 0;
    int temp;
    int i;
    
    for (i=0;i<sizes_rows;i++)
    {
        if (sizes[i][0] > sizes[i][1])
        {
            temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    
    for (i=0;i<sizes_rows;i++)
    {
        if (sizes[i][0] > width_max)
            width_max = sizes[i][0];
        
        if (sizes[i][1] > height_max)
            height_max = sizes[i][1];
    }
    
    answer = width_max * height_max;
    
    return answer;
}
