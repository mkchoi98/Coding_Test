#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, min;
	int answer1, answer2;
	int i;

	scanf("%d %d", &n, &m);

	if (n > m) min = n;
	else min = m;

	for (i = 1; i <= min; i++)
	{
		if (n % i == 0 && m % i == 0)
			answer1 = i;
	}

	answer2 = (n / answer1) * (m / answer1) * answer1;

	printf("%d\n%d", answer1, answer2);

	return 0;
}
