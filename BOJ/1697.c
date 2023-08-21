#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int front, rear;
	int x[200000];
}Queue;

void BFS(int discovered[], int x, int k)
{
	Queue que;

	int cur_x;

	que.front = que.rear = -1;

	que.x[++que.rear] = x;

	discovered[x] = 1;

	while (que.front < que.rear)
	{
		cur_x = que.x[++que.front];

		if (cur_x == k) break;

		if (cur_x - 1 >= 0 && discovered[cur_x - 1] == 0)
		{
			que.x[++que.rear] = cur_x - 1;
			discovered[cur_x - 1] = discovered[cur_x] + 1;
		}

		if (cur_x + 1 <= k && discovered[cur_x + 1] == 0)
		{
			que.x[++que.rear] = cur_x + 1;
			discovered[cur_x + 1] = discovered[cur_x] + 1;
		}

		if (cur_x * 2 <= k+1 && discovered[cur_x * 2] == 0)
		{
			que.x[++que.rear] = cur_x * 2;
			discovered[cur_x * 2] = discovered[cur_x] + 1;
		}
	}
}

int main()
{
	int x, k;

	int discovered[200001] = { 0 ,};

	int i;

	scanf("%d %d", &x, &k);

	if (x == k)
	{
		printf("0");
		
		return 0;
	}

	BFS(discovered, x, k);

	printf("%d", discovered[k]-1);

	return 0;
}
