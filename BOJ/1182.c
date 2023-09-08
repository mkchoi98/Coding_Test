//
//  main.c
//  1182
//
//  Created by 최민경 on 2023/09/08.
//

#include <stdio.h>

void DFS(int arr[], int num[], int visited[], int n, int s, int *cnt, int index, int start)
{
    int i;
    int sum;
    
    if (index == n+1) return ;
    
    sum = 0;
    
    for (i=0;i<index;i++)
    {
        sum += arr[i];
    }
    
    if (sum == s && index != 0)
    {
        (*cnt)++;
    }
    
    
    
    for (i=start;i<n;i++)
    {
        
        visited[i] = 1;
        arr[index] = num[i];
        index++;
        start++;
        DFS(arr, num, visited, n, s, cnt, index, start);
        index--;
        
    }
}

int main(int argc, const char * argv[]) {
    int n, s;
    
    scanf("%d %d", &n, &s);
    
    int i;
    int num[21];
    int visited[21] = {0,};
    
    int cnt = 0;
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &num[i]);
    }
    
    int arr[21];
    
    DFS(arr, num, visited, n, s, &cnt, 0, 0);
    
    printf("%d", cnt);
    
    return 0;
}
