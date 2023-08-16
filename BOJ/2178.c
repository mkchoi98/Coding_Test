#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
	int front, rear;
	int x[10000], y[10000];
}Queue;

void BFS(long adj[][101], int n, int m, int start_x, int start_y)
{
	Queue que;
	int x, y;

	int x_dir[4] = { 1, -1, 0, 0 };
	int y_dir[4] = { 0, 0, 1, -1 };
	int cur_x, cur_y;

	int i;

	que.front = que.rear = -1;

	que.x[++que.rear] = start_x;
	que.y[que.rear] = start_y;

	while (que.front < que.rear)
	{
		x = que.x[++que.front];
		y = que.y[que.front];

		for (i = 0; i < 4; i++)
		{
			cur_x = x + x_dir[i];
			cur_y = y + y_dir[i];
			if (cur_x < n && cur_x >= 0 && cur_y < m && cur_y >= 0 && adj[cur_x][cur_y] == 1)
			{
				que.x[++que.rear] = cur_x;
				que.y[que.rear] = cur_y;

				adj[cur_x][cur_y] = adj[x][y] + 1;
			}
		}
	}
}

int main()
{
	int n, m;

	int i, j;

	long adj[101][101] = { 0, };

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1ld", &adj[i][j]);
		}
	}

	BFS(adj, n, m, 0, 0);

	printf("%ld", adj[n - 1][m - 1]);

	return 0;
}
