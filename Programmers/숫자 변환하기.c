#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear;
    int num[1000001];
}Queue;

void BFS(int discovered[], int x, int y, int n)
{
    Queue que;
    int num;
    
    que.front = que.rear = -1;
    
    discovered[x] = 1;
    que.num[++que.rear] = x;
    
    while (que.front < que.rear)
    {
        num = que.num[++que.front];
        
        if (num == y) return;
        
        //if (num == 1000) return;
        
        if (num+n <= 1000000 && discovered[num+n] == 0)
        {
            que.num[++que.rear] = num+n;
            discovered[num+n] = discovered[num] + 1;
        }
        
        if (num*2 <= 1000000 && discovered[num*2] == 0)
        {
            que.num[++que.rear] = num*2;
            discovered[num*2] = discovered[num] + 1;
        }
        
        if (num*3 <= 1000000 && discovered[num*3] == 0)
        {
            que.num[++que.rear] = num*3;
            discovered[num*3] = discovered[num] + 1;
        }
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    int discovered[1000001] = {0,};
    
    BFS(discovered, x, y, n);
    
    answer = discovered[y]-1;
    
    return answer;
}
