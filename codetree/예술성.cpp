#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 29

using namespace std;

static int n;
static int arr[MAX_N][MAX_N];
static vector<vector<int>> group_arr;
static vector<int> group_num;
static vector<int> group_member_cnt;
static int answer;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void makeGroup(vector<vector<bool>> &visited, int x, int y, int group_num);
void adjGroup(int group1, int group2, int x, int y, int *cnt);
void rotateSqure(int row_start, int row_end, int col_start, int col_end);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int turn=0;turn<=3;turn++)
    {
        group_arr = vector<vector<int>> (MAX_N, vector<int>(MAX_N, 0));
        group_num = vector<int> (MAX_N*MAX_N+1, 0);
        group_member_cnt = vector<int> (MAX_N*MAX_N+1, 0);

        // 그룹 만들기
        int group_cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (!visited[i][j])
                {
                    makeGroup(visited, i, j, group_cnt);

                    group_cnt++;
                }
            }
        }

        visited.clear();

        // 예술 점수 구하기
        int art_score = 0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int d=0;d<4;d++)
                {
                    int adj_x = i+dx[d];
                    int adj_y = j+dy[d];

                    if (adj_x >= 0 && adj_x < n && adj_y >= 0 && adj_y < n && arr[i][j] != arr[adj_x][adj_y])
                    {
                        int g1 = group_arr[i][j];
                        int g2 = group_arr[adj_x][adj_y];

                        art_score += (group_member_cnt[g1]+group_member_cnt[g2])*group_num[g1]*group_num[g2];
                    }
                }
            }
        }

        art_score /= 2;

        answer += art_score;

        group_arr.clear();
        group_num.clear();
        group_member_cnt.clear();

        // 그림 정중앙 회전하기
        vector<int> temp1(n/2);
        vector<int> temp2(n/2);

        // 1
        for (int i=0;i<n/2;i++)
        {
            temp1[i] = arr[n/2][i];
        }

        for (int i=0;i<n/2;i++)
        {
            arr[n/2][i] = arr[i][n/2];
        }

        // 2
        for (int i=0;i<n/2;i++)
        {
            temp2[i] = arr[n-1-i][n/2];
        }

        for (int i=0;i<n/2;i++)
        {
            arr[n-1-i][n/2] = temp1[i];
        }

        // 3
        for (int i=0;i<n/2;i++)
        {
            temp1[i] = arr[n/2][n-1-i];
        }

        for (int i=0;i<n/2;i++)
        {
            arr[n/2][n-1-i] = temp2[i];
        }

        // 4
        for (int i=0;i<n/2;i++)
        {
            arr[i][n/2] = temp1[i];
        }

        temp1.clear();
        temp2.clear();

        // 4개의 정사각형 회전
        rotateSqure(0, n/2-1, 0, n/2-1);
        rotateSqure(n/2+1, n-1, 0, n/2-1);
        rotateSqure(0, n/2-1, n/2+1, n-1);
        rotateSqure(n/2+1, n-1, n/2+1, n-1);
    }

    cout << answer;

    return 0;
}

void makeGroup(vector<vector<bool>> &visited, int x, int y, int group_cnt) // BFS 활용
{
    queue<pair<int, int>> myQueue;

    myQueue.push({x, y});
    visited[x][y] = true;
    group_arr[x][y] = group_cnt;

    group_num[group_cnt] = arr[x][y];
    group_member_cnt[group_cnt]++;

    while (!myQueue.empty())
    {
        int cur_x = myQueue.front().first;
        int cur_y = myQueue.front().second;

        myQueue.pop();

        for (int i=0;i<4;i++)
        {
            int next_x = cur_x+dx[i];
            int next_y = cur_y+dy[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visited[next_x][next_y] && arr[x][y] == arr[next_x][next_y])
            {
                group_arr[next_x][next_y] = group_cnt;
                group_member_cnt[group_cnt]++;

                visited[next_x][next_y] = true;
                myQueue.push({next_x, next_y});
            }
        }
    }
}

void rotateSqure(int row_start, int row_end, int col_start, int col_end)
{
    int size = 0;

    while((row_start < row_end) && (col_start < col_end))
    {
        size = row_end - row_start + 1;
        vector<int> temp1(size);
        vector<int> temp2(size);
        
        // 1
        for (int i=col_end, j=0;i>=col_start+1, j<size-1;i--, j++)
        {
            temp1[j] = arr[row_start][i]; 
        }

        for (int i=col_end, j=row_start;i>=col_start, j<=row_end;i--, j++)
        {
            arr[row_start][i] = arr[j][col_start];
        }

        // 2
        for (int i=row_end, j=0;i>=row_start+1, j<size-1;i--, j++)
        {
            temp2[j] = arr[i][col_end]; 
        }

        for (int i=row_end, j=0;i>=row_start+1, j<size-1;i--, j++)
        {
            arr[i][col_end] = temp1[j];
        }

        // 3
        for (int i=col_start, j=0;i<=col_end-1, j<size-1;i++, j++)
        {
            temp1[j] = arr[row_end][i];
        }

        for (int i=col_start, j=0;i<=col_end-1, j<size-1;i++, j++)
        {
            arr[row_end][i] = temp2[j];
        }

        // 4
        for (int i=row_start+1, j=1;i<=row_end, j<size-1;i++, j++)
        {
            arr[i][col_start] = temp1[j];
        }

        row_start++;
        col_start++;
        row_end--;
        col_end--;
    }
}
