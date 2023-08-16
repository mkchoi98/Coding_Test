#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
	int front, rear;
	int data[1001];
}Queue;

void DFS(int adj[][1001], int* visited, int N, int start)
{
	int i;

	visited[start] = 1;
	printf("%d ", start);

	for (i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && adj[start][i] == 1)
		{
			DFS(adj, visited, N, i);
		}
	}
}

void BFS(int adj[][1001], int* discovered, int N, int start)
{
	Queue que;
	int i;
	int index;

	que.front = que.rear = -1;

	que.data[++que.rear] = start;
	discovered[start] = 1;

	while (que.front < que.rear)
	{
		index = que.data[++que.front];
		printf("%d ", index);

		for (i=1;i<=N;i++)
		{
			if (discovered[i] == 0 && adj[index][i] == 1)
			{
				discovered[i] = 1;
				que.data[++que.rear] = i;
			}
		}
	}
}

int main()
{
	int N, M, V;
	int i;
	int x, y;

	int adj[1001][1001] = { 0, };
	int visited[1001] = { 0, };
	int discovered[1001] = { 0, };

	scanf("%d %d %d", &N, &M, &V);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);

		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	DFS(adj, &visited, N, V);
	printf("\n");
	BFS(adj, &discovered, N, V);

	return 0;
}
