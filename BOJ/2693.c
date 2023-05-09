#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	int arr[10];
	int i, j, k;
	int temp;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &arr[j]);
		}

		for (j = 0; j < 9; j++)
		{
			for (k = j + 1; k < 10; k++)
			{
				if (arr[j] < arr[k])
				{
					temp = arr[k];
					arr[k] = arr[j];
					arr[j] = temp;
				}
			}
		}

		printf("%d\n", arr[2]);
	}

	return 0;
}
