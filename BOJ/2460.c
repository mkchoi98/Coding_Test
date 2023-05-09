#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int sum = 0;
	int max = 0;
	int i;

	for (i = 0; i < 10; i++)
	{
		scanf("%d %d", &n, &m);

		sum += m - n;

		if (max < sum)
			max = sum;
	}

	printf("%d", max);

	return 0;
}
