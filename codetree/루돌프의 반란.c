#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Santa
{
    int score;
    int r, c;
    int status; // 1이면 기절
}Santa;

void interactionSanta(Santa santa[], int arr[][51], int N, int index, int dx[], int dy[], int r, int c)
{
    int temp;
    int i, j;

    int next_x = r;
    int next_y = c;

    int cnt = 0;

    while (arr[next_x][next_y] != 0 /*|| (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N)*/)
    {
        next_x += dx[index];
        next_y += dy[index];

        if (next_x < 1 && next_x > N && next_y < 1 && next_y > N)
        {
            next_x -= dx[index];
            next_y -= dy[index];

            break;
        }

        cnt++;
    }

    for (i=0;i<cnt;i++)
    {
        arr[next_x][next_y] = arr[next_x+dx[(index+2)%4]][next_y+dy[(index+2)%4]];
        santa[arr[next_x][next_y]].r = next_x;
        santa[arr[next_x][next_y]].c = next_y;

        next_x += dx[(index+2)%4];
        next_y += dy[(index+2)%4];
    }
    
}

void interactionRudolf(Santa santa[], int arr[][51], int N, int index, int dx[], int dy[], int r, int c)
{
    int temp;
    int i, j;

    int next_x = r;
    int next_y = c;

    int cnt = 0;

    while (arr[next_x][next_y] != 0 /*|| (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N)*/)
    {
        next_x += dx[index];
        next_y += dy[index];

        //if (next_x < 1 && next_x > N && next_y < 1 && next_y > N) break;

        if (next_x < 1 && next_x > N && next_y < 1 && next_y > N)
        {
            next_x -= dx[index];
            next_y -= dy[index];

            break;
        }


        cnt++;
    }

    for (i=0;i<cnt;i++)
    {
        arr[next_x][next_y] = arr[next_x+dx[(index+4)%8]][next_y+dy[(index+4)%8]];
        santa[arr[next_x][next_y]].r = next_x;
        santa[arr[next_x][next_y]].c = next_y;

        next_x += dx[(index+4)%8];
        next_y += dy[(index+4)%8];
    }
}

void moveRudolf(Santa santa[], int arr[][51], int N, int P, int C, int *Rr, int *Rc)
{
    int i, j;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int minDistance = 25000;
    int minR, minC;

    for (i=1;i<=N;i++)
    {
        for (j=1;j<=N;j++)
        {
            if (arr[i][j] != 0)
            {
                int dis = pow(i-(*Rr), 2) + pow(j-(*Rc), 2);

                if (dis < minDistance)
                {
                    minDistance = dis;
                    minR = i;
                    minC = j;
                }

                else if (dis == minDistance)
                {
                    if (i > minR)
                    {
                        minR = i;
                        minC = j;
                    }

                    else if (i == minR)
                    {
                        if (j > minC)
                        {
                            minC = j;
                        }
                    }
                }
            }
        }
    }

    int index = -1;

    if (minR < *Rr && minC == *Rc)
    {
        *Rr += dx[0];
        *Rc += dy[0];

        index = 0;
    }

    else if (minR < *Rr && minC > *Rc)
    {
        *Rr += dx[1];    
        *Rc += dy[1];
        
        index = 1;
    }

    else if (minR == *Rr && minC > *Rc)
    {
        *Rr += dx[2];
        *Rc += dy[2];

        index = 2;
    }

    else if (minR > *Rr && minC > *Rc)
    {
        *Rr += dx[3];
        *Rc += dy[3];

        index = 3;
    }

    else if (minR > *Rr && minC == *Rc)
    {
        *Rr += dx[4];
        *Rc += dy[4];

        index = 4;
    }

    else if (minR > *Rr && minC < *Rc)
    {
        *Rr += dx[5];
        *Rc += dy[5];

        index = 5;
    }

    else if (minR == *Rr && minC < *Rc)
    {
        *Rr += dx[6];
        *Rc += dy[6];

        index = 6;
    }

    else if (minR < *Rr && minC < *Rc)
    {
        *Rr += dx[7];
        *Rc += dy[7];

        index = 7;
    }

    int temp = 0;

    if (index != -1) 
    {
        for (i=1;i<=P;i++)
        {
            if (*Rr == santa[i].r && *Rc == santa[i].c) // 충돌 발생
            {
                temp = arr[santa[i].r][santa[i].c];

                arr[santa[i].r][santa[i].c] = 0;

                santa[i].r += C * dx[index];
                santa[i].c += C * dy[index];
                santa[i].score += C;
                santa[i].status+=2; // 기절

                // 상호작용
                if (arr[santa[i].r][santa[i].c] != 0 /*&& santa[i].r >= 1 && santa[i].r <= N && santa[i].c >= 1 && santa[i].c <= N*/)
                {
                    interactionRudolf(santa, arr, N, index, dx, dy, santa[i].r, santa[i].c);
                    arr[santa[i].r][santa[i].c] = temp;
                }

                else if (arr[santa[i].r][santa[i].c] == 0 && santa[i].r >= 1 && santa[i].r <= N && santa[i].c >= 1 && santa[i].c <= N)
                {
                    arr[santa[i].r][santa[i].c] = i;
                }
            }
        }
    }
}

