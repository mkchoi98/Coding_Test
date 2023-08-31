//
//  main.c
//  10431
//
//  Created by 최민경 on 2023/08/31.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n;
    int p[1000][20];
    
    scanf("%d", &n);
    
    int i, j, k;
    
    int num;
    
    for (i=0;i<n;i++)
    {
        scanf("%d", &num);
        for (j=0;j<20;j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    
    int temp;
    
    int cnt;
    
    for (i=0;i<n;i++)
    {
        cnt = 0;
        for (j=1;j<20;j++)
        {
            for (k=0;k<j;k++)
            {
                if (p[i][j] < p[i][k])
                {
                    cnt++;
                }
            }
        }
        printf("%d %d\n", i+1, cnt);
    }
    
    
    return 0;
}

/*#include <stdio.h>

int T,num[21],N;

int main() {
    scanf("%d", &T);
    while(T--){
        int sum = 0;
        scanf("%d", &N);
        for (int i = 0; i < 20; i++) scanf("%d", num + i);
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j < i; j++) {
                if (num[j] > num[i]) sum++;
            }
        }
        printf("%d %d\n",N,sum);
    }
    return 0;
}
*/
