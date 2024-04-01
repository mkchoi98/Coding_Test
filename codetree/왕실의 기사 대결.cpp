#include <iostream>
#include <vector>
#include <queue>

#define MAX_L 41
#define MAX_N 30

using namespace std;

typedef struct Knight
{
    int r, c, h, w, k;
    bool status;
    int damage;
}Knight;

static int L, N, Q;
static int arr[MAX_L][MAX_L];
static Knight knight[MAX_N];
static int knightArr[MAX_L][MAX_L];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void moveKnight(int i, int d);
void getDamage(int i);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> L >> N >> Q;

    for (int i=1;i<=L;i++)
    {
        for (int j=1;j<=L;j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i=1;i<=N;i++)
    {
        cin >> knight[i].r >> knight[i].c >> knight[i].h >> knight[i].w >> knight[i].k;
        knight[i].status = true;
        knight[i].damage = 0;

        for (int s=knight[i].r;s<=knight[i].r+knight[i].h-1;s++)
        {
            for (int t=knight[i].c;t<=knight[i].c+knight[i].w-1;t++)
            {
                knightArr[s][t] = i;
            }
        }
    }

    while (Q--)
    {
        int i, d;

        cin >> i >> d;

        // 기사 이동
        if (!knight[i].status) continue ;

        moveKnight(i ,d);

        for (int s=1;s<=L;s++)
        {
            for (int t=1;t<=L;t++)
            {
                knightArr[s][t] = 0; // 초기화
            }
        }

        for (int num=1;num<=N;num++)
        {   
            if (!knight[num].status) continue;

            for (int s=knight[num].r;s<=knight[num].r+knight[num].h-1;s++)
            {
                for (int t=knight[num].c;t<=knight[num].c+knight[num].w-1;t++)
                {
                    knightArr[s][t] = num;
                }
            }
        }
    }

    int answer = 0;

    for (int num=1;num<=N;num++)
    {
        if (knight[num].status) 
        {
            answer += knight[num].damage;
        }
    }

    cout << answer;

    return 0;
}

void moveKnight(int i, int d)
{
    queue<int> myQueue, myQueue2;
    int nx = knight[i].r + dx[d];
    int ny = knight[i].c + dy[d];
    bool flag = false;
    vector<bool> isCheck(N+1, false);

    if (nx >= 1 && nx+knight[i].h-1 <= L && ny >= 1 && ny+knight[i].w-1 <= L)
    {
        for (int s=nx;s<=nx+knight[i].h-1;s++)
        {
            for (int t=ny;t<=ny+knight[i].w-1;t++)
            {
                if (arr[s][t] == 2) // 기사가 이동할 곳에 벽이 있는 경우
                {
                    return ; // 아무 일도 일어나지 않음
                }

                if (knightArr[s][t] != 0 && knightArr[s][t] != i)
                {
                    myQueue.push(i);
                    myQueue2.push(i);

                    isCheck[i] = true;

                    flag = true;

                    break;
                }
            }
            
            if (flag)
            {
                break;
            }
        }

        if (!flag) // 기사가 이동할 곳에 아무 것도 없을 경우
        {
            knight[i].r = nx; // 기사의 위치 변경
            knight[i].c = ny;

            return ;
        }
    }

    else return ;

    while (!myQueue.empty())
    {
        int num = myQueue.front();
        
        nx = knight[num].r + dx[d];
        ny = knight[num].c + dy[d];

        if (!(nx >= 1 && nx+knight[num].h-1 <= L && ny >= 1 && ny+knight[num].w-1 <= L))
        {
            return ;
        }

        myQueue.pop();

        int s, t;

        for (s=nx;s<=nx+knight[num].h-1;s++)
        {
            for (t=ny;t<=ny+knight[num].w-1;t++)
            {
                if (arr[s][t] == 2) // 기사가 이동할 곳에 벽이 있는 경우
                {
                    return ; // 아무 일도 일어나지 않음
                }

                if (knightArr[s][t] != 0 && !isCheck[knightArr[s][t]])
                {
                    myQueue.push(knightArr[s][t]);
                    myQueue2.push(knightArr[s][t]);

                    isCheck[knightArr[s][t]] = true;
                }
            }
        }
    }

    while (!myQueue2.empty()) // 기사들의 이동
    {
        int num = myQueue2.front();

        myQueue2.pop();

        knight[num].r += dx[d];
        knight[num].c += dy[d];

        if (num == i) continue;

        getDamage(num);
    }
}

void getDamage(int num)
{
    int cnt = 0;

    for (int s=knight[num].r;s<=knight[num].r+knight[num].h-1;s++)
    {
        for (int t=knight[num].c;t<=knight[num].c+knight[num].w-1;t++)
        {
            if (arr[s][t] == 1)
            {
               cnt++;
            }
        }
    }

    knight[num].k -= cnt;
    knight[num].damage += cnt;

    if (knight[num].k <= 0)
    {
        knight[num].r = -1;
        knight[num].c = -1;
        knight[num].status = false;
    }
}
