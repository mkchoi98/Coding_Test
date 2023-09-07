//
//  main.c
//  1931
//
//  Created by 최민경 on 2023/09/07.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct meeting
{
    int start;
    int end;
}meeting;

int compare(const meeting *a, const meeting *b)
{
    if (a->end > b->end)
        return 1;
    else if (a->end < b->end)
        return -1;
    else
    {
        if (a->start > b->start)
            return 1;
        else return -1;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    meeting arr[100000];
    int i;
    
    for (i=0;i<n;i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }
    
    qsort(arr, n, sizeof(meeting), compare);

    int index = 0;
    int cnt = 1;
    
    for (i=1;i<n;i++)
    {
        if (arr[index].end <= arr[i].start)
        {
            index = i;
            cnt++;
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}
