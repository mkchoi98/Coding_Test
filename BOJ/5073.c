//
//  main.c
//  5073
//
//  Created by 최민경 on 2023/08/31.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else return 0;
}

int main(int argc, const char * argv[]) {
    int arr[3];
    
    while (1)
    {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        
        if (arr[0] ==0 && arr[1] == 0 && arr[2] == 0) break;
        
        qsort(arr, 3, sizeof(int), compare);
        
        if (arr[0] + arr[1] <= arr[2])
        {
            printf("Invalid\n");
        }
        else if (arr[0] == arr[1] && arr[1] == arr[2])
        {
            printf("Equilateral\n");
        }
        else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2])
        {
            printf("Isosceles\n");
        }
        else
        {
            printf("Scalene\n");
        }
    }
    
    return 0;
}

