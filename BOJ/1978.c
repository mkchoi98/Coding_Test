#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, num;
	int i, j;
	int cnt = 0;
	int flag = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);

		flag = 1;
		for (j = 2; j < num; j++)
		{
			if (num % j == 0)
				flag = 0;
		}
		if (num != 1 && flag == 1)
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}
