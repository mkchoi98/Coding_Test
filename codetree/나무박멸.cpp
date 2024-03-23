#include <iostream>

#define MAX_N 20
#define MAX_M 1000

using namespace std;

static int n, m, k, c;
static int arr[MAX_M][MAX_N][MAX_N];
static int herbicide[MAX_N][MAX_N];
static long answer;

int cur_m = 1;

void growTree();
void breedTree();
void spraying();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> c;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> arr[0][i][j];
        }
    }

    while (cur_m <= m)
    {
        // 나무의 성장
        growTree();

        // 나무의 번식
        breedTree();

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                arr[cur_m][i][j] += arr[cur_m-1][i][j];
            }
        }

        // 제초제 뿌리기
        spraying();

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (herbicide[i][j] > 0)
                {
                    herbicide[i][j]--;
                }
            }
        }

        cur_m++;
    }

    cout << answer;

    return 0;
}

void growTree()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr[cur_m-1][i][j] > 0) // 0: 빈칸 -1: 벽
            {
                int cnt = 0; // 나무가 있는 인접한 칸 세기
                for (int d=0;d<4;d++)
                {
                    int next_x = i+dx[d];
                    int next_y = j+dy[d];

                    if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && arr[cur_m-1][next_x][next_y] > 0 && herbicide[next_x][next_y] == 0)
                    {
                        cnt++;
                    }
                }

                arr[cur_m-1][i][j] += cnt;
            }
        }
    }
}

void breedTree()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int cnt = 0;

            if (arr[cur_m-1][i][j] > 0)
            {
                for (int d=0;d<4;d++)
                {
                    int next_x = i+dx[d];
                    int next_y = j+dy[d];

                    if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && arr[cur_m-1][next_x][next_y] == 0 && herbicide[next_x][next_y] == 0)
                    {
                        cnt++;
                    }
                }

                if (cnt != 0)
                {
                    for (int d=0;d<4;d++)
                    {
                        int next_x = i+dx[d];
                        int next_y = j+dy[d];

                        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && arr[cur_m-1][next_x][next_y] == 0 && herbicide[next_x][next_y] == 0)
                        {
                            arr[cur_m][next_x][next_y] += arr[cur_m-1][i][j] / cnt;
                        }
                    }
                }
            }
        }
    }
}

void spraying()
{
    int max = 0, max_x = -1, max_y = -1;
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr[cur_m][i][j] > 0)
            {
                int tree = 0;
                
                tree += arr[cur_m][i][j];

                for (int d=0;d<4;d++)
                {
                    int cnt_k = 0;
                    int cur_x = i, cur_y = j;
                    int next_x, next_y;

                    while (cnt_k < k)
                    {
                        next_x = cur_x + dx[d];
                        next_y = cur_y + dy[d];

                        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                        {
                            break;
                        }

                        if (arr[cur_m][next_x][next_y] == 0 || arr[cur_m][next_x][next_y] == -1)
                        {
                            break;
                        }

                        tree += arr[cur_m][next_x][next_y];

                        cur_x = next_x;
                        cur_y = next_y;

                        cnt_k++;
                    }
                }

                if (max < tree)
                {
                    max = tree;
                    max_x = i;
                    max_y = j;
                }
            }
        }
    }

    if (max_x == -1 && max_y == -1) return ;

    arr[cur_m][max_x][max_y] = 0;
    herbicide[max_x][max_y] = c+1;

    for (int d=0;d<4;d++)
    {
        int cnt_k = 0;
        int cur_x = max_x, cur_y = max_y;
        int next_x, next_y;

        while (cnt_k < k)
        {
            next_x = cur_x + dx[d];
            next_y = cur_y + dy[d];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
            {
                break;
            }

            if (arr[cur_m][next_x][next_y] == 0 || arr[cur_m][next_x][next_y] == -1)
            {
                herbicide[next_x][next_y] = c+1;

                break;
            }

            arr[cur_m][next_x][next_y] = 0;
            herbicide[next_x][next_y] = c+1;

            cur_x = next_x;
            cur_y = next_y;

            cnt_k++;
        }
    }

    answer += max;
}
