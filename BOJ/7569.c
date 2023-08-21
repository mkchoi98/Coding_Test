#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
	int front, rear;
	int x[1000000], y[1000000], z[1000000];
}Queue;

void BFS(Queue que, int adj[][101][101], int m, int n, int h)
{

	int cur_x, cur_y, cur_z;
	int next_x, next_y, next_z;

	int dir_x[6] = { -1, 1, 0, 0, 0, 0 };
	int dir_y[6] = { 0, 0, -1, 1, 0, 0 };
	int dir_z[6] = { 0, 0, 0, 0, -1, 1 };

	int i;

	while (que.front < que.rear)
	{
		cur_x = que.x[++que.front];
		cur_y = que.y[que.front];
		cur_z = que.z[que.front];

		for (i = 0; i < 6; i++)
		{
			next_x = cur_x + dir_x[i];
			next_y = cur_y + dir_y[i];
			next_z = cur_z + dir_z[i];

			if (next_x < n && next_x >= 0 && next_y < m && next_y >= 0 && next_z < h && next_z >= 0 && adj[next_z][next_x][next_y] == 0)
			{
				adj[next_z][next_x][next_y] = adj[cur_z][cur_x][cur_y] + 1;

				que.x[++que.rear] = next_x;
				que.y[que.rear] = next_y;
				que.z[que.rear] = next_z;
			}
		}
	}
}

int main()
{
	int m, n, h;
	int i, j, k;

	int adj[101][101][101] = { 0, };

	Queue que;

	que.front = que.rear = -1;

	scanf("%d %d %d", &m, &n, &h);

	for (k = 0; k < h; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &adj[k][i][j]);
			}
		}
	}

	for (k = 0; k < h; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (adj[k][i][j] == 1)
				{
					que.x[++que.rear] = i;
					que.y[que.rear] = j;
					que.z[que.rear] = k;
				}
			}
		}
	}

	BFS(que, adj, m, n, h);

	int max = 0;

	for (k = 0; k < h; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (adj[k][i][j] == 0)
				{
					printf("-1");

					return 0;
				}

				if (adj[k][i][j] > max)
					max = adj[k][i][j];
			}
		}
	}

	printf("%d", max - 1);

	return 0;
}
