#include <stdio.h>

typedef struct Queue
{
    int front, rear;
    int x[100000], y[100000];
}Queue;

typedef struct Person
{
    int r, c;
    int x, y;
    int status; // 베이스 캠프 이동 여부(0: 출발 전, 1: 출발) 및 편의점 도착 여부(2: 편의점 도착)
}Person;

void BFS(int arr[][16], int start_x, int start_y, int n)
{
    Queue que;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int cur_x, cur_y, next_x, next_y;

    que.front = que.rear = -1;

    que.x[++que.rear] = start_x;
    que.y[que.rear] = start_y;

    arr[start_x][start_y] = 10;

    int i;

    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];
        cur_y = que.y[que.front];

        for (i=0;i<4;i++)
        {
            next_x = cur_x+dx[i];
            next_y = cur_y+dy[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && (arr[next_x][next_y] == 0 || arr[next_x][next_y] == 1))
            {
                arr[next_x][next_y] = arr[cur_x][cur_y] + 1;
                
                que.x[++que.rear] = next_x;
                que.y[que.rear] = next_y;
            }
        }
    }
}

int main() {
    Person person[256];
    int n, m;

    scanf("%d %d", &n, &m);

    int i, j;
    int arr[16][16] = {0,}, arr_to_basecamp[16][16] = {0,}, arr_to_store[16][16] = {0,};

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int x, y;

    for (i=0;i<m;i++)
    {
        scanf("%d %d", &x, &y);

        // 초기화
        person[i].status = 0;
        person[i].x = x-1;
        person[i].y = y-1;
        person[i].r = person[i].c = -1;
    }

    int sec = 0;
    int s, t, k;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int cnt = 0;

    while (1)
    {
        sec++;

        for (i=0;i<m;i++)
        {
            if (person[i].status == 1)
            {
                for (s=0;s<n;s++)
                {
                    for (t=0;t<n;t++)
                    {
                        arr_to_store[s][t] = arr[s][t];
                    }
                }

                BFS(arr_to_store, person[i].x, person[i].y, n);

                int min = 987654321;
                int min_x, min_y;
                int next_x, next_y;
                for (k=0;k<4;k++)
                {
                    next_x = person[i].r+dx[k];
                    next_y = person[i].c+dy[k];
                    if (arr_to_store[next_x][next_y] < min && next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && arr_to_store[next_x][next_y] > 2)
                    {
                        min = arr_to_store[next_x][next_y];
                        min_x = next_x;
                        min_y = next_y;
                    }
                }

                person[i].r = min_x;
                person[i].c = min_y;

                if (person[i].r == person[i].x && person[i].c == person[i].y)
                {
                    person[i].status = 2;
                    cnt++;
                }
            }
        }

        for (i=0;i<m;i++)
        {
            if (person[i].status == 2 && arr[person[i].x][person[i].y] != 2)
            {
                arr[person[i].x][person[i].y] = 2;
            }
        }

        if (cnt == m) break;

        //
        if (sec <= m)
        {
            for (i=0;i<sec;i++)
            {
                if (person[i].status == 0)
                {
                    for (s=0;s<n;s++)
                    {
                        for (t=0;t<n;t++)
                        {
                            arr_to_basecamp[s][t] = arr[s][t];
                        }
                    }

                    BFS(arr_to_basecamp, person[i].x, person[i].y, n);

                    int min = 987654321;
                    for (s=0;s<n;s++)
                    {
                        for (t=0;t<n;t++)
                        {
                            if (arr[s][t] == 1 && arr_to_basecamp[s][t] < min && arr_to_basecamp[s][t] > 2)
                            {
                                min = arr_to_basecamp[s][t];
                                person[i].r = s;
                                person[i].c = t;
                            }
                        }
                    }

                    person[i].status = 1;
                    arr[person[i].r][person[i].c] = 2;
                }
            }
        }
    }

    printf("%d", sec);

    return 0;
}