void moveSanta(Santa santa[], int arr[][51], int N, int P, int Rr, int Rc, int D)
{
    int i, j, k;
    int minDistance = 25000;
    int minIndex = -1;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int next_x, next_y;

    for (k=1;k<=P;k++)
    {
        if (santa[k].status > 0)
        {
            //printf("%d\n", k);
            santa[k].status--;
            
            continue;
        }

        minDistance = 25000;
        minIndex = -1;
        if (santa[k].r >= 1 && santa[k].r <= N && santa[k].c >= 1 && santa[k].c <= N && santa[k].status == 0)
        {
            int dis = pow(santa[k].r - Rr, 2) + pow(santa[k].c - Rc, 2);

            for (i=0;i<4;i++)
            {
                next_x = santa[k].r + dx[i];
                next_y = santa[k].c + dy[i];

                int newDistance = pow(next_x - Rr, 2) + pow(next_y - Rc, 2);

                if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N && (dis > newDistance) && (minDistance > newDistance) && arr[next_x][next_y] == 0)
                {
                    minIndex = i;
                    minDistance = newDistance;
                }
            }

            int temp = 0;


            if (minIndex != -1)
            {
                temp = arr[santa[k].r][santa[k].c];

                arr[santa[k].r][santa[k].c] = 0;

                santa[k].r += dx[minIndex];
                santa[k].c += dy[minIndex];

                //arr[santa[k].r][santa[k].c] = k;
            }

            if (Rr == santa[k].r && Rc == santa[k].c) // 루돌프와 충돌 발생
            {
                arr[santa[k].r][santa[k].c] = 0;

                santa[k].score += D;

                santa[k].r += D*dx[(minIndex+2)%4];
                santa[k].c += D*dy[(minIndex+2)%4];

                //printf("%d %d\n", santa[k].r, santa[k].c);

                santa[k].status += 2;
                        
                // 상호작용 추가
                if (arr[santa[k].r][santa[k].c] != 0)
                {
                    interactionSanta(santa, arr, N, (minIndex+2)%4, dx, dy, santa[k].r, santa[k].c);
                    arr[santa[k].r][santa[k].c] = temp;
                }

                else
                {
                    arr[santa[k].r][santa[k].c] = k;
                }
            }

            else
            {
                arr[santa[k].r][santa[k].c] = k;
            }
            
        }
    }
}

int main() {
    int N, M, P, C, D;
    int Rr, Rc; // 루돌프의 초기위치
    Santa santa[31];
    int arr[51][51] = {0, }; // 게임판

    scanf("%d %d %d %d %d", &N, &M, &P, &C, &D);
    scanf("%d %d", &Rr, &Rc);

    int i, j, k;
    int number;

    for (i=0;i<P;i++)
    {
        scanf("%d", &number);
        scanf("%d %d", &santa[number].r, &santa[number].c);

        santa[number].score = 0;
        santa[number].status = 0;
        arr[santa[number].r][santa[number].c] = number;
    }

    for (k=0;k<M;k++)
    {
        moveRudolf(santa, arr, N, P, C, &Rr, &Rc);

        // printf("%d turn\n", k+1);
        // printf("루돌프 이동 %d %d\n", Rr, Rc);
        // for (i=1;i<=N;i++)
        // {
        //     for (j=1;j<=N;j++)
        //     {
        //         printf("%2d", arr[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        moveSanta(santa, arr, N, P, Rr, Rc, D);

        // printf("산타 이동 %d %d\n", Rr, Rc);
        // for (i=1;i<=N;i++)
        // {
        //     for (j=1;j<=N;j++)
        //     {
        //         printf("%2d", arr[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");


        for (i=1;i<=P;i++)
        {
            if (santa[i].r >= 1 && santa[i].r <= N && santa[i].c >= 1 && santa[i].c <= N)
            {
                santa[i].score += 1;
            }
        }
    }

    for (i=1;i<=P;i++)
    {
        printf("%d ", santa[i].score);
    }

    return 0;
}
