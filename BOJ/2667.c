//
//  main.c
//  2667
//
//  Created by 최민경 on 2023/06/12.
//

//DFS
/*#include <stdio.h>
#include <stdlib.h>

void DFS(int adj[][25], int n, int row, int col, int *arr, int cnt)
{
    adj[row][col] = 0;
    arr[cnt]++;
    
    //printf("%d %d\n", row, col);
    
    if (adj[row][col-1] == 1 && col-1 >= 0)
        DFS(adj, n, row, col-1, arr, cnt);
    if (adj[row][col+1] == 1 && col+1 <= n-1)
        DFS(adj, n, row, col+1, arr, cnt);
    if (adj[row-1][col] == 1 && row-1 >= 0)
        DFS(adj, n, row-1, col, arr, cnt);
    if (adj[row+1][col] == 1 && row+1 <= n-1)
        DFS(adj, n, row+1, col, arr, cnt);
    
    return ;
}

void bubble_sort(int *arr, int n)
{
    int temp;
    int i, j;
    
    for (i=0;i<n-1;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int adj[25][25];
    int arr[25] = {0};
    int i, j;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (adj[i][j] == 1)
            {
                DFS(adj, n, i, j, arr, cnt);
                //printf("\n");
                cnt++;
            }
        }
    }
    
    printf("%d\n", cnt);
    
    bubble_sort(arr, cnt);
    
    for (i=0;i<cnt;i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}*/

// BFS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Queue
{
	int front, rear;
	int x[626], y[626];
}Queue;

void BFS(int adj[][26], int n, int start_x, int start_y, int num)
{
	Queue que;

	int x, y;
	int next_x, next_y;
	int dir_x[4] = { 1, -1, 0, 0 };
	int dir_y[4] = { 0, 0, 1, -1 };

	int i, j;

	que.front = que.rear = -1;

	que.x[++que.rear] = start_x;
	que.y[que.rear] = start_y;

	adj[start_x][start_y] = num;

	while (que.front < que.rear)
	{
		x = que.x[++que.front];
		y = que.y[que.front];

		for (i = 0; i < 4; i++)
		{
			next_x = x + dir_x[i];
			next_y = y + dir_y[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && adj[next_x][next_y] == 1)
			{
				que.x[++que.rear] = next_x;
				que.y[que.rear] = next_y;

				adj[next_x][next_y] = /*adj[x][y] + 1*/num;
			}
		}
	}
}

int main()
{
	int n;
	
	int adj[26][26] = { 0, };
	int visited[26] = { 0, };

	int i, j, k;

	int num = 2;

	int cnt[625] = { 0, };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%1d", &adj[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (adj[i][j] == 1)
			{
				BFS(adj, n, i, j, num);
				num++;
			}
		}
	}

	printf("%d", num - 2);

	for (k = 2; k < num; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (adj[i][j] == k)
				{
					cnt[k]++;
				}
			}
		}
	}

	int temp;

	for (i = 0; i < num-1; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (cnt[i] > cnt[j])
			{
				temp = cnt[i];
				cnt[i] = cnt[j];
				cnt[j] = temp;
			}
		}
	}

	for (i = 2; i < num; i++)
	{
		printf("\n%d", cnt[i]);
	}

	return 0;
}
