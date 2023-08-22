#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
	long long front, rear;
	long long x[1000001];
}Queue;

void BFS(long long discovered[], long long f, long long s, long long g, long long u, long long d)
{
	Queue que;
	
	long cur_x;

	que.front = que.rear = -1;

	discovered[s] = 1;

	que.x[++que.rear] = s;

	while (que.front < que.rear)
	{
		cur_x = que.x[++que.front];

		if (cur_x + u <= f && discovered[cur_x + u] == 0)
		{
			que.x[++que.rear] = cur_x + u;

			discovered[cur_x + u] = discovered[cur_x] + 1;
		}

		if (cur_x - d >= 1 && discovered[cur_x - d] == 0)
		{
			que.x[++que.rear] = cur_x - d;

			discovered[cur_x - d] = discovered[cur_x] + 1;
		}
	}
}

int main()
{
	long long f, s, g, u, d;

	long long discovered[1000001] = { 0, };

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	BFS(discovered, f, s, g, u, d);

	if (discovered[g] == 0)
	{
		printf("use the stairs");

		return 0;
	}

	printf("%lld", discovered[g] - 1);

	return 0;
}
