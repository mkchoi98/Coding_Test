#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_N 51
#define MAX_P 31

using namespace std;

static int N, M, P, C, D;
static int Rr, Rc; // 루돌프의 위치
static vector<pair<int, int>> santa;
static int answer[MAX_P];
static int santa_status[MAX_P]; // 1: 생존
static int santa_arr[MAX_N][MAX_N];

int rudolf_dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int rudolf_dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int santa_dx[4] = {-1, 0, 1, 0};
int santa_dy[4] = {0, 1, 0, -1};

int calDistance(int x1, int x2, int y1, int y2);
void moveRudolf();
void moveSanta();
bool isCrash(int num);
void moveCrash(int num, int d, int, bool);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> P >> C >> D;

    santa.resize(P+1);

    cin >> Rr >> Rc;

    for (int i=0;i<P;i++)
    {
        int num, Sr, Sc;

        cin >> num >> Sr >> Sc;

        santa[num].first = Sr;
        santa[num].second = Sc;

        santa_arr[Sr][Sc] = num;
        santa_status[num] = 1;
    }

    while (M--)
    {
        bool stop_flag = true;

        moveRudolf();

        moveSanta();

        for (int i=1;i<=P;i++)
        {
            if (santa[i].first != -1 && santa[i].second != -1)
            {
                answer[i] += 1;
                stop_flag = false;

                if (santa_status[i] > 1)
                {
                    santa_status[i]--;
                }
            }
        }

        if (stop_flag)
        {
            break;
        }
    }

    for (int i=1;i<=P;i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}

int calDistance(int x1, int y1, int x2, int y2)
{
    int dis = pow(x1-x2, 2) + pow(y1-y2, 2);

    return dis;
}

void moveRudolf()
{
    int min = 987654321;
    int min_num; // 가장 가까운 산타
    int dis;

    for (int i=1;i<=P;i++)
    {
        if (santa[i].first == -1 && santa[i].second == -1) continue;

        dis = calDistance(Rr, Rc, santa[i].first, santa[i].second);

        if (dis < min)
        {
            min = dis;
            min_num = i;
        }

        else if (dis == min)
        {
            if (santa[min_num].first < santa[i].first)
            {
                min_num = i;
            }

            else if (santa[min_num].first == santa[i].first)
            {
                if (santa[min_num].second < santa[i].second)
                {
                    min_num = i;
                }
            }
        }
    }

    int min_index;
    int nx, ny;

    min = 987654321;

    for (int i=0;i<8;i++)
    {
        nx = Rr+rudolf_dx[i];
        ny = Rc+rudolf_dy[i];

        dis = calDistance(santa[min_num].first, santa[min_num].second, nx, ny);

        if (dis < min)
        {
            min_index = i;
            min = dis;
        }
    }

    Rr = Rr + rudolf_dx[min_index];
    Rc = Rc + rudolf_dy[min_index];

    for (int i=1;i<=P;i++)
    {
        int x = santa[i].first;
        int y = santa[i].second;

        if (isCrash(i))
        {
            answer[i] += C;

            // 충돌 후 이동
            santa_status[i] = 3;
            santa_arr[x][y] = 0;

            moveCrash(i, min_index, C, false); // 충돌한 산타와 루돌프의 방향

            if (santa[i].first != -1 && santa[i].second != -1) santa_arr[santa[i].first][santa[i].second] = i;

            break;
        }
    }
}

void moveSanta()
{
    for (int num=1;num<=P;num++)
    {
        if (santa_status[num] > 1 || (santa[num].first == -1 && santa[num].second == -1)) continue;
        
        int x = santa[num].first;
        int y = santa[num].second;
        int cur_dis = calDistance(x, y, Rr, Rc);

        int min = 987654321;
        int min_index = -1;

        for (int i=0;i<4;i++)
        {
            int nx = x+santa_dx[i];
            int ny = y+santa_dy[i];

            if (nx >= 1 && nx <= N && ny >= 0 && ny <= N && santa_arr[nx][ny] == 0)
            {
                int dis = calDistance(Rr, Rc, nx, ny);

                if (cur_dis > dis && dis < min)
                {
                    min = dis;
                    min_index = i;
                }
            }
        }
        
        if (min_index == -1) continue;

        santa[num].first += santa_dx[min_index];
        santa[num].second += santa_dy[min_index];

        santa_arr[x][y] = 0;

        if (isCrash(num))
        {
            answer[num] += D;
            
            // 충돌 후 이동
            santa_status[num] = 3;
            
            moveCrash(num, (min_index+2)%4, D, true);

            if (santa[num].first != -1 && santa[num].second != -1) santa_arr[santa[num].first][santa[num].second] = num;
        }

        else
        {
            santa_arr[santa[num].first][santa[num].second] = num;
        }
    }
}

bool isCrash(int num)
{
    if (Rr == santa[num].first && Rc == santa[num].second)
    {
        return true;
    }

    return false;
}

void moveCrash(int num, int d, int size, bool is_santa)
{
    int x = santa[num].first;
    int y = santa[num].second;
    int nx = x, ny = y;

    for (int i=0;i<size;i++)
    {
        if (!is_santa)
        {
            nx = nx + rudolf_dx[d];
            ny = ny + rudolf_dy[d];
        }

        else
        {
            nx = nx + santa_dx[d];
            ny = ny + santa_dy[d];
        }
    }

    if (!(nx >= 1 && nx <= N && ny >= 1 && ny <= N)) // 격자 밖을 넘어가면
    {
        santa[num].first = -1;
        santa[num].second = -1;
    
        return ;
    }
    
    else if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && santa_arr[nx][ny] == 0) // 이동한 자리에 다른 산타가 없으면
    {
        santa[num].first = nx;
        santa[num].second = ny;

        return ;
    }

    queue<pair<int, int>> que;
    int temp;

    // 상호 작용
    while (santa_arr[nx][ny] != 0)
    {
        que.push({nx, ny});

        if (!is_santa)
        {
            nx = nx + rudolf_dx[d];
            ny = ny + rudolf_dy[d];
        }

        else
        {
            nx = nx + santa_dx[d];
            ny = ny + santa_dy[d];
        }

        if (!(nx >= 1 && nx <= N && ny >= 1 && ny <= N))
        {
            break;
        }
    }

    while (!que.empty())
    {
        int front_x = que.front().first;
        int front_y = que.front().second;

        que.pop();

        temp = santa_arr[front_x][front_y];

        santa_arr[front_x][front_y] = num;
        santa[num].first = front_x;
        santa[num].second = front_y;
        
        num = temp;
    }

    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
    {
        santa_arr[nx][ny] = num;
        santa[num].first = nx;
        santa[num].second = ny;
    }
   
    else
    {
        santa[num].first = -1;
        santa[num].second = -1;
    }
}
