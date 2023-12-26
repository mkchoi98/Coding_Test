#include <stdio.h>

typedef struct Knight
{
    int r, c, h, w, k;
    int damage;
    int flag; // 이동을 나타내는 플래그
}Knight;

typedef struct Queue
{
    int num[900]; // 기사의 번호
    int front, rear;
}Queue;

void moveKnight(Knight knight[], int arr[][41], int num ,int d, int L, int N)
{
    Queue que;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int i, j;
    int cur_num;

    que.front = que.rear = -1;

    que.num[++que.rear] = num;

    while (que.front < que.rear)
    {
        cur_num = que.num[++que.front];

        if (knight[cur_num].r + dx[d] < 1 || knight[cur_num].c + dy[d] < 1 || knight[cur_num].r + knight[cur_num].h + dx[d] - 1 > L || knight[cur_num].c + knight[cur_num].w + dy[d] - 1 > L)
        {
            return ;
        }
        
        for (i=knight[cur_num].r + dx[d];i<=knight[cur_num].r + knight[cur_num].h + dx[d] - 1;i++)
        {
            for (j=knight[cur_num].c + dy[d];j<=knight[cur_num].c + knight[cur_num].w + dy[d] - 1;j++)
            {
                if (arr[i][j] == 2)
                {
                    return ;
                }
            }
        }

        knight[cur_num].flag = 1;

        for (i=1;i<=N;i++)
        {
            if (i == cur_num) continue;

            if (knight[i].r + knight[i].h - 1 < knight[cur_num].r + dx[d]) continue;
            if (knight[cur_num].r + knight[cur_num].h + dx[d] - 1 < knight[i].r) continue;
            if (knight[i].c + knight[i].w - 1 < knight[cur_num].c + dy[d]) continue;
            if (knight[cur_num].c + knight[cur_num].w + dy[d] - 1 < knight[i].c) continue;

            if (knight[i].k <= 0) continue;
            //printf("@@%d@@\n", i);
            que.num[++que.rear] = i;
        }
    }

    int s, t;

    //if (que.front == que.rear)
    {
        for (i=1;i<=N;i++)
        {
            if (knight[i].flag == 1)
            {
                knight[i].r += dx[d];
                knight[i].c += dy[d];
                knight[i].flag = 0;

                if (i != num)
                {
                    for (s=knight[i].r;s<=knight[i].r+knight[i].h-1;s++)
                    {
                        for (t=knight[i].c;t<=knight[i].c+knight[i].w-1;t++)
                        {
                            if (arr[s][t] == 1)
                            {
                                knight[i].k--;
                                knight[i].damage++;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    Knight knight[31];
    int arr[41][41] = {0,};
    int L, N, Q;

    scanf("%d %d %d", &L, &N, &Q);

    int i, j;
    int r, c, h, w, k;

    for (i=1;i<=L;i++)
    {
        for (j=1;j<=L;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i=1;i<=N;i++)
    {
        scanf("%d %d %d %d %d", &r, &c, &h, &w, &k);

        knight[i].r = r;
        knight[i].c = c;
        knight[i].h = h;
        knight[i].w = w;
        knight[i].k = k;
        knight[i].damage = 0;
        knight[i].flag = 0;
    }

    int num, d;

    for (i=0;i<Q;i++)
    {
        scanf("%d %d", &num, &d);

        if (knight[num].k <= 0) continue; 
        
        moveKnight(knight, arr, num, d, L, N);

        for (j=1;j<=N;j++)
        {
            knight[j].flag = 0;
        }
    }

    int answer = 0;

    for (i=1;i<=N;i++)
    {
        if (knight[i].k > 0)
        {
            answer += knight[i].damage;
        }
    }

    printf("%d", answer);

    return 0;
}
