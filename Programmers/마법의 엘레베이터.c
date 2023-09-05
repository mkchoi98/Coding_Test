#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct Queue
{
    int x[100000000];
    int front, rear;
}Queue;

void BFS(int discovered[], int start)
{
    Queue que;
    long cur_x, next_x;
    int i;
    
    que.front = que.rear = -1;
    
    que.x[++que.rear] = start;
    
    discovered[start] = 1;
    
    while (que.front < que.rear)
    {
        cur_x = que.x[++que.front];

        if (cur_x == 0) break;
        
        for (i=0;i<=8;i++)
        {
            next_x = cur_x + pow(10, i);
            
            if (next_x <= 100000000 && discovered[next_x] == 0)
            {
                que.x[++que.rear] = next_x;
                discovered[next_x] = discovered[cur_x] + 1;
            }
            
        }
        
        for (i=0;i<=8;i++)
        {
            next_x = cur_x - pow(10, i);
            
            if (next_x >= 0 && discovered[next_x] == 0)
            {
                que.x[++que.rear] = next_x;
                discovered[next_x] = discovered[cur_x] + 1;
            }
            
        }
    }
}

int solution(int storey) {
    int answer = 0;
    int discovered[100000001] = {0, };
    
    BFS(discovered, storey);

    answer = discovered[0] - 1;
    
    return answer;
}
