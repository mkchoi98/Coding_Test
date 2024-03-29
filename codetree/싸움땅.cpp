#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 21

using namespace std;

typedef struct playerInfo
{
    int x, y, d, s;
    int gun_power;
    int point;
}playerInfo;

static int n, m, k;
static vector<vector<vector<int>>> gun_info(MAX_N, vector<vector<int>>(MAX_N, vector<int> (MAX_N*MAX_N)));
static int gun_cnt[MAX_N][MAX_N];
static playerInfo player[MAX_N*MAX_N];
static int player_arr[MAX_N][MAX_N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void movePlayer(int num); // player[i]의 x, y 변경
void getGun(int num); // 플레이어의 번호
void throwGun(int num); // 플레이어의 번호
int fight(int num1, int num2); // 현재 이동 중인 플레이어의 번호, 해당 좌표에 있는 플레이어의 번호
void moveLosePlayer(int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            int g;

            cin >> g;

            if (g > 0)
            {
                gun_info[i][j][gun_cnt[i][j]] = g;
                gun_cnt[i][j]++;
            }
        }
    }

    for (int i=1;i<=m;i++)
    {
        int x, y, d, s;

        cin >> x >> y >> d >> s;

        player[i].x = x;
        player[i].y = y;
        player[i].d = d;
        player[i].s = s;
        player[i].gun_power = 0;
        player[i].point = 0;

        player_arr[x][y] = i;
    }

    
    while (k--)
    {
        for (int i=1;i<=m;i++)
        {
            // 1. 플레이어의 이동

            // 이동 전 플레이어 위치
            int cur_x = player[i].x;
            int cur_y = player[i].y;

            movePlayer(i);

            // 이동 후 플레이어 위치
            int next_x = player[i].x;
            int next_y = player[i].y;

            if (player_arr[next_x][next_y] == 0) // 플레이어가 없는 경우
            {
                player_arr[cur_x][cur_y] = 0;
                player_arr[next_x][next_y] = i;

                if (gun_cnt[next_x][next_y] > 0) // 총이 있는 경우
                {
                    getGun(i);
                }
            }

            else
            {
                player_arr[cur_x][cur_y] = 0;

                int fight_num = player_arr[next_x][next_y];
                int winner = fight(i, fight_num);

                if (winner == i) // 현재 플레이어가 이긴 경우
                {
                    // 진 플레이어는 총을 버림
                    if (player[fight_num].gun_power > 0) throwGun(fight_num);
                    
                    moveLosePlayer(fight_num);
                    
                    player_arr[next_x][next_y] = i;

                    if (gun_cnt[next_x][next_y] > 0) // 총이 있는 경우
                    {
                        getGun(i);
                    }
                }

                else // 현재 플레이어가 진 경우
                {
                    // 진 플레이어는 총을 버림
                    if (player[i].gun_power > 0) throwGun(i);
                    
                    moveLosePlayer(i);

                    if (gun_cnt[next_x][next_y] > 0) // 총이 있는 경우
                    {
                        getGun(fight_num);
                    }
                }

            }
        }
    }

    for (int i=1;i<=m;i++)
    {
        cout << player[i].point << " ";
    }

    return 0;
}

void movePlayer(int num) // player[i]의 x, y 변경
{
    int d = player[num].d;
    int nx = player[num].x + dx[d];
    int ny = player[num].y + dy[d];

    if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= n))
    {
        d = (d+2)%4;

        nx = player[num].x + dx[d];
        ny = player[num].y + dy[d];
    }

    player[num].x = nx;
    player[num].y = ny;
    player[num].d = d;
}

void getGun(int num) // 플레이어의 번호
{
    int x = player[num].x;
    int y = player[num].y;
    int max = gun_info[x][y][gun_cnt[x][y]-1];

    if (player[num].gun_power > 0)
    {
        if (player[num].gun_power < max)
        {
            throwGun(num);
        }

        else return; // 갖고 있는 총의 공격력이 더 높은 경우, 총을 줍지 않고 return
    }

    player[num].gun_power = max;

    gun_info[x][y][gun_cnt[x][y]-1] = 0;
    gun_cnt[x][y]--;
}

void throwGun(int num) // 플레이어의 번호
{
    int x = player[num].x;
    int y = player[num].y;

    gun_info[x][y][gun_cnt[x][y]] = player[num].gun_power;
    player[num].gun_power = 0;

    gun_cnt[x][y]++;

    for (int i=0;i<gun_cnt[x][y]-1;i++)
    {
        for (int j=i+1;j<gun_cnt[x][y];j++)
        {
            if (gun_info[x][y][i] > gun_info[x][y][j])
            {
                int temp = gun_info[x][y][i];
                gun_info[x][y][i] = gun_info[x][y][j];
                gun_info[x][y][j] = temp;
            }
        }
    }
}

int fight(int num1, int num2) // 현재 이동 중인 플레이어의 번호, 해당 좌표에 있는 플레이어의 번호
{
    int sum1 = player[num1].s + player[num1].gun_power;
    int sum2 = player[num2].s + player[num2].gun_power;
    int score = abs((player[num1].s + player[num1].gun_power) - (player[num2].s + player[num2].gun_power));

    if (sum1 > sum2)
    {
        player[num1].point += score;

        return num1;
    }

    else if (sum1 < sum2)
    {
        player[num2].point += score;

        return num2;
    }

    else
    {
        if (player[num1].s > player[num2].s)
        {
            player[num1].point += score;

            return num1;
        }

        else
        {
            player[num2].point += score;

            return num2;
        }
    }
}

void moveLosePlayer(int num) // 진 플레이어의 번호
{
    int d = player[num].d;
    int nx = player[num].x + dx[d];
    int ny = player[num].y + dy[d];

    while (!(nx > 0 && nx <= n && ny > 0 && ny <= n && player_arr[nx][ny] == 0))
    {
        d = (d+1)%4;

        nx = player[num].x + dx[d];
        ny = player[num].y + dy[d];
    }

    player[num].d = d;
    player[num].x = nx;
    player[num].y = ny;

    player_arr[nx][ny] = num;

    if (gun_cnt[nx][ny] > 0) // 총이 있는 경우
    {
        getGun(num);
    }
}
