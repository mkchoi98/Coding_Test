//
//  main.cpp
//  2023
//
//  Created by 최민경 on 2024/01/17.
//

#include <iostream>
#include <vector>

using namespace std;

static int N;

bool isPrime(int num)
{
    for (int i=2;i<=num/2;i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

void DFS(int num, int index)
{
    if (index == N)
    {
        if (isPrime(num))
        {
            cout << num << '\n';
        }
        
        return ;
    }
    
    for (int i=1;i<10;i++)
    {
        if (isPrime(num*10 + i))
        {
            DFS(num*10 + i, index+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
    
    return 0;
}
