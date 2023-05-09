#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[100];
	int n;
	int i;

	scanf("%d", &n);

	if (n == 0 || n == 1)
	{
		printf("%d", n);

		return 0;
	}

	arr[0] = 0;
	arr[1] = 1;

	for (i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%d", arr[--i]);

	return 0;
}
