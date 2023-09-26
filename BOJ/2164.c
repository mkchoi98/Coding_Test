//
//  main.c
//  2164
//
//  Created by 최민경 on 2023/09/25.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    int i;
    int arr[1000000];
    
    for (i=0;i<n;i++)
    {
        arr[i] = i+1;
    }
    
    int front, rear;
    
    front = 0;
    rear = n-1;
    
    while (1)
    {
        front = (front + 1) % n;
        
        if (front == rear) break;
        
        rear = (rear + 1) % n;
        
        arr[rear] = arr[front];
        
        front = (front + 1) % n;
        
        if (front == rear) break;
    }
    
    printf("%d", arr[front]);
    
    return 0;
}
