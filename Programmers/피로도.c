#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void DFS(int** dongeons, int visited[], int rows, int cnt, int *max, int k)
{
    int i;
    
    if (cnt > *max) *max = cnt;

    if (*max == rows) return;
    
    for (i=0;i<rows;i++)
    {
        if (visited[i] == 0 && dongeons[i][0] <= k)
        {
            visited[i] = 1;
            DFS(dongeons, visited, rows, cnt+1, max, k-dongeons[i][1]);
            visited[i] = 0;
        }
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int answer = -1;
    int max = 0;
    int cnt = 0;
    
    int visited[8] = {0,};
    
    DFS(dungeons, visited, dungeons_rows, cnt, &max, k);
    
    return max;
}
