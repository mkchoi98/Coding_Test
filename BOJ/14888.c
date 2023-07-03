#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void DFS(int* arr, int cnt, long long* min, long long* max, int* op, int result, int n)
{
    if (cnt == n)
    {
        //printf("%d\n", result);
        if (*min > result) *min = result;
        if (*max < result) *max = result;
    }

    if (op[0] != 0)
    {
        op[0]--;
        DFS(arr, (cnt)+1, min, max, op, result + arr[cnt+1], n);
        op[0]++;
    }

    if (op[1] != 0)
    {
        op[1]--;
        DFS(arr, (cnt) + 1, min, max, op, result - arr[cnt+1], n);
        op[1]++;
    }

    if (op[2] != 0)
    {
        op[2]--;
        DFS(arr, (cnt) + 1, min, max, op, result * arr[cnt+1], n);
        op[2]++;
    }

    if (op[3] != 0)
    {
        op[3]--;

        if (result < 0)
        {
            result *= -1;
            DFS(arr, cnt+1, min, max, op, (result / arr[cnt+1]) * (-1), n);
        }

        else DFS(arr, cnt+1, min, max, op, result / arr[cnt+1], n);

        op[3]++;
    }
}

int main(int argc, const char* argv[]) {
    int n;
    int arr[100];
    int op[4];
    int i;
    long long min = 1000000000, max = -1000000000;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 4; i++)
        scanf("%d", &op[i]);

    DFS(arr, 0, &min, &max, op, arr[0], n-1);

    printf("%lld\n%lld", max, min);

    return 0;
}
