#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int n, m;
static vector<vector<int>> arr; // 격자

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    arr = vector<vector<int>>(n, vector<int>(n));

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }

    int score = 0;
    int start_x = 0, start_y = 1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int u = 4, f = 2, r = 1;
    int next_f, next_u, next_r;
    int direction = 0; // 0: 우 1: 하 2: 좌 3: 상 (시계방향)

    for (int time=0;time<m;time++)
    {
        //cout << start_x << " " << start_y << " " << 7-u << "\n";

        // 점수 획득 과정
        queue<pair<int, int>> myQueue;
        vector<vector<int>> visited(n, vector<int>(n, false));

        myQueue.push({start_x, start_y});
        visited[start_x][start_y] = true;

        int cnt = 1;

        while (!myQueue.empty())
        {
            int cur_x = myQueue.front().first;
            int cur_y = myQueue.front().second;

            myQueue.pop();

            for (int i=0;i<4;i++)
            {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];

                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n)
                {
                    if (arr[start_x][start_y] == arr[next_x][next_y] && !visited[next_x][next_y])
                    {
                        myQueue.push({next_x, next_y});
                        visited[next_x][next_y] = true;
                        cnt++;
                    }
                }
            }
        }

        visited.clear();

        score += cnt*arr[start_x][start_y];

        // 주사위가 굴러갈 방향 정하기
        if (7-u > arr[start_x][start_y]) // 현재 진행방향에서 90도 시계방향으로 회전
        {
           direction++;

           if (direction == 4) direction = 0;
        }

        else if (7-u < arr[start_x][start_y]) // 현재 진행방향에서 90도 반시계방향으로 회전
        {
            direction--;

            if (direction == -1) direction = 3;
        }

        // 주사위 굴리기
        while (true)
        {
            if (direction == 0)
            {
                start_y += 1;

                if (start_y == n)
                {
                    direction = (direction+2)%4;

                    start_y -= 1;

                    continue;
                }

                next_u = 7-r;
                next_r = u;

                u = next_u;
                r = next_r;
            }

            else if (direction == 1)
            {
                start_x += 1;

                if (start_x == n)
                {
                    direction = (direction+2)%4;

                    start_x -= 1;

                    continue;
                }

                next_u = 7-f;
                next_f = u;

                u = next_u;
                f = next_f;
            }

            else if (direction == 2)
            {
                start_y -= 1;

                if (start_y < 0)
                {
                    direction = (direction+2)%4;

                    start_y += 1;

                    continue;
                }
                
                next_r = 7-u;
                next_u = r;

                r = next_r;
                u = next_u;
            }

            else if (direction == 3)
            {
                start_x -= 1;
                
                if (start_x < 0)
                {
                    direction = (direction+2)%4;

                    start_x += 1;

                    continue;
                }

                next_u = f;
                next_f = 7-u;

                u = next_u;
                f = next_f;
            }

            break;
        }
    }

    cout << score;

    return 0;
}
