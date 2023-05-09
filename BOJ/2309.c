#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[9];
	int i, j;
	int sum = 0;
	int temp;
	int flag = 0;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	
	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (sum - (arr[i] + arr[j]) == 100)
			{
				arr[i] = arr[j] = 0;
				flag = 1;

				break;
			}
		}
		if (flag == 1) break;
	}

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 2; i < 9; i++) printf("%d\n", arr[i]);

	return 0;
}
