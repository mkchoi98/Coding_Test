#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, t;
	int binary[1000];
	int i, j, k;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);

		j = 0;
		while (n != 0)
		{
			binary[j++] = n % 2;
			n /= 2;
		}

		for (k = 0; k < j; k++)
		{
			if (binary[k] == 1)
				printf("%d ", k);
		}
	}


	return 0;
}
