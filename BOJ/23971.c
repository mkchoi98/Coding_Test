#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
	int h, w, n, m;

	scanf("%d %d %d %d", &h, &w, &n, &m);

	int answer;

	answer = (int)(ceil((double)h / (double)(n + 1))) * (int)(ceil((double)w / (double)(m+1)));

	printf("%d", answer);

	return 0;
}
