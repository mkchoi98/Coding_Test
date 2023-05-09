#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, *num;
	int i, j;
	int min, max;

	scanf("%d", &n);

	num = (int*)malloc(sizeof(int) * n);

	scanf("%d", &num[0]);

	min = max = num[0];

	for (i = 1; i < n; i++)
	{
		scanf("%d", &num[i]);

		if (max < num[i])
			max = num[i];
		if (min > num[i])
			min = num[i];
	}

	printf("%d %d", min, max);

	free(num);

	return 0;
}
