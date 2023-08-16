#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void DFS(int adj[][101], int* visited, int n, int start, int *cnt)
{
	int i;

	visited[start] = 1;
	//printf("%d ", start);
	(*cnt)++;
	for (i = 1; i <= n; i++)
	{
		if (visited[i] == 0 && adj[start][i] == 1)
		{
			DFS(adj, visited, n, i, cnt);
		}
	}
}

int main()
{
	int n, m;
	int i;

	int adj[101][101] = { 0, };
	int x, y;
	int visited[101] = { 0, };

	int cnt = 0;
	
	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);

		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	DFS(adj, visited, n, 1, &cnt);

	printf("%d", cnt-1);
}
