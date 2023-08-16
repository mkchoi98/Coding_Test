#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// DFS ver
/*void DFS(int adj[][101], int visited[], int now, int end, int *cnt, int n, int *answer)
{
	int i;

	if (now == end)
	{
		*answer = *cnt;
		return;
	}

	visited[now] = 1;

	for (i = 1; i <= n; i++)
	{
		if (adj[now][i] == 1 && visited[i] != 1)
		{
			(*cnt)++;
			
			DFS(adj, visited, i, end, cnt, n, answer);
		}
	}
	(*cnt)--;
}

int main()
{
	int n;
	int num1, num2;
	int m;
	int x, y;
	int i;

	int adj[101][101] = {0, };
	int visited[101] = {0};

	int cnt = 0;
	int answer = 0;

	scanf("%d", &n);
	scanf("%d %d", &num1, &num2);
	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	DFS(adj, visited, num1, num2, &cnt, n, &answer);

	if (cnt != -1) printf("%d", answer);
	else printf("-1");

	return 0;
}*/

// BFS ver
typedef struct Queue
{
	int front, rear;
	int data[101];
}Queue;

void BFS(int adj[][101], int *discovered, int n, int start, int end)
{
	Queue que;
	int index;
	
	int i;

	que.front = que.rear = -1;

	discovered[start] = 1;
	que.data[++que.rear] = start;

	while (que.front < que.rear)
	{
		index = que.data[++que.front];

		if (index == end) break;

		for (i = 1; i <= n; i++)
		{
			if (discovered[i] == 0 && adj[index][i] != 0)
			{
				que.data[++que.rear] = i;
				discovered[i] = 1;

				discovered[i] = discovered[index] + 1;
			}
		}
	}
}

int main()
{
	int n;
	int a, b;
	int m;

	int i, j;
	
	int adj[101][101] = {0,};
	int discovered[101] = {0,};
	int x, y;

	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);

		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	BFS(adj, discovered, n, a, b);

	printf("%d", discovered[b] -1);

	return 0;
}
