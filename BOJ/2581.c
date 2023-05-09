#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int sum = 0, min = -1;
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = n; i <= m; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0) break;
		}

		if (j == i)
		{
			if (sum == 0) min = i;
			
			sum += i;
		}
	}

	if (min == -1)
	{
		printf("-1");

		return 0;
	}

	printf("%d\n%d", sum, min);

	return 0;
}
