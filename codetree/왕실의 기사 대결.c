#include <stdio.h>

typedef struct Knight
{
    int r, c, h, w, k;
    int damage;
    int status;
}Knight;

void moveKnight(Knight knight[], int L, int num, int d, int arr[][41], int arrKnight[][41])
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int next_x, next_y;

    int i, j;

    
}

int main() {
    Knight knight[31];
    int L, N, Q;
    int arr[41][41] = {0,};
    int arrKnight[41][41] = {0,};

    scanf("%d %d %d", &L, &N, &Q);

    int i, j, s, t;

    for (i=1;i<=L;i++)
    {
        for (j=1;j<=L;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int r, c, h, w, k;

    for (i=1;i<=N;i++)
    {
        scanf("%d %d %d %d %d", &knight[i].r, &knight[i].c, &knight[i].h, &knight[i].w, &knight[i].k);
        knight[i].status = 0;

        for (s=knight[i].r;s<knight[i].r+knight[i].h;s++)
        {
            for (t=knight[i].c;t<knight[i].c+knight[i].w;t++)
            {
                arrKnight[s][t] = i;
            }
        }
    }

    int num; // 기사의 번호
    int d;
    
    for (i=0;i<Q;i++)
    {
        scanf("%d %d", &num, &d);
    }


    // for (s=1;s<=L;s++)
    // {
    //     for (t=1;t<=L;t++)
    //     {
    //         printf("%2d", arrKnight[s][t]);
    //     }
    //     printf("\n");
    // }

    return 0;
}
