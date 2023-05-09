#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, k;
	int i;
	int cnt = 0;

	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0) cnt++;

		if (cnt == k)
		{
			printf("%d", i);
			break;
		}
	}

	if (i == n + 1)
		printf("0");

	return 0;
}
