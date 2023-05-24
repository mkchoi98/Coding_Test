#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void DFS(int adj[][101], int visited[], int now, int end, int *cnt, int n, int *answer)
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
}
