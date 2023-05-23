//
//  main.c
//  2331
//
//  Created by 최민경 on 2023/05/23.
//

#include <stdio.h>

void DFS(int A, int P, int visited[])
{
    int sum = 0, num;
    int i;
    
    visited[A] += 1;
    
    while (A > 0){
        num = 1;
        for (i=0;i<P;i++)
        {
            num *= A%10;
        }
        sum += num;
        A/=10;
    }
    
    if (visited[sum] == 2) return ;
    
    DFS(sum, P, visited);
}

int main(int argc, const char * argv[]) {
    int A, P;
    int visited[300000]={0};
    int cnt = 0;
    int i;
    
    scanf("%d %d", &A, &P);
    
    DFS(A, P, visited);
    
    for (i=0;i<300000;i++)
    {
        if (visited[i] == 1) cnt++;
    }
    
    printf("%d", cnt);
    
    return 0;
}
