#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
	int data[101];
	int front, rear;
}Queue;

void init(int* arr, int n)
{
	int i;

	for (i = 0; i <= n; i++)
		arr[i] = 0;
}

void BFS(int adj[][101], int discovered[101], int start, int end, int n, int *cnt)
{
	Queue que;
	int i, index;

	que.front = que.rear = -1;

	discovered[start] = 1;

	que.data[++que.rear] = start;

	while (que.front < que.rear)
	{
		index = que.data[++que.front];
		
		//if (adj[index][end])
			printf("%d ", index);

		for (i = 1; i <= n; i++)
		{
			if (adj[index][i] == 1 && discovered[i] != 1)
			{
				if (i == end) return;

				discovered[i] = 1;
				que.data[++que.rear] = i;
			}
		}
	}
}

int main()
{
	int n, m;
	int x, y;

	int adj[101][101] = { 0, };
	int discovered[101] = { 0 };

	int i, j;

	int min = 5000, cnt = 0, sub_cnt = 0, sum = 0;
	int answer;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	for (i = 1; i <= n; i++)
	{
		sum = 0;
		cnt = 0;
		sub_cnt = 0;
		
		for (j = 1; j <= n; j++)
		{
			if (i == j) continue;

			printf("strat: %d end: %d\n", i, j);

			init(discovered, n);

			BFS(adj, discovered, i, j, n, &cnt);
			
			printf("result : %d\n", cnt);
		}
		printf("\n");
		if (min > cnt)
		{
			min = cnt;
			answer = i;
		}
	}

	printf("%d", answer);

	return 0;
}
