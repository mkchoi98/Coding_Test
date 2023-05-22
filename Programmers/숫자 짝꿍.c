#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* X, const char* Y) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer;
    int arr_x[10] = {0, }, arr_y[10] = {0, };
    char* y = Y;
    long long i, j;
    char temp;
    int index = -1;
    
    if (strlen(X) > strlen(Y))
        answer = (char *)malloc(sizeof(char)*strlen(Y));
    else
        answer = (char *)malloc(sizeof(char)*strlen(X));
    
    for (i=0;i<strlen(X);i++)
        arr_x[X[i] - '0']++;
        
    for (i=0;i<strlen(Y);i++)
        arr_y[Y[i] - '0']++;
    
    for (i=9;i>=0;i--)
    {
        if ((arr_x[i] >= arr_y[i]) && (arr_x[i] != 0 && arr_y[i] != 0))
        {
            for (j=0;j<arr_y[i];j++)
                answer[++index] = i+'0';
        }
        else if ((arr_x[i] < arr_y[i]) && (arr_x[i] != 0 && arr_y[i] != 0))
        {
            for (j=0;j<arr_x[i];j++)
                answer[++index] = i+'0';
        }
    }
    
    if (answer[0]-'0' == 0)
        return "0";
    
    if (index == -1)
        return "-1";
    
    answer[++index] = '\0';
    
    return answer;
}
