#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int i, j, k = 0;
	int arr[1000];
	int sum = 0;
	int stop_flag = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= i; j++)
		{
			arr[k++] = i;

			if (k == m+1)
			{
				stop_flag = 1;
				break;
			}
		}

		if (stop_flag)
			break;
	}

	for (i = n-1; i < m; i++) sum += arr[i];

	printf("%d", sum);

	return 0;
}
