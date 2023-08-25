#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n;
	long k;
	long coin[10];

	int i;

	int max_index;
	long cnt = 0;

	scanf("%d %ld", &n, &k);

	max_index = n-1;

	for (i = 0; i < n; i++)
	{
		scanf("%ld", &coin[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (coin[i] > k)
		{
			max_index = i - 1;

			break;
		}
	}

	while (k != 0)
	{
		k = k - coin[max_index];
		
		cnt++;

		for (i = 0; i <= max_index; i++)
		{
			if (coin[i] > k)
			{
				max_index = i - 1;
				break;
			}
		}
	}

	printf("%ld", cnt);

	return 0;
}
